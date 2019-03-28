#include "Actor.h"

using namespace godot;

void Actor::_register_methods() {
	register_method((char*)"_process", &Actor::_process);
	register_method((char*)"_ready", &Actor::_ready);
}

void Actor::_init() { }

Actor::Actor() { return; }
Actor::~Actor() { return; }

void Actor::_process(float delta) {
	return;
}

void Actor::_ready() { return; }