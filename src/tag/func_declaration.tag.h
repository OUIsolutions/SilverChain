
#include "../imports/imports.globals.h"


Tag *newTag(const char *name);

void Tag_add_file(Tag *self,const char *file);

void Tag_implement(Tag *self,const char *point,const char *prev);
