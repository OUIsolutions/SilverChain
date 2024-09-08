#include "../dependencies/dependencies.all.h"

#ifndef TAG
#define TAG

typedef  struct{
    char *name;
    DtwStringArray *itens;
}Tag;

Tag *newTag(const char *name);

void Tag_implement(Tag *self,const char *point,const char *prev);



#endif
