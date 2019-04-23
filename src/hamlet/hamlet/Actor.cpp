#include "Actor.h"

using namespace godot;

void Actor::_register_methods() {
	register_method((char*)"_ready", &Actor::_ready);
	register_method((char*)"_process", &Actor::_process);
	//register_method((char*)"_physics_process", &Actor::_physics_process);
}

void Actor::_init() { }

Actor::Actor() { return; }
Actor::Actor(bool a) { 
	if (!a) isAnimate = false; // Constuctor for inanimate objects
	set_process(true);
} 
Actor::~Actor() { set_process(true);  return; }

// Only run if _process is not overloaded
void Actor::_process(float delta) {
	if (!isAbilityEnabled) {
		iAbilityCountdown -= 1;
		if (iAbilityCountdown <= 0)
			isAbilityEnabled = true;
	}
	Godot::print(isAbilityEnabled);
	return;
}

void Actor::_physics_process(float delta) {
	return;
}

void Actor::_ready() { 
	//set_physics_process(true); 
}

// Weapon and Ability methods
void Actor::StartAbilityCooldown(int cooldown) {
	iAbilityCountdown = cooldown;
	isAbilityEnabled = false;
}

void Actor::StartAbility2Cooldown(int cooldown) {
	iAbility2Countdown = cooldown;
	isAbility2Enabled = false;
}

// HP methods
bool Actor::ReduceHealth(float fDamage) {
	if (isAnimate && isAlive) {
		fHealth -= fDamage;
		Godot::print("{0}", fHealth);
		return CheckLivingStatus();
	}
	return false;
}

bool Actor::CheckLivingStatus() {
	if (isAnimate && fHealth <= 0)
		isAlive = false;
	return isAlive;
}

void Actor::Die() {
	Godot::print("die");
	isAlive = false;
	queue_free();
}