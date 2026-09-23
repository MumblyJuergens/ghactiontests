#include "TestableThingy.hpp"

#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

void initialize_module(godot::ModuleInitializationLevel level)
{
    if (level != godot::MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }

    GDREGISTER_CLASS(TestableThingy);
}

void uninitialize_module(godot::ModuleInitializationLevel level)
{
    if (level != godot::MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
}

extern "C" GDExtensionBool GDE_EXPORT library_init(GDExtensionInterfaceGetProcAddress get_proc,
                                                          const GDExtensionClassLibraryPtr library,
                                                          GDExtensionInitialization *initialization)
{
    godot::GDExtensionBinding::InitObject init_obj{get_proc, library, initialization};

    init_obj.register_initializer(initialize_module);
    init_obj.register_terminator(uninitialize_module);
    init_obj.set_minimum_library_initialization_level(godot::MODULE_INITIALIZATION_LEVEL_SCENE);

    return init_obj.init();
}