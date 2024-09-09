
#include "../imports/imports.globals.h"

TagList *newTagList();

Tag * TagList_find_tag_element(TagList *self,const char *tag);


int TagList_ordanate_tag_by_priority(const void *tag1,const void *tag2);

void TagList_add_item(TagList *self, const char *tag,const char *path,int priority);

void TagList_implement(TagList *self,const char *point,const char *project_short_cut);

void TagList_free(TagList *self);
