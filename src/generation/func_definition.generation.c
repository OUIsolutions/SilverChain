#include "../imports/imports.func_declaration.h"


void generate_code(const char *src,const char *import_dir,DtwStringArray * tags){

    DtwStringArray *src_listage = dtw.list_files_recursively(src,true);
    TagList *itens = newTagList();
    for(int i = 0; i <src_listage->size;i++){
        char *current = src_listage->strings[i];
        DtwPath *path = dtw.path.newPath(current);
        char *name = dtw.path.get_name(path);
        if(is_a_tag(tags,name)){

        }
    }
}
