#include "../imports/imports.globals.h"

CTextStack *create_module_import_content(const char *current_fie ,const char *import_point,const char *module_path);

int  get_tag_index(DtwStringArray *tags,const char *name);

double get_tag_priority(DtwStringArray *tags,const char *name);

int count_path_levels(const char *path);

CTextStack * make_relative_path(
    const char *current_file,
    const char *dest_dir,
    const char *dest_file
);
