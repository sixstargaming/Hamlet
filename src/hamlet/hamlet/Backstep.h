#ifndef BACKSTEP_H
#define BACKSTEP_H

#include "Ability.h"
#include "Actor.h"
#include "Player.h"

namespace godot {
	class Player;

	class Backstep : public Ability {
		GODOT_CLASS(Backstep, Ability)

	private:
		int distance = -1800;
		Player* actor;

	public:

		void _init();

		Backstep();
		Backstep(Player* argp);
		~Backstep();

		void Execute();
	};
}

#endif //!BACKSTEP_H