#include "abstract_enemy.hpp"

#include "map_movable.hpp"

using biv::AbstractEnemy;

AbstractEnemy::AbstractEnemy(const Coord& top_left, const int width, const int height)
	: RectMapMovableAdapter(top_left, width, height) {}

biv::Rect AbstractEnemy::get_rect() const noexcept {
	return {top_left, width, height};
}

biv::Speed AbstractEnemy::get_speed() const noexcept {
	return {vspeed, hspeed};
}

void AbstractEnemy::process_mario_collision(Collisionable* mario) noexcept {
	if (mario->get_speed().v > 0 && mario->get_speed().v != V_ACCELERATION) {
		kill();
	}
    else {
		mario->kill();
	}
}