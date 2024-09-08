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
void Tag_create_module_file(Tag *self,CTextStack *final_text_path,const char *prev,const char *project_short_cut){
    CTextStack *final_text = stack.newStack_string_empty();

    if(prev != NULL){
            stack.format(final_text,"#include \"imports.%s.h\"\n",prev);
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
    const char *point,
    const char *project_short_cut,
    const char *prev,
    const char *src
){
    for(int i = 0; i < self->itens->size;i++){

        char *current_file_path = self->itens->strings[i];
        CTextStack *text_to_insert = create_module_import_content(current_file_path,point,src);

        char *file_content = dtw.load_string_file_content(current_file_path);
        CTextStack *file_content_stack = stack.newStack_string(file_content);
        int start_scope_index = stack.index_of(file_content_stack,"//siver_chain_scope_start");
        if(start_scope_index == -1){
            //means its not implemented
            stack.text(file_content_stack,text_to_insert->rendered_text);
            dtw.write_string_file_content(current_file_path,file_content_stack->rendered_text);
            stack.free(file_content_stack);
            stack.free(text_to_insert);
            continue;
        }
        
        int end_scope_index = stack.index_of(file_content_stack,"//siver_chain_scope_end");
        if(end_scope_index == -1){
            printf(" file %s not provided scope\n",current_file_path);
            exit(1);
        }
        //replace the content
        stack.substr(file_content_stack,start_scope_index,end_scope_index);
        stack.insert_at(file_content_stack,start_scope_index,text_to_insert->rendered_text);
        dtw.write_string_file_content(current_file_path,file_content_stack->rendered_text);
        stack.free(file_content_stack);
        stack.free(text_to_insert);
    }

}
void Tag_implement(
    Tag *self,
    const char *point,
    const char *project_short_cut,
    const char *prev,
    const char *src
){

    CTextStack *final_text_path = stack.newStack_string_empty();
    stack.format(final_text_path,"%s/imports.%s.h",point,self->name);

    Tag_create_module_file(self,final_text_path,prev,project_short_cut);
    Tag_replace_import_in_files(self,point,project_short_cut,prev,src);
    stack.free(final_text_path);
}   


void Tag_free(Tag *self){
    free(self->name);
    DtwStringArray_free(self->itens);
    free(self);
}
