#include "../imports/imports.func_declaration.h"


Tag *newTag(const char *name,double priority){
    Tag *self = (Tag*)malloc(sizeof(Tag));
    *self = (Tag){0};
    self->name = strdup(name);
    self->priority = priority;
    self->itens = newDtwStringArray();
}

void Tag_add_file(Tag *self,const char *file){
    DtwStringArray_append(self->itens,file);
}

void Tag_implement(Tag *self,const char *point,const char *project_short_cut,const char *prev){

}


void Tag_free(Tag *self){
    free(self->name);
    DtwStringArray_free(self->itens);
    free(self);
}