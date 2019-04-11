#include "Backstep.h"

using namespace godot;

void Backstep::_init() { return; }

Backstep::Backstep(Actor* actor) {
	iCooldown = 10;
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