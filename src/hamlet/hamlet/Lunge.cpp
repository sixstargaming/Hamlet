#include "Lunge.h"

using namespace godot;

void Lunge::_init() { return; }

Lunge::Lunge() { throw "Requires a pointer to parent"; }

Lunge::Lunge(Player* argp) {
	iCooldown = 100;
	actor = argp;
	return;
}

Lunge::~Lunge() { return; }

void Lunge::Execute() {
	Vector2 motion = Vector2(distance, 0);
	actor->move_and_slide(motion);
	actor->StartAbilityCooldown(iCooldown);
	return;
}