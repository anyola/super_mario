#include "jumping_enemy.hpp"

using biv::JumpingEnemy;

JumpingEnemy::JumpingEnemy(const Coord& top_left, const int width, const int height)
	: AbstractEnemy(top_left, width, height) {
	hspeed = 0;
	vspeed = 0;
}

void JumpingEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	
}

void JumpingEnemy::process_vertical_static_collision(Rect* obj) noexcept {
	if (vspeed > 0) {
		top_left.y -= vspeed;
		vspeed = 0;
		jump();
	} 
    else if (vspeed < 0) {
		top_left.y -= vspeed;
		vspeed = 0;
	}
}