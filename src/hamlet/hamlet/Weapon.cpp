#include "Weapon.h"

using namespace godot;

void Weapon::_register_methods() {
	//register_method((char*)"_process", &Weapon::_process);
	register_method((char*)"_ready", &Weapon::_ready);
	//register_method((char*)"_on_Area2D_body_entered", &Weapon::_on_Area2D_body_entered);
}

void Weapon::_ready() { _physics_process(false); }

void Weapon::Attack() {
	_change_state(ATTACK);
}

void Weapon::_change_state(bool new_sate) {
	current_state = new_sate;
	
	if (!current_state)
		set_physics_process(false);
	else {
		set_physics_process(true);
		pAnimationPlayer->play("attack");
	}
}

void Weapon::_physics_process(float delta) {
	Array aOverlappingBodies = get_overlapping_bodies();
	if (aOverlappingBodies.size() == 0)
		return;
	for (int x = 0; x < aOverlappingBodies.size(); x++) {
		// TODO: Check if inherits from class Actor, this cast is super unsafe
		Actor aActor = (Actor)aOverlappingBodies[x];
		if (!IsOwner(aActor))
			aActor.ReduceHealth(fDamage);	
	}
	set_physics_process(false); // End the attack on hit
}

// Don't attack ourselves
bool Weapon::IsOwner(Node actor) {
	if (this->get_parent()->get_name() == actor.get_name())
		return true;
	return false;
}