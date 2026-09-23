#include "flying_enemy.hpp"

using biv::FlyingEnemy;

FlyingEnemy::FlyingEnemy(const Coord& top_left, const int width, const int height)
	: AbstractEnemy(top_left, width, height) {
	hspeed = 0.15;
	vspeed = 0.1;
	min_y = top_left.y - 4;
	max_y = top_left.y + 4;
}

void FlyingEnemy::move_vertically() noexcept {
	top_left.y += vspeed;
	if (top_left.y <= min_y || top_left.y >= max_y) {
		vspeed = -vspeed;
	}
}

void FlyingEnemy::process_horizontal_static_collision(Rect* obj) noexcept {
	hspeed = -hspeed;
	move_horizontally();
}

void FlyingEnemy::process_vertical_static_collision(Rect* obj) noexcept {
	
}