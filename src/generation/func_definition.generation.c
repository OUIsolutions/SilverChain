#include "../imports/imports.func_declaration.h"


void generate_code(const char *src,const char *import_dir,DtwStringArray * tags){

    DtwStringArray *src_listage = dtw.list_files_recursively(src,true);
    TagList *itens = newTagList();
    for(int i = 0; i <src_listage->size;i++){
        char *current = src_listage->strings[i];
        DtwPath *path = dtw.path.newPath(current);
        char *name = dtw.path.get_name(path);
        CTextStack *name_stack = stack.newStack_string(name);
        int first_dot = stack.index_of_char(name_stack,'.');
        stack.self_substr(name_stack,0,first_dot);
        double priority = get_tag_priority(tags,name_stack->rendered_text);
        if(priority != -1){
            TagList_add_item(itens,name_stack->rendered_text,current,priority);
        }
    }
}
