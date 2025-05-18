//silver_chain_scope_start
//DONT MODIFY THIS COMMENT
//this import is computationally generated
//mannaged by SilverChain: https://github.com/OUIsolutions/SilverChain
#include "../../../imports/imports.api_declare.h"
//silver_chain_scope_end


SilverChainGeneratorNamespace newSilverChainGeneratorNamespace(){
    SilverChainGeneratorNamespace self = {0};
    self.generate_code = SilverChain_generate_code;
    self.generate_code_in_watch_mode = SilverChain_generate_code_in_watch_mode;
    return self;
}
