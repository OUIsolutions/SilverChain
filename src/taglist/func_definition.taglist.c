
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

void TagList_add_item(TagList *self, const char *tag,const char *path,double priority){
    Tag *tag_to_add = TagList_find_tag_element(self,tag);
    if(tag_to_add == NULL){
        tag_to_add = newTag(tag,priority);
        self->tags = (Tag**)realloc(self->tags, (self->size +1) * sizeof(Tag**));
        self->tags[self->size] = tag_to_add;
        self->size+=1;
    }
    Tag_add_file(tag_to_add,path);

}

void TagList_ordanate_tag_by_priority(void **tag1,void **tag2){
    Tag *t1 = (Tag*)*tag1;
    Tag *t2 = (Tag*)*tag2;
    if(t1->priority > t2->priority){
        return 1;
    }else if(t1->priority < t2->priority){
        return -1;
    }
    return 0;
}
void TagList_implement(TagList *self,const char *point,const char *project_short_cut){
 
    qsort(self->tags, self->size, sizeof(Tag*), TagList_ordanate_tag_by_priority);

    for(int i = 1; i < self->size;i++){
        Tag *current = self->tags[i];
        char *prev = self->tags[i-1]->name;
        Tag_implement(current,point,project_short_cut,prev);
    }
}

void TagList_free(TagList *self){
    for(int i = 0; i < self->size;i++){
        Tag *current = self->tags[i];
        free(current);
    }
    free(self->tags);
    free(self);
}