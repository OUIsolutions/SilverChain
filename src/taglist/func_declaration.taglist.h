
#include "../imports/imports.globals.h"

TagList *newTagList();

Tag * TagList_find_tag_element(TagList *self,const char *tag);


void TagList_add_item(TagList *self, const char *tag,const char *path);
