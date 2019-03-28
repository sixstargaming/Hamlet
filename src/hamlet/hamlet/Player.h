#include "Root.h"
#include "Actor.h"
#include <KinematicBody2D.hpp>
#include <Camera2D.hpp>
#include <Input.hpp>

namespace godot {
	class Player : public Actor {
		GODOT_CLASS(Player, Actor)
	private:
		Vector2 motion;
	public:
		Camera2D* pCamera;
		const int SPEED = 300;

		static void _register_methods();
		void _init();
		void _process(float delta);
		void _ready();

		void UpdateMotionFromInput();
		Player();
		~Player();
	};
}