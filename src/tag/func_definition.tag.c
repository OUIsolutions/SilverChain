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

void Tag_implement(
    Tag *self,
    const char *point,
    const char *project_short_cut,
    const char *prev,
    const char *src
){   
    CTextStack *final_text = stack.newStack_string_empty();

    CTextStack *final_text_path = stack.newStack_string_empty();
    stack.format(final_text_path,"%s/imports.%s.h",point,self->name);

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
}


void Tag_free(Tag *self){
    free(self->name);
    DtwStringArray_free(self->itens);
    free(self);
}