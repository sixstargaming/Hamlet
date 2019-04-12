#ifndef ABILITY_H
#define ABILITY_H

#include "Root.h"
#include <Node.hpp>

namespace godot {
	class Ability : public Node {
		GODOT_CLASS(Ability, Node) 

	protected:
		int iCooldown;
		int iCountdown;

	public:
		bool isDisabled = false;

		static void _register_methods();

		void _init();
		void _ready();
		void _physics_process(float delta);

		Ability();
		~Ability();

		void StartCooldown();
		int GetCooldown();
		int GetRemainingCooldown();

		// Method to be overwritten by inheritor
		void Execute();
	};
}

#endif //!ABILITY_H