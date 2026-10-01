#include "second_level.hpp"
#include "third_level.hpp"

using biv::SecondLevel;

SecondLevel::SecondLevel(UIFactory* ui_factory) : GameLevel(ui_factory) {
	init_data();
}

biv::GameLevel* SecondLevel::get_next() {
	if (!next) {
		clear_data();
		next = new biv::ThirdLevel(ui_factory);
	}
	return next;
}

bool SecondLevel::is_final() const noexcept {
	return false;
}

// ----------------------------------------------------------------------------
// 									PROTECTED
// ----------------------------------------------------------------------------
void SecondLevel::init_data() {
	ui_factory->create_mario({39, 10}, 3, 3);
 
	ui_factory->create_ship({20, 25}, 40, 2);
 
	ui_factory->create_ship({70, 25}, 20, 2);
	ui_factory->create_jumping_enemy({78, 20}, 3, 2);
 
	ui_factory->create_ship({100, 25}, 20, 2);
	ui_factory->create_flying_enemy({105, 15}, 3, 2);
	ui_factory->create_full_box({108, 18}, 5, 3);
	ui_factory->create_box({113, 18}, 5, 3);
 
	ui_factory->create_ship({130, 25}, 25, 2);
}
