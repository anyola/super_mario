#pragma once

#include "collisionable.hpp"
#include "movable.hpp"
#include "rect.hpp"
#include "rect_map_movable_adapter.hpp"
#include "speed.hpp"

namespace biv {
	class AbstractEnemy : public RectMapMovableAdapter, public Movable, public Collisionable {
		public:
			AbstractEnemy(const Coord& top_left, const int width, const int height);

			Rect get_rect() const noexcept override;
			Speed get_speed() const noexcept override;

			void process_mario_collision(Collisionable*) noexcept override;

			void process_horizontal_static_collision(Rect*) noexcept override = 0;
			void process_vertical_static_collision(Rect*) noexcept override = 0;
	};
}