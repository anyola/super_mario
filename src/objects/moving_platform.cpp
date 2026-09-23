#include "moving_platform.hpp"

using biv::MovingPlatform;

MovingPlatform::MovingPlatform(
	const Coord& top_left, const int width, const int height,
	const int patrol_range
) : RectMapMovableAdapter(top_left, width, height) {
	hspeed = 0.1;
	vspeed = 0;
	min_x = top_left.x - patrol_range;
	max_x = top_left.x + patrol_range;
}

biv::Rect MovingPlatform::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed MovingPlatform::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void MovingPlatform::move_horizontally() noexcept {
	top_left.x += hspeed;
	if (top_left.x <= min_x || top_left.x >= max_x) {
		hspeed = -hspeed;
	}
}

void MovingPlatform::move_vertically() noexcept {
	
}

void MovingPlatform::process_horizontal_static_collision(Rect* obj) noexcept {
	
}

void MovingPlatform::process_mario_collision(Collisionable* obj) noexcept {
	Rect mario_rect = obj->get_rect();
	if (mario_rect.get_bottom() <= get_top() + 1) {
		static_cast<Mario*>(obj)->move_horizontal_offset(hspeed);
	}
}

void MovingPlatform::process_vertical_static_collision(Rect* obj) noexcept {

}