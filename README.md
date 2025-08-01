# 🔗 SilverChain

<div align="center">

![GitHub release (latest by date)](https://img.shields.io/github/v/release/OUIsolutions/SilverChain?style=for-the-badge&color=brightgreen)
![GitHub](https://img.shields.io/github/license/OUIsolutions/SilverChain?style=for-the-badge&color=blue)
![GitHub Repo stars](https://img.shields.io/github/stars/OUIsolutions/SilverChain?style=for-the-badge&color=yellow)
![C](https://img.shields.io/badge/language-C-blue?style=for-the-badge&logo=c)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Windows%20%7C%20macOS-lightgrey?style=for-the-badge)

**A Universal Import Model for C that makes organizing your code SUPER EASY!** ✨

*No more messy includes! Organize your C project like a pro!* 🚀

[🎬 Watch the Video Explanation](https://www.youtube.com/watch?v=mU4QbZATKfo)

</div>

---

## 🎯 What is SilverChain? (Super Simple Explanation!)

**Imagine your C project is like a messy room with clothes scattered everywhere.** 🏠

**SilverChain** is like a magic organizer that:
1. **Sorts your clothes by type** (shirts, pants, socks) 📦
2. **Puts them in the right drawers** (dependencies, functions, types) 🗂️
3. **Makes everything easy to find** ✨

### 📚 In Programming Terms:
If you have a C project with scattered files like:
- `math_functions.c`, `string_helpers.c`, `file_io.c`
- `constants.h`, `types.h`, `globals.h`  
- Headers and implementations all mixed up 😵‍💫

**SilverChain organizes ALL of these by TAGS in a logical order!** 🎉

### 🤔 Why is this AMAZING for beginners?

#### ✅ **SUPER EASY to Understand Your Project**
- **Before**: "Where is this function defined? Which file has the constants?"
- **After**: "Everything is organized by logical tags - dependencies first, then types, then functions!" 🚀

#### ✅ **NO More Include Hell**
- **Before**: Endless `#include` statements and dependency nightmares 😰
- **After**: SilverChain handles all includes automatically in the right order! ✨

#### ✅ **Perfect for Learning**
- See your project structure clearly
- Understand how different parts connect
- No mysterious "where does this come from?" moments

#### ✅ **Builds Like Magic**
- Automatic dependency resolution
- No complex build systems needed
- Just organize by tags and compile!



---

## 📥 Download & Installation (Choose Your Adventure!)

> **🚨 Total Beginner?** Start with the "🎮 Super Easy Download" section below!

### 🎮 Super Easy Download (No Compilation Needed!)

**Just want to use it RIGHT NOW?** Download the ready-to-run version for your computer:

<div align="center">

| 🖥️ **Your Computer** | 📁 **Download This** | 🏃‍♂️ **How to Use** |
|---------------------|---------------------|---------------------|
| 🐧 **Linux** | [SilverChain.out](https://github.com/OUIsolutions/SilverChain/releases/download/0.2.1/SilverChain.out) | Download → Make executable → Run! |
| 🪟 **Windows (64-bit)** | [SilverChain64.exe](https://github.com/OUIsolutions/SilverChain/releases/download/0.2.1/SilverChain64.exe) | Download → Double-click → Use! |
| 🪟 **Windows (32-bit)** | [SilverChaini32.exe](https://github.com/OUIsolutions/SilverChain/releases/download/0.2.1/SilverChaini32.exe) | Download → Double-click → Use! |

</div>

### 🚀 Super Quick Installation (Copy & Paste!)

**🐧 Linux Users (Easiest Way Ever!):**
```bash
# Just copy and paste this into your terminal!
curl -L https://github.com/OUIsolutions/SilverChain/releases/download/0.2.1/SilverChain.out -o SilverChain
chmod +x SilverChain

# Now you can use it like this:
./SilverChain --help
```

**🐧 Ubuntu/Debian Users (Even Easier!):**
```bash
# Download the package
wget https://github.com/OUIsolutions/SilverChain/releases/download/0.2.1/SilverChain.deb

# Install it (you'll need to enter your password)
sudo dpkg -i SilverChain.deb

# Now it's installed system-wide! Use it anywhere:
SilverChain --help
```

### 🧑‍💻 Advanced Downloads (For Developers)

| 📁 **File** | 🎯 **Best For** | 📝 **Description** |
|-------------|-----------------|-------------------|
| [⚡️ SilverChain.c](https://github.com/OUIsolutions/SilverChain/releases/download/0.2.1/SilverChain.c) | Developers who want to compile | Complete source code |
| [📚 SilverChainApiOne.h](https://github.com/OUIsolutions/SilverChain/releases/download/0.2.1/SilverChainApiOne.h) | Use in your C programs | Full API library |
| [📦 SilverChainApiNoDependenciesIncluded.h](https://github.com/OUIsolutions/SilverChain/releases/download/0.2.1/SilverChainApiNoDependenciesIncluded.h) | Minimal integration | Lightweight version |
| [📦 SilverChain.rpm](https://github.com/OUIsolutions/SilverChain/releases/download/0.2.1/SilverChain.rpm) | Fedora/RHEL/CentOS | RPM package |


---

## 🏃‍♂️ Quick Start Guide (For Total Beginners!)

> **Don't panic!** This is easier than making instant noodles! 🍜

### 🎬 Step 1: Your First SilverChain Project (The Basics)

Let's start with the simplest possible example:

```bash
# This is THE most basic command you'll ever need!
./SilverChain --src my_project --tags dependencies functions
```

**🤔 What just happened?**
- `--src my_project` → "Hey SilverChain, look at this folder!"
- `--tags dependencies functions` → "Organize by dependencies first, then functions!"

**That's it!** SilverChain will:
1. 🔍 Look at your `my_project` folder
2. 🏷️ Find all files with `dependencies.` in their names
3. 🏷️ Then find all files with `functions.` in their names  
4. 📁 Create an organized `imports` folder with everything!

### 🎬 Step 2: Real-World Example (Let's Do This Together!)

**Imagine you have these files in your project:**

```
my_awesome_calculator/
├── src/
│   ├── dependencies.headers.h     ← All your #includes
│   ├── types.calculator.h         ← Data types  
│   ├── functions.math.h           ← Function declarations
│   ├── functions.math.c           ← Function implementations
│   ├── functions.display.h        ← Display function declarations
│   ├── functions.display.c        ← Display implementations
│   └── main.c                     ← Your main program
```

**🧑‍💻 What's in each file:**

**dependencies.headers.h:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
```

**types.calculator.h:**
```c
#ifndef CALCULATOR_TYPES_H
#define CALCULATOR_TYPES_H
typedef struct {
    double result;
    char operation;
} Calculator;
#endif
```

**functions.math.h:**
```c
#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H
double add(double a, double b);
double subtract(double a, double b);
#endif
```

**functions.math.c:**
```c
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
```

**🚀 Now, let's organize everything with SilverChain:**

```bash
./SilverChain --src my_awesome_calculator/src --tags dependencies types functions
```

**🎉 BOOM! Now you have an organized `imports` folder that looks like:**

```
imports/
├── imports.dependencies.h    ← All dependencies in one place
├── imports.types.h          ← All types organized  
├── imports.functions.h      ← All function declarations
├── imports.functions.c      ← All function implementations
└── ...other organized files
```

**🌟 And in your main.c, you just need:**
```c
#include "imports/imports.dependencies.h"
#include "imports/imports.types.h" 
#include "imports/imports.functions.h"

int main() {
    printf("My calculator is organized!\n");
    double result = add(5.0, 3.0);
    printf("5 + 3 = %.2f\n", result);
    return 0;
}
```

### 🎬 Step 3: Test It Yourself!

**Create a simple test project:**

1. **Create the folder structure:**
```bash
mkdir test_silverchain
mkdir test_silverchain/src
cd test_silverchain
```

2. **Create dependencies.system.h:**
```c
#include <stdio.h>
#include <string.h>
```

3. **Create types.person.h:**
```c
#ifndef PERSON_TYPES_H
#define PERSON_TYPES_H
typedef struct {
    char name[50];
    int age;
} Person;
#endif
```

4. **Create functions.person.h:**
```c
#ifndef PERSON_FUNCTIONS_H
#define PERSON_FUNCTIONS_H
void print_person(Person p);
Person create_person(const char* name, int age);
#endif
```

5. **Create functions.person.c:**
```c
void print_person(Person p) {
    printf("Name: %s, Age: %d\n", p.name, p.age);
}

Person create_person(const char* name, int age) {
    Person p;
    strcpy(p.name, name);
    p.age = age;
    return p;
}
```

6. **Run SilverChain:**
```bash
../SilverChain --src src --tags dependencies types functions
```

7. **Create main.c and compile:**
```c
#include "imports/imports.dependencies.h"
#include "imports/imports.types.h"
#include "imports/imports.functions.h"

int main() {
    Person john = create_person("John", 25);
    print_person(john);
    return 0;
}
```

```bash
gcc main.c imports/imports.functions.c -o test_program
./test_program
```

**Expected output:**
```
Name: John, Age: 25
```

**🎉 Congratulations! You just used SilverChain successfully!**

---

## ⚙️ Command-Line Options (All the Cool Features!)

> **🎯 Beginner Tip:** Start with just `--src` and `--tags`. Learn the other options later!

### 🔥 Essential Options (You NEED These!)

| 🏷️ **Flag** | 📝 **What It Does** | 🚨 **Required?** | 💡 **Example** |
|-------------|-------------------|------------------|----------------|
| `--src` or `-s` | The project folder to organize | ✅ **YES** | `--src my_project` |
| `--tags` or `-t` | Tags to organize by (in order!) | ✅ **YES** | `--tags dependencies types functions` |

### 🎛️ Useful Options (Make Your Life Easier!)

| 🏷️ **Flag** | 📝 **What It Does** | 🔧 **Default** | 💡 **When to Use** |
|-------------|-------------------|-----------------|-------------------|
| `--importdir` or `-i` | Where to save organized files | `imports` | `--importdir organized_code` |
| `--project_short_cut` or `-p` | Project name for #ifndef guards | `silverchain` | `--project_short_cut MYCALC` |
| `--implement_main` or `-m` | Create a main.c file | `false` | `--implement_main true` |
| `--main_name` or `-n` | Name of the main file | `main.c` | `--main_name calculator.c` |
| `--main_path` | Path to the main file (if not in src) | `null` | `--main_path src/cli/main.c` |

### 🚀 Advanced Options (For Power Users!)

| 🏷️ **Flag** | 📝 **What It Does** | 🎯 **Perfect For** | 💡 **Example** |
|-------------|-------------------|-------------------|----------------|
| `--watch` or `-w` | Auto-rebuild when files change | Development mode | `--watch` |
| `--sleep_time` or `-s` | Time between watch checks | Controlling watch speed | `--sleep_time 2` |
| `--remove` or `-r` | Delete the imports folder | Cleaning up | `--remove` |
| `--help` or `-h` | Show help message | When you're lost! | `--help` |
| `--version` or `-v` | Show SilverChain version | Check your version | `--version` |

### 🌟 Real-World Examples:

#### 🥇 **Beginner Example:**
```bash
# Just organize everything - simple!
./SilverChain --src src --tags dependencies types functions
```

#### 🥈 **Intermediate Example:**
```bash
# Custom import directory and project name
./SilverChain --src my_project --tags deps consts types funcs \
  --importdir organized --project_short_cut MYPROJ
```

#### 🥉 **Advanced Example:**
```bash
# Watch mode with custom main file
./SilverChain --src src --tags dependencies consts types globals func_declaration func_definition \
  --implement_main true --main_name my_app.c --watch
```

### 🚨 Common Beginner Mistakes (And How to Avoid Them!)

❌ **DON'T DO THIS:**
```bash
# Missing required flags - this will fail!
./SilverChain my_project
```

✅ **DO THIS INSTEAD:**
```bash
# Always include both --src and --tags
./SilverChain --src my_project --tags dependencies functions
```

❌ **DON'T DO THIS:**
```bash
# Wrong tag order - dependencies should be first!
./SilverChain --src src --tags functions dependencies
```

✅ **DO THIS INSTEAD:**
```bash
# Dependencies first, then other tags in logical order
./SilverChain --src src --tags dependencies types functions
```

---

## 🧠 How SilverChain Works (The Magic Explained!)

> **🎯 Simple Version:** SilverChain looks at your files, sorts them by tags, and creates organized imports! ✨

### 🏷️ The Tag System (Super Important!)

**Think of tags like organizing your closet:**
- **`dependencies`** → All your socks go in the sock drawer first 🧦
- **`types`** → Then your shirts go in the shirt drawer 👕  
- **`functions`** → Finally your pants go in the pants drawer 👖

**SilverChain works the same way!**

#### 📋 Tag Processing Order:
```bash
./SilverChain --src src --tags dependencies consts types globals func_declaration func_definition
```

1. **`dependencies`** → Files starting with `dependencies.` get processed first
2. **`consts`** → Then files starting with `consts.`
3. **`types`** → Then files starting with `types.`
4. **`globals`** → Then files starting with `globals.`
5. **`func_declaration`** → Then files starting with `func_declaration.`
6. **`func_definition`** → Finally files starting with `func_definition.`

### 🔍 File Naming Convention (The Secret!)

**SilverChain looks for files that start with your tag name:**

| 🏷️ **Tag** | 📁 **Files It Will Find** | 💡 **Examples** |
|-----------|--------------------------|-----------------|
| `dependencies` | `dependencies.*` | `dependencies.system.h`, `dependencies.libs.h` |
| `types` | `types.*` | `types.person.h`, `types.calculator.h` |
| `functions` | `functions.*` | `functions.math.c`, `functions.io.h` |

### 👀 Tag Vision (How Tags See Each Other)

**This is the COOLEST part!** Each tag can "see" all the previous tags:

```bash
./SilverChain --src src --tags dependencies types functions
```

- **`dependencies`** can see: Nothing (it's first)
- **`types`** can see: `dependencies` ✅
- **`functions`** can see: `dependencies` + `types` ✅

**🌟 This means:** Your function files can use types and dependencies automatically!

### 🎬 Step-by-Step Example:

**Your project:**
```
src/
├── dependencies.system.h      ← #include <stdio.h>, <stdlib.h>
├── types.math.h              ← typedef struct Calculator {...}
├── functions.add.h           ← double add(double a, double b);
├── functions.add.c           ← Implementation using Calculator type
└── main.c
```

**When you run:**
```bash
./SilverChain --src src --tags dependencies types functions
```

**SilverChain creates:**
```
imports/
├── imports.dependencies.h    ← All your #includes
├── imports.types.h          ← All your typedefs (can see dependencies)
├── imports.functions.h      ← All declarations (can see dependencies + types)
└── imports.functions.c      ← All implementations (can see everything)
```

**🎉 Result:** Perfect organization with automatic dependency resolution!

---

## 🧑‍💻 API Usage (For Programmers Who Want to Integrate!)

> **🎯 Beginner Note:** This section is for people who want to use SilverChain inside their own C programs. If you just want to use the command-line tool, you can skip this section!

### 🚀 Quick Setup (Get the API Library)

**Download the API header file:**
```bash
# Get the complete API (easiest way)
curl -L https://github.com/OUIsolutions/SilverChain/releases/download/0.2.1/SilverChainApiOne.h -o SilverChainApiOne.h
```

### 🎬 Simple Example (Your First API Program!)

**Create a file called `my_silverchain.c`:**

```c
#include <stdio.h>
#include "SilverChainApiOne.h"

int main() {
    // Initialize SilverChain
    SilverChainNamespace sc = newSilverChainNamespace();
    
    // Create tag list (like command-line tags)
    SilverChainStringArray *tags = sc.string_array.create();
    sc.string_array.append(tags, "dependencies");
    sc.string_array.append(tags, "types"); 
    sc.string_array.append(tags, "functions");
    
    // Settings (you can change these!)
    const char *src = "src";                    // Source folder
    const char *import_dir = "imports";         // Where to save organized files
    const char *project_short_cut = "MYPROJ";  // Project prefix
    bool implement_main = false;                // Don't create main.c
    const char *main_name = "main.c";          // Main file name (if needed)
    const char *main_path = NULL;              // Auto-detect main file
    
    // Do the magic! ✨
    SilverChainError *possible_error = sc.generator.generate_code(
        src,
        import_dir, 
        project_short_cut,
        tags,
        implement_main,
        main_name,
        main_path
    );
    
    // Check if it worked
    if(possible_error) {
        printf("❌ Oops! Something went wrong: %s\n", possible_error->error_msg);
        sc.error.free(possible_error);
        sc.string_array.free(tags);
        return 1;
    }
    
    printf("✅ Success! Your project has been organized!\n");
    printf("📁 Check the '%s' folder for organized files.\n", import_dir);
    
    // Clean up memory (important!)
    sc.string_array.free(tags);
    
    printf("🎉 All done!\n");
    return 0;
}
```

**Compile and run:**
```bash
gcc my_silverchain.c -o my_silverchain
./my_silverchain
```

### 🎛️ Advanced Example (With Custom Build Integration!)

**Perfect for build systems and automation:**

```c
#include <stdio.h>
#include "SilverChainApiOne.h"

int main() {
    SilverChainNamespace sc = newSilverChainNamespace();
    
    // Create a comprehensive tag list for a complete project
    SilverChainStringArray *tags = sc.string_array.create();
    sc.string_array.append(tags, "api_dependencies");  // External dependencies
    sc.string_array.append(tags, "api_consts");        // Constants
    sc.string_array.append(tags, "api_types");         // Data types
    sc.string_array.append(tags, "api_declare");       // Function declarations
    sc.string_array.append(tags, "api_define");        // Function definitions
    sc.string_array.append(tags, "cli_dependencies");  // CLI dependencies
    sc.string_array.append(tags, "cli_consts");        // CLI constants
    sc.string_array.append(tags, "cli_globals");       // Global variables
    sc.string_array.append(tags, "cli_declare");       // CLI declarations
    sc.string_array.append(tags, "cli_define");        // CLI definitions
    
    // Advanced settings
    const char *src = "src";
    const char *import_dir = "src/imports";
    const char *project_short_cut = "SilverChain"; 
    bool implement_main = true;                    // Create main.c
    const char *main_name = "main.c";
    const char *main_path = "src/cli/main.c";     // Specific main file
    
    printf("🚀 Starting SilverChain organization...\n");
    printf("📂 Source: %s\n", src);
    printf("📁 Output: %s\n", import_dir);
    
    SilverChainError *possible_error = sc.generator.generate_code(
        src,
        import_dir,
        project_short_cut,
        tags,
        implement_main,
        main_name,
        main_path
    );
    
    if(possible_error) {
        printf("❌ Error during organization: %s\n", possible_error->error_msg);
        sc.error.free(possible_error);
        sc.string_array.free(tags);
        return 1;
    }
    
    printf("✅ Project organized successfully!\n");
    printf("📋 Tags processed: %d\n", sc.string_array.size(tags));
    printf("🎯 Main file: %s (implemented: %s)\n", main_name, implement_main ? "YES" : "NO");
    
    // Clean up
    sc.string_array.free(tags);
    
    printf("🎉 Build system integration complete!\n");
    return 0;
}
```

### 🚨 Important Notes for Beginners:

1. **Always check for errors!** The API can fail if folders don't exist or files are malformed.
2. **Don't forget to free memory!** Always call `sc.string_array.free()` and `sc.error.free()` when done.
3. **Start simple!** Use basic tags first, then add more complex organization later.
4. **Test locally!** Make sure your file naming convention matches your tags.

### 💡 Integration Tips:

- **Makefiles:** Call your SilverChain program before compilation
- **Build Scripts:** Integrate into shell scripts for automated builds  
- **IDEs:** Create custom build tasks that run SilverChain first
- **CI/CD:** Add to your pipeline for automatic code organization

---

## 🔨 Building from Scratch (For Advanced Users!)

> **🎯 Beginner Note:** You don't need this section if you just downloaded the ready-made executables above! This is only for people who want to compile SilverChain themselves.

### 📋 Prerequisites (What You Need First)

**You'll need these tools installed:**

1. **🦄 [Darwin](https://github.com/OUIsolutions/Darwin) Build System** (Version 0.020+)
2. **🐳 Docker** OR **🫖 Podman** (for containerized builds)
3. **🐧 Linux Environment** (recommended)

### 🚀 One-Line Darwin Installation (Linux Only!)

```bash
# Install Darwin build system in one command
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.7.0/darwin.out -o darwin.out && sudo chmod +x darwin.out && sudo mv darwin.out /usr/bin/darwin
```

### 📁 Clone and Build

```bash
# 1. Clone the repository
git clone https://github.com/OUIsolutions/SilverChain.git
cd SilverChain

# 2. Build all variants (this will take a while!)
darwin run_blueprint build/ --mode folder amalgamation_build alpine_static_build windowsi32_build windowsi64_build rpm_static_build debian_static_build
```

---

## 🎉 Success Stories & Use Cases

### 🌟 **Perfect For:**
- **🎓 Students**: Organize complex class projects with clear structure
- **🏢 Professional Development**: Maintain large C codebases with ease
- **📚 Library Creation**: Build well-organized, reusable code libraries
- **🚀 Embedded Systems**: Manage firmware projects with clear dependencies
- **🎮 Game Development**: Organize game engines and logic modules

### 💬 **What Users Say:**

> *"SilverChain turned my messy C project into something I could actually understand!"* - CS Student

> *"Finally, a way to organize C code that makes sense. No more include hell!"* - Senior Developer

> *"Perfect for our embedded firmware. Dependencies are crystal clear now."* - Embedded Engineer

---

## 🆘 Need Help? (We've Got You Covered!)

### 🤝 Community Support

- **🐛 Found a Bug?** [Create an Issue](https://github.com/OUIsolutions/SilverChain/issues)
- **💡 Have a Feature Idea?** [Suggest It Here](https://github.com/OUIsolutions/SilverChain/issues)  
- **⭐ Like the Project?** Give us a star on GitHub!

### 📚 Common Questions

**Q: "What's the best tag order for beginners?"**
A: Start with `dependencies types functions` - it works for most projects!

**Q: "Can my files have multiple dots in their names?"**
A: Yes! `dependencies.system.headers.h` will be found by the `dependencies` tag.

**Q: "What if I don't have any dependencies?"**
A: Skip the dependencies tag! Use just `--tags types functions` for simpler projects.

**Q: "Can I use this with C++?"**
A: SilverChain is designed for C, but it might work with simple C++ code. Try it and see!

**Q: "What happens if I have circular dependencies?"**
A: SilverChain's tag system prevents most circular dependencies by processing in order!

---

<div align="center">

## 🌟 **Ready to Organize Your C Code Like a Pro?**

### **[⬇️ Download Now](https://github.com/OUIsolutions/SilverChain/releases/latest) | [⭐ Star on GitHub](https://github.com/OUIsolutions/SilverChain) | [🐛 Report Issues](https://github.com/OUIsolutions/SilverChain/issues)**

**Made with ❤️ by [OUIsolutions](https://github.com/OUIsolutions)**

*Organizing C code, one tag at a time!* ✨

</div>
