
#include "../imports/imports.globals.h"




Tag *newTag(const char *name,int priority);


void Tag_add_file(Tag *self,const char *file);


void Tag_implement(
    Tag *self,
    const char *point,
    const char *project_short_cut,
    const char *prev,
    const char *src
);


void Tag_free(Tag *self);
