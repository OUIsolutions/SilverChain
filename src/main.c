
#include "imports/imports.func_definition.h"

int main(){

    dtw = newDtwNamespace();
    stack = newCTextStackModule();
    /*
    CTextStack *make_relative_path_test = make_relative_path2(
        "src",
        "src/algo/func_definition.algo.c",
        "src/imports",
        "src/imports/imports.func_definition.h"
    );
    */
    
   /*
    CTextStack *make_relative_path_test = make_relative_path2(
        "src",
        "src/algo/func_definition.algo.c",
        "imports",
        "imports/imports.func_definition.h"
    );

    */
   
    CTextStack *make_relative_path_test = make_relative_path2(
        "src/imports/imports.func_definition.h",
        "src/algo/func_definition.algo.c"
    );
    

    printf("%s\n",make_relative_path_test->rendered_text);
    stack.free(make_relative_path_test);
    return 0;

    DtwStringArray *tags = newDtwStringArray();
    dtw.string_array.append(tags,"dependencies");
    dtw.string_array.append(tags,"types");
    dtw.string_array.append(tags,"globals");
    dtw.string_array.append(tags,"func_declaration");
    dtw.string_array.append(tags,"func_definition");
    dtw.string_array.append(tags,"final");

    generate_code("src","src/imports","silverchain",tags);

}
