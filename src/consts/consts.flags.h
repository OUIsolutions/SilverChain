
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.dependencies.h"
//silver_chain_scope_end

#define SRC_FLAG "s | src | source"
#define IMPORT_FLAG "i | i mportdir"
#define TAG_FLAG "t | tags"
#define PROJECT_SHORT_CUT_FLAG "p | project_short_cut"
#define IMPLEMENT_MAIN_FLAG "m | implement_main"
#define MAIN_NAME_FLAG "n | main_name"
#define MAIN_PATH_FLAG "p | main_path"

#define HELP_FLAG "h | help"

#define SRC_DESCRIPTION "The folder of the project(required)"
#define IMPORT_DESCRIPTION "The directory to be used to save imports (default: imports)"
#define TAG_DESCRIPTION "The tags to be used (required)"
#define PROJECT_SHORT_CUT_DESCRIPTION "The project short cut to be used in #ifndef props (default: silverchain)"
#define IMPLEMENT_MAIN_DESCRIPTION "true or false to implement the main function (default: false)"
#define MAIN_NAME_DESCRIPTION "The name of the main function (default: main.c or main.cpp)"
#define MAIN_PATH_DESCRIPTION "The path of the main function (default: not set)"
#define HELP_DESCRIPTION "Show the help message"

#define HELP_MESSAGE "Usage: silverchain [options]\nOptions:"\
"\n  -h, --help\t\t\t"HELP_DESCRIPTION\
"\n  -s, --src\t\t\t"SRC_DESCRIPTION\
"\n  -i, --importdir\t\t"IMPORT_DESCRIPTION\
"\n  -t, --tags\t\t\t"TAG_DESCRIPTION\
"\n  -p, --project_short_cut\t"PROJECT_SHORT_CUT_DESCRIPTION\
"\n  -m, --implement_main\t\t"IMPLEMENT_MAIN_DESCRIPTION\
"\n  -n, --main_name\t\t"MAIN_NAME_DESCRIPTION\
"\n  -p, --main_path\t\t"MAIN_PATH_DESCRIPTION\
"\n"

