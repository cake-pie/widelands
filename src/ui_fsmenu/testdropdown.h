#ifndef WL_UI_FSMENU_TESTDROPDOWN_H
#define WL_UI_FSMENU_TESTDROPDOWN_H

#include "logic/game_settings.h"
#include "ui_fsmenu/main.h"

namespace FsMenu {

class TestDropdown : public UI::UniqueWindow {
public:
	explicit TestDropdown(MainMenu&, UI::UniqueWindow::Registry&);
	~TestDropdown() override = default;

	WindowLayoutID window_layout_id() const override {
		return UI::Window::WindowLayoutID::kFsMenuAbout;
	}

protected:
	void layout() override;

private:
	UI::Box box_;
	UI::Dropdown<std::string> dd_txt_rdgr;
	UI::Dropdown<std::string> dd_pic_rdgr;
	UI::Dropdown<std::string> dd_txt_tggl;
	UI::Dropdown<std::string> dd_pic_tggl;

	void init_dd(UI::Dropdown<std::string>& dd, const GameSettings& settings);
};

}  // namespace FsMenu

#endif  // end of include guard: WL_UI_FSMENU_TESTDROPDOWN_H
