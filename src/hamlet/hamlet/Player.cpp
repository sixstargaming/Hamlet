#include "Player.h"

using namespace godot;

Weapon* Player::pWeapon;

void Player::_register_methods() {
	register_method((char*)"_process", &Player::_process);
	register_method((char*)"_ready", &Player::_ready);
	//register_method((char*)"_on_Area2D_body_entered", &Player::_on_Area2D_body_entered);
}

void Player::_init() { }

Player::Player() {
	pWeapon = nullptr;
	motion = Vector2(0, 0);

	// Create ability on palyer
	pAbility = new Backstep(this);
}
Player::~Player() { 
	delete pAbility;
	return; 
}

void Player::_process(float delta) {
	UpdateFromInput();
	move_and_slide(motion);

	if (!isAbilityEnabled) {
		iAbilityCountdown -= 1;
		if (iAbilityCountdown <= 0)
			isAbilityEnabled = true;
	}
	Godot::print(isAbilityEnabled);
	return;

}

void Player::UpdateFromInput() {
	motion = Vector2(0, 0);
	Input* i = Input::get_singleton();

	// Movement
	if (i->is_action_pressed("ui_up")) 
		motion.y -= SPEED;
	if (i->is_action_pressed("ui_down")) 
		motion.y += SPEED;
	if (i->is_action_pressed("ui_left")) 
		motion.x -= SPEED;
	if (i->is_action_pressed("ui_right")) 
		motion.x += SPEED;

	// Actions
	if (i->is_action_pressed("player_attack") && pWeapon)
		pWeapon->Attack();
	if (i->is_action_pressed("player_ability") && pAbility && isAbilityEnabled)
		pAbility->Execute();
}

void Player::_ready() {
	const godot::String gsCamera2D = "Camera2D";
	Node* n;
	godot::Array a = get_children();
	int64_t childCount = get_child_count();

	for (int64_t x = 0; x < childCount; x++) {
		n = get_child(x);
		if (gsCamera2D == n->get_name()) {
			pCamera = (Camera2D*)n;
		}
	}

	//Root::pPlayer = this;
}

/*void Player::_on_Area2D_body_entered(PhysicsBody2D *offendingObject) {
	if (offendingObject->get_name() == "Monster") {
		Actor target = (Actor)offendingObject->get_owner();
		target.ReduceHealth(100);
	}
}*/