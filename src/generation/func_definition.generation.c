
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.func_declaration.h"
//silver_chain_scope_end


void generate_code(const char *src,const char *import_dir,const char *project_short_cut,DtwStringArray * tags){

    dtw.remove_any(import_dir);

    DtwStringArray *src_listage = dtw.list_files_recursively(src,true);
    TagList *itens = newTagList();
    for(int i = 0; i <src_listage->size;i++){
        char *current = src_listage->strings[i];
        DtwPath *path = dtw.path.newPath(current);

        char *name = dtw.path.get_name(path);
        CTextStack *name_stack = stack.newStack_string(name);
        int first_dot = stack.index_of_char(name_stack,'.');
        stack.self_substr(name_stack,0,first_dot);

        int tag_index = get_tag_index(tags,name_stack->rendered_text);
        if(tag_index != -1){
            TagList_add_item(itens,name_stack->rendered_text,current,tag_index);
        }
        dtw.path.free(path);
        stack.free(name_stack);
    }

    TagList_implement(itens,import_dir,project_short_cut);
    TagList_free(itens);
}
