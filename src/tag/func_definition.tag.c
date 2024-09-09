a
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.func_declaration.h"
//silver_chain_scope_end

Tag *newTag(const char *name,int priority){
    Tag *self = (Tag*)malloc(sizeof(Tag));
    *self = (Tag){0};
    self->name = strdup(name);
    self->priority = priority;
    self->itens = newDtwStringArray();
    return self;
}

void Tag_add_file(Tag *self,const char *file){
    DtwStringArray_append(self->itens,file);
}

void Tag_create_module_file(
    Tag *self,
    CTextStack *final_text_path,
    const char *prev_module,
    const char *project_short_cut
){
    CTextStack *final_text = stack.newStack_string_empty();

    if(prev_module != NULL){
            stack.format(final_text,"#include \"%s.%s.h\"\n",IMPORT_NAME, prev_module);
    }


    stack.format(final_text,"#ifndef %s_%s\n",project_short_cut,self->name);
    stack.format(final_text,"#define %s_%s\n",project_short_cut,self->name);
    for(int i = 0; i < self->itens->size;i++){
        char *current_file = self->itens->strings[i];
        CTextStack *relative_path = make_relative_path(final_text_path->rendered_text,current_file);
        stack.format(final_text,"#include \"%t\"\n",relative_path);
        stack.free(relative_path);
    }
    stack.format(final_text,"#endif\n");


    dtw.write_string_file_content(final_text_path->rendered_text,final_text->rendered_text);
    stack.free(final_text);
}

void Tag_replace_import_in_files(
    Tag *self,
    const char *module_dir,
    const char *prev
){
    if(prev == NULL){
        return;
    }
    CTextStack *module_path = stack.newStack_string_empty();
    stack.format(module_path,"%s/imports.%s.h",module_dir,prev);
    int end_scope_size = (int)strlen(SILVER_CHAIN_END_SCOPE);
    for(int i = 0; i < self->itens->size;i++){

        char *current_file_path = self->itens->strings[i];
       CTextStack *relative_path = make_relative_path(current_file_path,module_path->rendered_text);
        CTextStack *text_to_insert = stack.newStack_string(SILVER_CHAIN_START_SCOPE);
        stack.format(text_to_insert,"%s",MANAGED_SYSTEM);
        stack.format(text_to_insert,"#include \"%t\"\n",relative_path);
        stack.text(text_to_insert,SILVER_CHAIN_END_SCOPE);
        stack.free(relative_path);

        char *file_content = dtw.load_string_file_content(current_file_path);
        CTextStack *file_content_stack = stack.newStack_string(file_content);
        int start_scope_index = stack.index_of(file_content_stack,SILVER_CHAIN_START_SCOPE);
        if(start_scope_index == -1){
            //means its not implemented
            stack.self_insert_at(file_content_stack,0,text_to_insert->rendered_text);
            dtw.write_string_file_content(current_file_path,file_content_stack->rendered_text);
            stack.free(file_content_stack);
            stack.free(text_to_insert);
            continue;
        }

        int end_scope_index = stack.index_of(file_content_stack,SILVER_CHAIN_END_SCOPE);
        if(end_scope_index == -1){
            printf(FILE_NOT_PROVIDED_ERROR,current_file_path);
           continue;
        }
        //replace the content
        stack.self_pop(file_content_stack,start_scope_index,end_scope_index+end_scope_size-1);
        stack.self_insert_at(file_content_stack,start_scope_index,text_to_insert->rendered_text);
        dtw.write_string_file_content(current_file_path,file_content_stack->rendered_text);
        stack.free(file_content_stack);
        stack.free(text_to_insert);
    }
    stack.free(module_path);
}


void Tag_implement(
    Tag *self,
    const char *module_dir,
    const char *project_short_cut,
    const char *prev
){

    CTextStack *import_module_file_path = stack.newStack_string_empty();
    stack.format(import_module_file_path,"%s/%s.%s.h",module_dir,IMPORT_NAME,self->name);

    Tag_create_module_file(self,import_module_file_path,prev,project_short_cut);
    Tag_replace_import_in_files(self,module_dir,prev);
    stack.free(import_module_file_path);
}


void Tag_free(Tag *self){
    free(self->name);
    DtwStringArray_free(self->itens);
    free(self);
}
