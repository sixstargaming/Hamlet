#include "Backstep.h"

using namespace godot;

void Backstep::_init() { return; }

Backstep::Backstep() { throw "Requires a pointer to parent"; }

Backstep::Backstep(Player* argp) {
	iCooldown = 10;
	pPlayer = argp;
	//pPlayer->add_child(this); // This should be done on Player.cpp
	return;
}

Backstep::~Backstep() { return; }

void Backstep::Execute() {
	if (!isDisabled) {
		Vector2 motion = Vector2(distance, 0);
		pPlayer->move_and_slide(motion);
		StartCooldown();
	}
	return;
}