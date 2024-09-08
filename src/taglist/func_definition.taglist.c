
#include "../imports/imports.func_declaration.h"


TagList *newTagList(){
    TagList *self = malloc(sizeof(TagList));
    *self = (TagList){0};
    self->tags = (Tag**)malloc(0);
    return self;
}
Tag * TagList_find_tag_element(TagList *self,const char *tag){
    for(int i = 0; i < self->size;i++){
        Tag *current = self->tags[i];
        if(strcmp(current->name, tag) == 0){
            return current;
        }
    }
    return NULL;
}

void TagList_add_item(TagList *self, const char *tag,const char *path){
    Tag *tag_to_add = TagList_find_tag_element(self,tag);
    if(tag_to_add == NULL){
        tag_to_add = newTag(tag);
        self->tags = (Tag**)realloc(self->tags, (self->size +1) * sizeof(Tag**));
        self->tags[self->size] = tag_to_add;
        self->size+=1;
    }


}
