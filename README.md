
## SilverChain a Universal Import Model for C

SilverChain is a unified import model for C, it allows you to import modules and use their functions and variables in a more organized and efficient way.


## How to use

firts download the [silverchain.out](https://github.com/OUIsolutions/SilverChain/releases/download/v0.01/silverchain.out) or
[silverchain.exe](https://github.com/OUIsolutions/SilverChain/releases/download/v0.01/silverchain.exe)
file and put it in your project folder, then run the following command:

```bash
./silverchain.out -src <src_folder> -tags <tag1> <tag2> <tag3> ... <tagN>
```
## Build

```bash
gcc src/main.c -Wall -pedantic -o silverchain.out
```

this will generate a folder called "imports" with all the imports and their dependencies, and a main.c file with the main function and the imports.


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

## How it works
basicly it makes a imports dir , giving visualization of the project modules tag after tag, lets pick the self project build comand:


```bash
./silverchain.out -src src -tags dependencies consts types globals func_declaration func_definition
```
the first tag its "dependencies" so all the files that starts with "dependencies." will be imported, after that it will see that the next tag its "consts" so all the files that starts with "consts." will be imported, and so on, the same proccess will ocurry for the types, globals, func_declaration and func_definition tags, but in this case the files need to starts with the same name of the tag but in lowercase
### The Tags Vision
each tag can visualize the all the ancestors tags, for example:

```bash
./silverchain.out -src src -tags dependencies consts types globals func_declaration func_definition
```

in this case the "func_declaration" and "func_definition" tags will see the "dependencies" and "consts" .
