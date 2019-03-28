#ifndef PLAYER_H
#define PLAYER_H

#include "Root.h"
#include <KinematicBody2D.hpp>

namespace godot {
	class Actor : public KinematicBody2D {
		GODOT_CLASS(Actor, KinematicBody2D)

	public:

		static void _register_methods();
		void _init();
		void _process(float delta);
		void _ready();

		Actor();
		~Actor();
	};
}

#endif