#ifndef MONSTER_H
#define MONSTER_H

#include "Root.h"
#include "Actor.h"
#include <stdlib.h>
#include <time.h>
#include <KinematicBody2D.hpp>
#include <Camera2D.hpp>
#include <Input.hpp>

namespace godot {
	class Monster : public Actor {
		GODOT_CLASS(Monster, Actor)
	private:
		Vector2 motion;
		int SPEED = 300;
		enum DIRECTON { UP, DOWN, LEFT, RIGHT };
	public:

		static void _register_methods();
		void _init();
		void _process(float delta);
		//void _ready();

		void ProcessAI();

		Monster();
		~Monster();
	};
}

#endif // !MONSTER_H