#include "ui_fsmenu/testlistselect.h"

namespace FsMenu {

TestListselect::TestListselect(MainMenu& fsmm, UI::UniqueWindow::Registry& r)
   : UI::UniqueWindow(&fsmm,
                      UI::WindowStyle::kFsMenu,
                      "about",
                      &r,
                      610, 250,
                      "Listselect UI Test"),
     box_(this, UI::PanelStyle::kFsMenu, "main_box", 0, 0, UI::Box::Vertical),
     lsl_pl_(&box_, "list pl", 10, 20, 190, 150, UI::PanelStyle::kFsMenu,
             UI::ListselectLayout::kPlain),
     lsl_sc_(&box_, "list sc", 210, 20, 190, 150, UI::PanelStyle::kFsMenu,
             UI::ListselectLayout::kShowCheck),
     lsl_ms_(&box_, "list ms", 410, 20, 190, 150, UI::PanelStyle::kFsMenu,
             UI::ListselectLayout::kMultiCheck) {
	lsl_pl_.add("Item 3", "A3", nullptr, false);
	lsl_pl_.add("Item 0", "A0", nullptr, false);
	lsl_pl_.add("Item 2", "A2", nullptr, false);
	lsl_pl_.add("Item 1", "A1", nullptr, false);
	lsl_pl_.sort();

	lsl_sc_.add("Item 3", "B3", nullptr, false);
	lsl_sc_.add("Item 0", "B0", nullptr, false);
	lsl_sc_.add("Item 2", "B2", nullptr, false);
	lsl_sc_.add("Item 1", "B1", nullptr, false);
	lsl_sc_.sort();

	lsl_ms_.add("Item 3", "C3", nullptr, false);
	lsl_ms_.add("Item 0", "C0", nullptr, false);
	lsl_ms_.add("Item 2", "C2", nullptr, false);
	lsl_ms_.add("Item 1", "C1", nullptr, false);
	lsl_ms_.sort();

	lsl_pl_.selected.connect([this](uint32_t i) {
		log_info("Received signal for A %i selected\n", i);
	});
	lsl_pl_.checkmark_changed.connect([this](std::string e, bool v) {
		log_info("Received signal for A %s chkchgto %s\n", e.c_str(), v?"T":"F");
	});
	lsl_sc_.selected.connect([this](uint32_t i) {
		log_info("Received signal for B %i selected\n", i);
	});
	lsl_sc_.checkmark_changed.connect([this](std::string e, bool v) {
		log_info("Received signal for B %s chkchgto %s\n", e.c_str(), v?"T":"F");
	});
	lsl_ms_.selected.connect([this](uint32_t i) {
		log_info("Received signal for C %i selected\n", i);
	});
	lsl_ms_.checkmark_changed.connect([this](std::string e, bool v) {
		log_info("Received signal for C %s chkchgto %s\n", e.c_str(), v?"T":"F");
	});

	layout();
	center_to_parent();
	initialization_complete();
}

void TestListselect::layout() {
	UI::Window::layout();
	if (!is_minimal()) {
		box_.set_size(get_inner_w(), get_inner_h());
	}
}

}  // namespace FsMenu
