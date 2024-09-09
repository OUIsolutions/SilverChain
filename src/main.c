
//silver_chain_scope_start
//mannaged by silver chain
#include "imports/imports.func_definition.h"
//silver_chain_scope_end



int main(int argc,char *argv[]){

    dtw = newDtwNamespace();
    stack = newCTextStackModule();
    cli = newCliNamespace();
    CliEntry *entry = newCliEntry(argc,argv);

    CliFlag *src_flag = cli.entry.get_flag(entry,SRC_FLAG,CLI_NOT_CASE_SENSITIVE);

    //verify if exist
    if(src_flag->exist == false){
           printf(SRC_FLAG_NOT_PROVIDED);
           cli.entry.free(entry);
           return 1;
    }

    char *src = cli.flag.get_str(src_flag,0,CLI_CASE_SENSITIVE);
    if(dtw.entity_type(src) != DTW_FOLDER_TYPE){
        printf(SRC_ITS_NOT_A_DIR);
        cli.entry.free(entry);
        return 1;
    }

    CliFlag *imports_flag = cli.entry.get_flag(entry,IMPORT_FLAG,CLI_NOT_CASE_SENSITIVE);


    char *imports = NULL;
    if(imports_flag->exist){
        imports =cli.flag.get_str(imports_flag,0,CLI_CASE_SENSITIVE);
    }
    if(!imports_flag->exist){
        imports  = dtw.concat_path(src,IMPORT_NAME);
    }

    CliFlag *tag_flags = cli.entry.get_flag(entry,TAG_FLAG,CLI_NOT_CASE_SENSITIVE);

    if(!tag_flags->exist){
        printf(TAG_FLAG_NOT_PROVIDED);
        cli.entry.free(entry);
        return 1;
    }


    DtwStringArray *tags = newDtwStringArray();

    for(int i = 0; i < tag_flags->size;i++){
        char *tag = cli.flag.get_str(tag_flags,i,CLI_CASE_SENSITIVE);
        dtw.string_array.append(tags,tag);
    }
    CliFlag *project_short_cut_flag = cli.entry.get_flag(entry,PROJECT_SHORT_CUT_FLAG,CLI_NOT_CASE_SENSITIVE);
    char *project_short_cut = PROJECT_SHORT_CUT_DEFAULT;

    if(project_short_cut_flag->exist){
        project_short_cut = cli.flag.get_str(project_short_cut_flag,0,CLI_CASE_SENSITIVE);
    }


    generate_code(src,imports,project_short_cut,tags,true,NULL,NULL);

}
