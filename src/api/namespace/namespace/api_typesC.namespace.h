//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.api_typesB.h"
//silver_chain_scope_end


typedef struct SilverChainNamespace{
    SilverChainGeneratorNamespace generator;
    SilverChainErrorNamespace error;
    SilverChainStringArrayNamespace string_array;
    void(*remove_start_end_from_folder)(const char *src);
}SilverChainNamespace;
