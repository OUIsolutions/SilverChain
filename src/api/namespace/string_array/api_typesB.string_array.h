

typedef struct SilverChainStringArrayNamespace{
    SilverChainStringArray * (*create)();
    void (*append)(SilverChainStringArray *self,const char *value);
    void (*free)(SilverChainStringArray *self);

} SilverChainStringArrayNamespace;
