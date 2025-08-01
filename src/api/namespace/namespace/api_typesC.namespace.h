

typedef struct SilverChainNamespace{
    SilverChainGeneratorNamespace generator;
    SilverChainErrorNamespace error;
    SilverChainStringArrayNamespace string_array;
    void(*remove_start_end_from_folder)(const char *src);
}SilverChainNamespace;
