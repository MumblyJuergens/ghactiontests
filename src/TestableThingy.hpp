#pragma once

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/wrapped.hpp>
#include <godot_cpp/variant/string.hpp>

class TestableThingy : public godot::RefCounted {
    GDCLASS(TestableThingy, godot::RefCounted)

    godot::String gimme_string() { return "Woozle Wuzzle"; }

    protected:
        static void _bind_methods() {
            godot::ClassDB::bind_method(godot::D_METHOD("gimme_string"), &TestableThingy::gimme_string);
        }
};