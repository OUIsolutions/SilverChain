

SilverChainStringArray * newSilverChainStringArray(){
    return newDtwStringArray();
}
void SilverChainStringArray_append(SilverChainStringArray *self,const char *value){
    DtwStringArray_append(self,value);
}

void SilverChainStringArray_free(SilverChainStringArray *self){
    DtwStringArray_free(self);
}
