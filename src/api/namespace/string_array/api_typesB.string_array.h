//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.api_types.h"
//silver_chain_scope_end


typedef struct SilverChainStringArrayNamespace{
    SilverChainStringArray * (*create)();
    void (*append)(SilverChainStringArray *self,const char *value);
    void (*free)(SilverChainStringArray *self);

} SilverChainStringArrayNamespace;
