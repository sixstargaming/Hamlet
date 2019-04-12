#include "Ability.h"

using namespace godot;

void Ability::_register_methods() {
	//register_method((char*)"_process", &Weapon::_process);
	register_method((char*)"_ready", &Ability::_ready);
	register_method((char*)"_physics_process", &Ability::_physics_process);
	//register_method((char*)"_on_AnimationPlayer_animation_finished", &Weapon::_on_AnimationPlayer_animation_finished);
}

void Ability::_init() { return; }

Ability::Ability() {
	iCooldown = 0; //safety assign
	set_physics_process(false);
	return;
}
Ability::~Ability() { return; }

void Ability::_ready() { return; }

void Ability::StartCooldown() {
	iCountdown = iCooldown;
	set_physics_process(true);
	isDisabled = true;
}

void Ability::_physics_process(float delta) {
	if (isDisabled) {
		iCountdown -= 1;
		if (iCountdown <= 0) {
			isDisabled = false;
			set_physics_process(false);
		}
	}
	return;
}

int Ability::GetCooldown() { return iCooldown; }
int Ability::GetRemainingCooldown() { return iCountdown; }