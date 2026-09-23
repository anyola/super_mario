#pragma once

#include "abstract_enemy.hpp"

namespace biv {
	class FlyingEnemy : public AbstractEnemy {
		private:
			float min_y;
			float max_y;

		public:
			FlyingEnemy(const Coord& top_left, const int width, const int height);

			void move_vertically() noexcept override;

			void process_horizontal_static_collision(Rect*) noexcept override;
			void process_vertical_static_collision(Rect*) noexcept override;
	};
}