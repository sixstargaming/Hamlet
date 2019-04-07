#ifndef PLAYER_H
#define PLAYER_H

#include "Root.h"
#include "Actor.h"
#include "Weapon.h"
#include <KinematicBody2D.hpp>
#include <Camera2D.hpp>
#include <Input.hpp>


namespace godot {
	class Weapon;

	class Player : public Actor {
		GODOT_CLASS(Player, Actor)
	private:
		Vector2 motion;
	public:
		Camera2D* pCamera;
		const int SPEED = 300;

		static Weapon* pWeapon;

		static void _register_methods();
		void _init();
		void _process(float delta);
		void _ready();
		//void _on_Area2D_body_entered(PhysicsBody2D *OffendingObject);

		void UpdateFromInput();
		Player();
		~Player();
	};
}

#endif // !PLAYER_H