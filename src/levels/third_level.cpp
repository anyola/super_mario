#include "third_level.hpp"

using biv::ThirdLevel;

ThirdLevel::ThirdLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

bool ThirdLevel::is_final() const noexcept {
	return true;
}

biv::GameLevel* ThirdLevel::get_next() {
	return next;
}

void ThirdLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);
	ui_factory->create_ship({20, 25}, 30, 2);
	ui_factory->create_jumping_enemy({28, 20}, 3, 2);
	ui_factory->create_flying_enemy({48, 15}, 3, 2);
	ui_factory->create_ship({65, 25}, 10, 2);
	ui_factory->create_jumping_enemy({67, 20}, 3, 2);
	ui_factory->create_moving_platform({85, 25}, 5, 2, 7);
	ui_factory->create_ship({105, 25}, 10, 2);
	ui_factory->create_ship({125, 20}, 12, 7);
	ui_factory->create_box({128, 13}, 3, 3);
	ui_factory->create_full_box({133, 10}, 3, 3);
	ui_factory->create_moving_platform({145, 25}, 5, 2, 6);
	ui_factory->create_flying_enemy({155, 16}, 3, 2);
	ui_factory->create_ship({165, 25}, 10, 2);
	ui_factory->create_jumping_enemy({167, 20}, 3, 2);
	ui_factory->create_moving_platform({182, 25}, 5, 2, 6);
	ui_factory->create_ship({200, 25}, 20, 2);
}