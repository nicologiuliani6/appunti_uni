#include <dlfcn.h>
#include <iostream>
#include <string>

// Tipo della funzione plugin_main
typedef int (*plugin_main_t)(int, char**);

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <libreria.so> [argomenti...]\n";
        return 1;
    }

    const char* lib_path = argv[1];

    // Carica la libreria
    void* handle = dlopen(lib_path, RTLD_NOW);
    if (!handle) {
        std::cerr << "Errore dlopen: " << dlerror() << "\n";
        return 1;
    }

    // Trova la funzione plugin_main
    dlerror(); // pulisce errori precedenti
    plugin_main_t plugin_main = (plugin_main_t)dlsym(handle, "plugin_main");
    const char* err = dlerror();
    if (err != nullptr) {
        std::cerr << "Errore dlsym: " << err << "\n";
        dlclose(handle);
        return 1;
    }

    // Prepara gli argomenti (passa tutti gli argomenti dopo il nome .so)
    int new_argc = argc - 1;
    char** new_argv = argv + 1;

    // Esegui la funzione plugin_main()
    int result = plugin_main(new_argc, new_argv);

    // Chiude la libreria
    dlclose(handle);

    return result;
}

