#include "Root.h"
#include "Actor.h"
#include <KinematicBody2D.hpp>
#include <Camera2D.hpp>
#include <Input.hpp>

namespace godot {
	class Monster : public Actor {
		GODOT_CLASS(Monster, Actor)
	private:
		// Vector2 motion;
	public:

		//static void _register_methods();
		//void _init();
		//void _process(float delta);
		//void _ready();

		Monster();
		~Monster();
	};
}