#include "../imports/imports.func_declaration.h"



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
    CTextStack *path_stack = stack.newStack_string(path);
    stack.replace(path_stack,"/","");
    int count = 0;
    for(int i = 0; i < path_stack->size; i++){
        if(path_stack->rendered_text[i] == '/'){
            count++;
        }
    }
    stack.free(path_stack);
    return count;
}

CTextStack * make_relative_path(
    const char *current_file,
    const char *dest_dir,
    const char *dest_file
){


    int total_levels = count_path_levels(current_file);
    bool is_in_dest_dir = dtw_starts_with(current_file,dest_dir);
    if(is_in_dest_dir){
        total_levels -= 1;
    }
    CTextStack *final_path = stack.newStack_string_empty();
    for(int i = 0; i < total_levels; i++){
        stack.text(final_path,"../");
    }
    if(is_in_dest_dir){
        CTextStack *formmated_dest = stack.newStack_string(dest_file);
        stack.self_pop(formmated_dest,0,strlen(dest_dir));
        stack.text(final_path,formmated_dest->rendered_text);
        stack.free(formmated_dest);
    }
    
    if(!is_in_dest_dir){
        stack.text(final_path,dest_file);
    }
    return final_path;


}
