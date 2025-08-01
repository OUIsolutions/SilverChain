


void private_SilverChain_write_element_if_not_equal(const char *path,const char *content){
    char *old = dtw_load_string_file_content(path);
    if(old){
        if(strcmp(old, content) !=0){
            dtw_write_string_file_content(path,content);
        }
        free(old);
        return;
    }
    dtw_write_string_file_content(path,content);


}
