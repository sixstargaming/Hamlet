#ifndef LUNGE_H
#define LUNGE_H

#include "Ability.h"
#include "Actor.h"
#include "Player.h"

namespace godot {
	class Player;

	class Lunge : public Ability {
		GODOT_CLASS(Lunge, Ability)

	private:
		int distance = 1800;
		Player* actor;

	public:

		void _init();

		Lunge();
		Lunge(Player* argp);
		~Lunge();

		void Execute();
	};
}

#endif //!LUNGE_H