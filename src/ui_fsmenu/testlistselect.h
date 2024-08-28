#ifndef WL_UI_FSMENU_TESTLISTSELECT_H
#define WL_UI_FSMENU_TESTLISTSELECT_H

#include "ui_fsmenu/main.h"

namespace FsMenu {

class TestListselect : public UI::UniqueWindow {
public:
	explicit TestListselect(MainMenu&, UI::UniqueWindow::Registry&);
	~TestListselect() override = default;

	WindowLayoutID window_layout_id() const override {
		return UI::Window::WindowLayoutID::kFsMenuAbout;
	}

protected:
	void layout() override;

private:
	UI::Box box_;
	UI::Listselect<std::string> lsl_pl_;
	UI::Listselect<std::string> lsl_sc_;
	UI::Listselect<std::string> lsl_ms_;
};

}  // namespace FsMenu

#endif  // end of include guard: WL_UI_FSMENU_TESTLISTSELECT_H
