#include "../imports/imports.func_declaration.h"


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

void Tag_create_module_file(Tag *self,CTextStack *final_text_path,const char *prev_module,const char *project_short_cut,const char *src){
    CTextStack *final_text = stack.newStack_string_empty();

    if(prev_module != NULL){
            stack.format(final_text,"#include \"imports.%s.h\"\n",prev_module);
    }


    stack.format(final_text,"#ifndef %s_%s\n",project_short_cut,self->name);
    stack.format(final_text,"#define %s_%s\n",project_short_cut,self->name);
    for(int i = 0; i < self->itens->size;i++){
        char *current_file = self->itens->strings[i];
        CTextStack *relative_path = make_relative_path(final_text_path->rendered_text,src,current_file);
        stack.format(final_text,"#include \"%t\"\n",relative_path);
        stack.free(relative_path);
    }
    stack.format(final_text,"#endif\n");


    dtw.write_string_file_content(final_text_path->rendered_text,final_text->rendered_text);
    stack.free(final_text);
}

void Tag_replace_import_in_files(
    Tag *self,
    const char *import_module_dir,
    const char *import_module_file
){
    for(int i = 0; i < self->itens->size;i++){

        char *current_file_path = self->itens->strings[i];

        CTextStack *relative_path = make_relative_path(current_file_path,import_module_dir,import_module_file);
        CTextStack *text_to_insert = stack.newStack_string("\n//silver_chain_scope_start\n");
        stack.text(text_to_insert,"//mannaged by silver chain\n");
        stack.format(text_to_insert,"#include \"%t\"\n",relative_path);
        stack.text(text_to_insert,"\n//silver_chain_scope_end\n");
        stack.free(relative_path);

        char *file_content = dtw.load_string_file_content(current_file_path);
        CTextStack *file_content_stack = stack.newStack_string(current_file_path);
        int start_scope_index = stack.index_of(file_content_stack,"\n//silver_chain_scope_start\n");
        if(start_scope_index == -1){
            //means its not implemented
            stack.self_insert_at(file_content_stack,0,text_to_insert->rendered_text);
            stack.text(file_content_stack,file_content);
            dtw.write_string_file_content(current_file_path,file_content_stack->rendered_text);
            stack.free(file_content_stack);
            stack.free(text_to_insert);
            continue;
        }

        int end_scope_index = stack.index_of(file_content_stack,"\n//siver_chain_scope_end\n");
        if(end_scope_index == -1){
            printf(" file %s not provides  end scope\n",current_file_path);
            exit(1);
        }
        //replace the content
        stack.self_substr(file_content_stack,start_scope_index,end_scope_index);
        stack.self_insert_at(file_content_stack,start_scope_index,text_to_insert->rendered_text);
        dtw.write_string_file_content(current_file_path,file_content_stack->rendered_text);
        stack.free(file_content_stack);
        stack.free(text_to_insert);
    }
}


void Tag_implement(
    Tag *self,
    const char *module_dir,
    const char *project_short_cut,
    const char *prev,
    const char *src
){

    CTextStack *import_module_file_path = stack.newStack_string_empty();
    stack.format(import_module_file_path,"%s/imports.%s.h",module_dir,self->name);

    Tag_create_module_file(self,import_module_file_path,prev,project_short_cut,src);
    Tag_replace_import_in_files(self,module_dir,import_module_file_path->rendered_text);
    stack.free(import_module_file_path);
}


void Tag_free(Tag *self){
    free(self->name);
    DtwStringArray_free(self->itens);
    free(self);
}
