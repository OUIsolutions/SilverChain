#include "../imports/imports.func_declaration.h"


bool is_a_tag(DtwStringArray *tags,const char *file){
    for(int i = 0; i < tags->size; i++){
        if(dtw_starts_with(file,tags->strings[i])){
            return true;
        }
    }
    return false;
}
