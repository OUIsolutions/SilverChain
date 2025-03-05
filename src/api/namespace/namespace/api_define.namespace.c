
//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.api_declare.h"
//silver_chain_scope_end
SilverChainNamespace newSilverChainNamespace(){
    SilverChainNamespace self = {0};
    self.error = newSilverChainErrorNamespace();
    self.generator = newSilverChainGeneratorNamespace();
    self.string_array = newSilverChainStringArrayNamespace();
    return  self;
}
