
#include "../imports/imports.globals.h"

TagList *newTagList();

Tag * TagList_find_tag_element(TagList *self,const char *tag);

void TagList_ordanate_tag_by_priority(void **tag1,void **tag2);

void TagList_add_item(TagList *self, const char *tag,const char *path,double priority);

void TagList_implement(TagList *self,const char *point,const char *project_short_cut);

void TagList_free(TagList *self);
