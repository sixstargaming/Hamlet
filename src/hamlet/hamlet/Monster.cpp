#include "Monster.h"

using namespace godot;

void Monster::_register_methods() {
	register_method((char*)"_ready", &Monster::_ready);
	register_method((char*)"_process", &Monster::_process);
}

void Monster::_init() { return; }

Monster::Monster() { fHealth = 100.00f; }
Monster::~Monster() { return; }

void Monster::_process(float delta) {
	if (fHealth <= 0) Die();
}