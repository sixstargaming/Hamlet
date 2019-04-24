#ifndef ACTOR_H
#define ACTOR_H

#include "Root.h"
#include <KinematicBody2D.hpp>

namespace godot {
	class Actor : public KinematicBody2D {
		GODOT_CLASS(Actor, KinematicBody2D)

	public:

		bool isAnimate = true; // Flag as false for inanimate objects like rocks and trees
		bool isAlive = true;
		bool isAbilityEnabled = true;
		bool isAbility2Enabled = true;
		bool isStunned = false;

		int iAbilityCountdown = 0;
		int iAbility2Countdown = 0;

		float fHealth;

		static void _register_methods();
		void _init();
		void _process(float delta);
		void _physics_process(float delta);
		void _ready();

		Actor();
		Actor(bool a);
		~Actor();

		bool ReduceHealth(float fDamage, float fStunTime); // Returns true if Actor is still alive after calculating damage
		void Die(); // Kills Actor
		bool CheckLivingStatus();

		// Ability and weapons stuff
		void StartAbilityCooldown(int cooldown);
		void StartAbility2Cooldown(int cooldown);
	};
}

#endif //!ACTOR_H