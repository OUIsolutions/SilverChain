
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.func_declaration.h"
//silver_chain_scope_end



int  get_tag_index(DtwStringArray *tags,const char *name){

    for(int i = 0; i < tags->size; i++){

        char *current_tag = tags->strings[i];
        if(dtw_starts_with(name,current_tag)){
            return i;
        }

    }
    return -1;
}


int count_path_levels(const char *path){
    UniversalGarbage *garbage = newUniversalGarbage();

    CTextStack *path_stack = stack.newStack_string(path);
    UniversalGarbage_add(garbage,stack.free,path_stack);
    stack.self_replace(path_stack,"//","/");

    int count = 0;
    for(int i = 0; i < path_stack->size; i++){
        if(path_stack->rendered_text[i] == '/'){
            count++;
        }
    }
    UniversalGarbage_free(garbage);
    return count;
}


CTextStack * make_relative_path(
    const char *current_file,
    const char *dest_file
){

    UniversalGarbage *garbage = newUniversalGarbage();
    CTextStack *formmated_current_path = stack.newStack_string(current_file);
    UniversalGarbage_add(garbage,stack.free,formmated_current_path);

    stack.self_replace(formmated_current_path,"//","/");
    CTextStack *formmated_dest_path = stack.newStack_string(dest_file);
    UniversalGarbage_add(garbage,stack.free,formmated_dest_path);
    stack.self_replace(formmated_dest_path,"//","/");

    int lower_size = 0;
    if(formmated_current_path->size > formmated_dest_path->size){
        lower_size = formmated_dest_path->size;
    }else{
        lower_size = formmated_current_path->size;
    }

    int count_to_substract = 1;
    while (count_to_substract < lower_size){
        if(formmated_current_path->rendered_text[count_to_substract] != formmated_dest_path->rendered_text[count_to_substract]){

            if(formmated_current_path->rendered_text[count_to_substract-1] != '/' || formmated_dest_path->rendered_text[count_to_substract-1] != '/'){
                count_to_substract =0;
            }
            break;
        }
        count_to_substract+=1;
    }

    if(count_to_substract > 0){
        stack.self_pop(formmated_current_path,0,count_to_substract-1);
        stack.self_pop(formmated_dest_path,0,count_to_substract-1);
    }
    int dirs_to_add = count_path_levels(formmated_current_path->rendered_text);
    CTextStack *final_path = stack.newStack_string_empty();

    for(int i = 0; i < dirs_to_add; i++){
        stack.text(final_path,"../");
    }
    stack.text(final_path,formmated_dest_path->rendered_text);
    //printf("current = %s\n",formmated_current_path->rendered_text);
    //printf("formmated =%s\n",formmated_dest_path->rendered_text);

    UniversalGarbage_free(garbage);
    return final_path;






}
