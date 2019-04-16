#include "Backstep.h"

using namespace godot;

void Backstep::_init() { return; }

Backstep::Backstep() { throw "Requires a pointer to parent"; }

Backstep::Backstep(Player* argp) {
	iCooldown = 10;
	actor = argp;
	return;
}

Backstep::~Backstep() { return; }

void Backstep::Execute() {
	if (!isDisabled) {
		Vector2 motion = Vector2(distance, 0);
		actor->move_and_slide(motion);
		StartCooldown();
	}
	return;
}