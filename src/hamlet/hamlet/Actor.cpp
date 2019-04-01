#include "Actor.h"

using namespace godot;

void Actor::_register_methods() {
	register_method((char*)"_process", &Actor::_process);
	register_method((char*)"_ready", &Actor::_ready);
}

void Actor::_init() { }

Actor::Actor() { return; }
Actor::Actor(bool a) { if (!a) isAnimate = false;  } // Constuctor for inanimate objects
Actor::~Actor() { return; }

void Actor::_process(float delta) {
	return;
}

void Actor::_ready() { 
	//set_physics_process(false); 
}

// HP methods
bool Actor::ReduceHealth(float fDamage) {
	if (isAnimate && isAlive) {
		fHealth -= fDamage;
		return CheckLivingStatus();
	}
	return false;
}

bool Actor::CheckLivingStatus() {
	if (isAnimate && fHealth <= 0) {
		isAlive = false;
		queue_free(); // Kills object
	}
	return isAlive;
}