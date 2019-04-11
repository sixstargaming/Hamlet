#ifndef BACKSTEP_H
#define BACKSTEP_H

#include "Ability.h"
#include "Actor.h"

namespace godot {
	class Backstep : Ability {
		GODOT_CLASS(Backstep, Ability)

	private:
		int distance = 300;
		Actor* actor;

	public:

		void _init();

		Backstep(Actor* actor);
		~Backstep();

		void Execute();
	};
}

#endif //!BACKSTEP_H