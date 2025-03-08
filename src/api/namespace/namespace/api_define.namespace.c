
SilverChainNamespace newSilverChainNamespace(){
    SilverChainNamespace self = {0};
    self.error = newSilverChainErrorNamespace();
    self.generator = newSilverChainGeneratorNamespace();
    self.string_array = newSilverChainStringArrayNamespace();
    self.remove_start_end_from_folder = SilverCHain_remove_start_end_from_folder;
    return  self;
}
