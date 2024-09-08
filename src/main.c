
#include "imports/imports.func_definition.h"

int main(){

    dtw = newDtwNamespace();
    stack = newCTextStackModule();

    char *src = "src";
    DtwStringArray *tags = newDtwStringArray();
    DtwStringArray_add_item(tags,"dependencies");
    DtwStringArray_add_item(tags,"types");
    DtwStringArray_add_item(tags,"globals");
    DtwStringArray_add_item(tags,"func_declaration");
    DtwStringArray_add_item(tags,"func_definition");
    DtwStringArray_add_item(tags,"final");

    generate_code("src","imports","silverchain",tags);

}
