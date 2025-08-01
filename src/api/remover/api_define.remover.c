//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end



void SilverCHain_remove_start_end_from_folder(const char *src){
    bool CONCAT_PATH = true;
    DtwStringArray *files = NULL;
    
    // Check if src is a file or directory
    if(dtw_entity_type(src) == DTW_FILE_TYPE){
        // If it's a file, create a string array with just this file
        files = newDtwStringArray();
        DtwStringArray_append(files, src);
    } else {
        // If it's a directory, list files recursively
        files = dtw_list_files_recursively(src, CONCAT_PATH);
    }
    
    if(files == NULL){
        return;
    }
    
    int end_scope_size = (int)strlen(SILVER_CHAIN_END_SCOPE);

    for(int i = 0; i < files->size; i++){
        char *content = dtw_load_string_file_content(files->strings[i]);
        if(content == NULL){
            continue;
        }

        CTextStack *formatted = newCTextStack_string(content);
        if(CTextStack_index_of(formatted,"silver_chain_internal_unchanged") != -1){
            // If the file is marked as not changed, skip it
            CTextStack_free(formatted);
            free(content);
            continue;
        }

        bool has_changes = true;
        
        // Keep removing SilverChain scopes until no more are found
        while(has_changes){
            has_changes = false;
            
            int start_scope_index = CTextStack_index_of(formatted, SILVER_CHAIN_START_SCOPE);
            if(start_scope_index == SILVER_CHAIN_NOT_FOUND){
                break;
            }

            int end_scope_index = CTextStack_index_of(formatted, SILVER_CHAIN_END_SCOPE);
            if(end_scope_index == -1){
                break;
            }

            // Remove the scope content
            CTextStack_self_pop(formatted, start_scope_index, end_scope_index + end_scope_size);
            has_changes = true;
        }
        
        // Write the cleaned content back to file
        dtw_write_string_file_content(files->strings[i], formatted->rendered_text);

        CTextStack_free(formatted);
        free(content);
    }
    
    DtwStringArray_free(files);
}