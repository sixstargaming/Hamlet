#ifndef PLAYER_H
#define PLAYER_H

#include "Root.h"
#include <KinematicBody2D.hpp>

namespace godot {
	class Actor : public KinematicBody2D {
		GODOT_CLASS(Actor, KinematicBody2D)

	public:

		bool isAnimate = true; // Flag as false for inanimate objects like rocks and trees

		bool isAlive;
		float fHealth;

		static void _register_methods();
		void _init();
		void _process(float delta);
		void _ready();

		Actor();
		Actor(bool a);
		~Actor();

		bool ReduceHealth(float fDamage); // Returns true if Actor is still alive after calculating damage
		bool CheckLivingStatus();
	};
}

#endif