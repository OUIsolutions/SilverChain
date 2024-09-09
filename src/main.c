
#include "imports/imports.func_definition.h"

int main(){

    dtw = newDtwNamespace();
    stack = newCTextStackModule();

    DtwStringArray *tags = newDtwStringArray();
    dtw.string_array.append(tags,"dependencies");
    dtw.string_array.append(tags,"types");
    dtw.string_array.append(tags,"globals");
    dtw.string_array.append(tags,"func_declaration");
    dtw.string_array.append(tags,"func_definition");
    dtw.string_array.append(tags,"final");

    generate_code("src","src/imports","silverchain",tags);

}
