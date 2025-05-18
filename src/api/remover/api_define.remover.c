//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end



void SilverCHain_remove_start_end_from_folder(const char *src){
    bool CONCAT_PATH = true;
    DtwStringArray *files = dtw_list_files_recursively(src,CONCAT_PATH);
        int end_scope_size = (int)strlen(SILVER_CHAIN_END_SCOPE);

    for(int i = 0; i < files->size; i++){
        char *content = dtw_load_string_file_content(files->strings[i]);
        if(content == NULL){
            continue;
        }

        CTextStack *formmated = newCTextStack_string(content);
        int start_scope_index = CTextStack_index_of(formmated,SILVER_CHAIN_START_SCOPE);
        if(start_scope_index == SILVER_CHAIN_NOT_FOUND){
            CTextStack_free(formmated);
            free(content);
            continue;
        }

        int end_scope_index = CTextStack_index_of(formmated,SILVER_CHAIN_END_SCOPE);
        if(end_scope_index == -1){
            CTextStack_free(formmated);
            free(content);
            continue;
        }

        CTextStack_self_pop(formmated,start_scope_index,end_scope_index+end_scope_size);

        dtw_write_string_file_content(files->strings[i],formmated->rendered_text);

        CTextStack_free(formmated);
        free(content);
    }
}