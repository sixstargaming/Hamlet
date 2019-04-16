/* Include all calsses on this file */
#include "Root.h"
#include "Actor.h"
#include "Player.h"
#include "Monster.h"
#include "Weapon.h"
#include "Ability.h"
#include "Backstep.h"

// #include <gdnative_api_struct.gen.h>  // Not needed?
//#include <core/Godot.hpp> // Remove once included in root file?

// DO NOT use namesapce godot here

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
	godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
	godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
	godot::Godot::nativescript_init(handle);

	/* Register all classes here with godot::register_class<godot::CLASSNAME>(); */
	godot::register_class<godot::Actor>();
	godot::register_class<godot::Player>();
	godot::register_class<godot::Monster>();
	godot::register_class<godot::Weapon>();
	godot::register_class<godot::Ability>();
	godot::register_class<godot::Backstep>();
}