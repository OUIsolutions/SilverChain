#include "../imports/imports.func_declaration.h"


double get_tag_number(int position, const char *current_tag,const char* name){

    int current_tag_size = strlen(current_tag);
    CTextStack *number_text = stack.newStack_string(name);
    stack.self_substr(number_text,0,current_tag_size);

    CTextStack *final_number = stack.newStack_string_empty();
    stack.format(final_number,"%d.%t",position,number_text);
    double final_number_double = stack.parse_to_double(final_number);

    stack.free(final_number);
    stack.free(number_text);
    return final_number_double;

}

double get_tag_priority(DtwStringArray *tags,const char *name){


    for(int i = 0; i < tags->size; i++){

        char *current_tag = tags->strings[i];
        if(dtw_starts_with(name,current_tag)){
            return get_tag_number(i,current_tag,name);
        }

    }
    return -1;
}
