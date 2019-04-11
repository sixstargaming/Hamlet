#include "Ability.h"

using namespace godot;

void Ability::_register_methods() {
	//register_method((char*)"_process", &Weapon::_process);
	register_method((char*)"_ready", &Ability::_ready);
	register_method((char*)"_fixed_process", &Ability::_fixed_process);
	//register_method((char*)"_on_AnimationPlayer_animation_finished", &Weapon::_on_AnimationPlayer_animation_finished);
}

void Ability::_init() { return; }

Ability::Ability() { iCooldown = 0; /*safety assign*/ return; }
Ability::~Ability() { return; }

void Ability::_ready() { return; }

void Ability::StartCooldown() {
	iCountdown = iCooldown;
	isDisabled = true;
}

void Ability::_fixed_process(float delta) {
	if (isDisabled) {
		iCountdown -= 1;
		if (iCountdown <= 0)
			isDisabled = false;
	}
	return;
}

int Ability::GetCooldown() { return iCooldown; }
int Ability::GetRemainingCooldown() { return iCountdown; }