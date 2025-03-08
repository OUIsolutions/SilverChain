

SilverChainStringArrayNamespace newSilverChainStringArrayNamespace(){
    SilverChainStringArrayNamespace self = {0};
    self.create  = newSilverChainStringArray;
    self.append = SilverChainStringArray_append;
    self.free =SilverChainStringArray_free;
    return  self;
}
