#ifndef WEAPON_H
#define WEAPON_H

#include "Root.h"
#include "Actor.h"
#include "Player.h"
#include <Area2D.hpp>
#include <AnimationPlayer.hpp>

namespace godot {
	class Weapon : public Area2D {
		GODOT_CLASS(Weapon, Area2D)
	private:
		// NULL
	public:
		//AnimationPlayer *pAnimationPlayer;

		enum STATES { IDLE, ATTACK };
		bool current_state = IDLE;

		float fDamage = 50.00f;
		float fStunTime = 0.5f;

		static void _register_methods();

		void _ready();
		void Attack();
		void _change_state(bool new_sate);
		void _physics_process(float delta);
		void _on_AnimationPlayer_animation_finished(String name);
		void _init();

		bool IsOwner(Node *actor);

		Weapon();
		~Weapon();
	};
}

#endif // !WEAPON_H
