#include "Monster.h"

using namespace godot;

void Monster::_register_methods() {
	register_method((char*)"_ready", &Monster::_ready);
	register_method((char*)"_process", &Monster::_process);
}

void Monster::_init() { return; }

Monster::Monster() { fHealth = 100.00f; }
Monster::~Monster() { return; }

void Monster::_process(float delta) {
	if (fHealth <= 0) Die();
	ProcessAI();
}

void Monster::ProcessAI() {
	motion = Vector2(0, 0);

	if (!isStunned) {
		srand(time(NULL));
		int iMov = rand() % 3;
		switch (iMov)
		{
		case UP:
			motion = Vector2(SPEED, 0);
			break;
		case DOWN:
			motion = Vector2(-SPEED, 0);
			break;
		case LEFT:
			motion = Vector2(0, -300);
			break;
		case RIGHT:
			motion = Vector2(0, SPEED);
			break;
		default:
			Godot::print("Non-valid AI Movement");
			break;
		}
	}
	move_and_slide(motion);
}