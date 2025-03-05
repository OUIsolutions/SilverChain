
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end

SilverChainStringArray * newSilverChainStringArray(){
    return newDtwStringArray();
}
void SilverChainStringArray_append(SilverChainStringArray *self,const char *value){
    DtwStringArray_append(self,value);
}

void SilverChainStringArray_free(SilverChainStringArray *self){
    DtwStringArray_free(self);
}
