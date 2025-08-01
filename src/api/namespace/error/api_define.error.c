

SilverChainErrorNamespace newSilverChainErrorNamespace(){
    SilverChainErrorNamespace self ={0};
    self.free = SilverChainError_free;
    return self;
}
