#include "../tag/tag.h"

#ifndef TAGLIST
#define TAGLIST

typedef struct{
    Tag *tags;
    int size;
} TagList;

TagList *newTagList();

void TagList_add_item(const char *tag,const char *src_path);

#endif
