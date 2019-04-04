#include "Monster.h"

using namespace godot;

void Monster::_register_methods() {
	register_method((char*)"_ready", &Monster::_ready);
}

void Monster::_init() { return;  }

Monster::Monster() { fHealth = 100; }
Monster::~Monster() { return; }