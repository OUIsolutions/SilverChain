
#include "../imports/imports.globals.h"


Tag *newTag(const char *name,int priority);


void Tag_add_file(Tag *self,const char *file);

void Tag_create_module_file(
    Tag *self,
    CTextStack *final_text_path,
    const char *prev_module,
    const char *project_short_cut
);


void Tag_replace_import_in_files(
    Tag *self,
    const char *import_module_file
);

void Tag_implement(
    Tag *self,
    const char *module_dir,
    const char *project_short_cut,
    const char *prev
);



void Tag_free(Tag *self);
