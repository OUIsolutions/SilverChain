
## SilverChain a Universal Import Model for C

SilverChain is a unified import model for C, it allows you to import modules and use their functions and variables in a more organized and efficient way.

[video explanation](https://www.youtube.com/watch?v=mU4QbZATKfo)



## Releases
| item          | plataform |
|-------        |-----------|
| [CAmalgamator.c](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamator.c)| Source  |
| [CAmalgamatorApiOne.h](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamatorApiOne.h)| Source of The Lib  |
| [CAmalgamatorApiNoDependenciesIncluded.h](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamatorApiNoDependenciesIncluded.h)| Lib without dependenies  |
| [CAmalgamator.out](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamator.out)| Linux Binary |
| [CAmalgamator64.exe](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamator64.exe)| Windows 64 Binary |
| [CAmalgamatori32.exe](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamatori32.exe)| Windows i32 Binary |
| [CAmalgamator.rpm](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamator.rpm)| fedora/rehl/centos package |
| [CAmalgamator.deb](https://github.com/OUIsolutions/CAmalgamator/releases/download/0.0.4/CAmalgamator.deb)| debian/ubuntu package |


## Building from Scratch
if you want to build the code from scracth  you need to have [Darwin](https://github.com/OUIsolutions/Darwin) 
installed on versio **0.020** and **Docker** our **Podman** installed on your machine.
After install all dependecies,clone the repo on your machine , than run:
```shel
 darwin run_blueprint build/ --mode folder amalgamation_build alpine_static_build windowsi32_build windowsi64_build rpm_static_build debian_static_build
```



##  Usage
this will generate a folder called "imports" with all the imports and their dependencies, and a main.c file with the main function and the imports.

```bash
./SilverChain.o -src <src_folder> -tags <tag1> <tag2> <tag3> ... <tagN>
```

## Flags

| Flag | Description | Default |
|------|-------------|---------|
| -s, --src | The project folder (required) | - |
| -i, --importdir | The directory to be used for saving imports | imports |
| -t, --tags | The tags to be used (required) | - |
| -p, --project_short_cut | The project shortcut to be used in #ifndef properties | silverchain |
| -m, --implement_main | true or false to implement the main function | false |
| -n, --main_name | The name of the main function | main.c or main.cpp |
| -p, --main_path | The path of the main function | undefined |
| -h, --help | Shows the help message | - |
| -w, --watch | Watch the project files and rebuild if they change | - |
| -s, --sleep_time | The time to sleep between each check (default: 0) | - |

## How it works
basicly it makes a imports dir , giving visualization of the project modules tag after tag, lets pick the self project build comand:


```bash
./silverchain.out -src src -tags dependencies consts types globals func_declaration func_definition
```
the first tag its "dependencies" so all the files that starts with "dependencies." will be imported, after that it will see that the next tag its "consts" so all the files that starts with "consts." will be imported, and so on, the same proccess will ocurry for the types, globals, func_declaration and func_definition tags, but in this case the files need to starts with the same name of the tag but in lowercase
### The Tags Vision
each tag can visualize the all the ancestors tags, for example:

```bash
./SilverChain.o -src src -tags dependencies consts types globals func_declaration func_definition
```

in this case the "func_declaration" and "func_definition" tags will see the "dependencies" and "consts" .

## Api Usage
if you want to integrate silver chain into your build system, you can use it
directly in c.

install **SilverChainApiOne** file by typing:
```shel
curl -L https://github.com/OUIsolutions/SilverChain/releases/download/v0.07/SilverChainApiOne.h -o SilverChainApiOne.h

```

then you can use the api like these:
```c
#include "SilverChainApiOne.h"
SilverChainNamespace sc;

int main(){
    sc = newSilverChainNamespace();

    SilverChainStringArray * tags = sc.string_array.create();
    sc.string_array.append(tags,"api_dependencies");
    sc.string_array.append(tags,"api_const");
    sc.string_array.append(tags,"api_type");
    sc.string_array.append(tags,"api_declare");
    sc.string_array.append(tags,"api_define");
    sc.string_array.append(tags,"cli_dependencies");
    sc.string_array.append(tags,"cli_consts");
    sc.string_array.append(tags,"cli_type");
    sc.string_array.append(tags,"cli_globals");
    sc.string_array.append(tags,"cli_declare");
    sc.string_array.append(tags,"cli_define");

    const char *src = "src";
    const char *import_dir = "src/imports";
    const char *project_short_cut = "SilverChain";
    bool implement_main = true;
    const char *main_name = "main.c";
    // these its not required when you have only one main
    const char *main_path = "src/cli/main.c";
    SilverChainError *possible_error = sc.generator.generate_code(
        src,
        import_dir,
        project_short_cut,
        tags,
        implement_main,
        main_name,
        main_path
    );
    if(possible_error){
        printf("%s\n",possible_error->error_msg);
        sc.error.free(possible_error);
    }
    sc.string_array.free(tags);
}

```
