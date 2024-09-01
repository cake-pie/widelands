#include "ui_fsmenu/testdropdown.h"

#include "logic/single_player_game_settings_provider.h"

namespace FsMenu {

TestDropdown::TestDropdown(MainMenu& fsmm, UI::UniqueWindow::Registry& r)
	: UI::UniqueWindow(&fsmm,
			UI::WindowStyle::kFsMenu,
			"about",
			&r,
			400, 250,
			"Dropdown UI Test"),
	box_(this, UI::PanelStyle::kFsMenu, "main_box", 0, 0, UI::Box::Vertical),
	dd_txt_rdgr(&box_, "txt rdgr", 10, 10, 150, 16, 32, _("Tribe"),
		UI::DropdownType::kTextualRadioGrp,
		UI::PanelStyle::kFsMenu, UI::ButtonStyle::kFsMenuSecondary),
	dd_pic_rdgr(&box_, "pic rdgr", 160, 10, 32, 16, 32, "",
		UI::DropdownType::kPictorialRadioGrp,
		UI::PanelStyle::kFsMenu, UI::ButtonStyle::kFsMenuSecondary),
	dd_txt_tggl(&box_, "txt tggl", 10, 110, 150, 16, 32, _("Tribe"),
		UI::DropdownType::kTextualToggles,
		UI::PanelStyle::kFsMenu, UI::ButtonStyle::kFsMenuSecondary),
	dd_pic_tggl(&box_, "pic tggl", 160, 110, 32, 16, 32, "",
		UI::DropdownType::kPictorialToggles,
		UI::PanelStyle::kFsMenu, UI::ButtonStyle::kFsMenuSecondary) {
	auto spgsp = new SinglePlayerGameSettingsProvider();
	const Image* ico = g_image_cache->get("images/players/no_team.png");
	init_dd(dd_txt_rdgr, spgsp->settings());
	dd_pic_rdgr.set_image(ico);
	init_dd(dd_pic_rdgr, spgsp->settings());
	init_dd(dd_txt_tggl, spgsp->settings());
	dd_pic_tggl.set_image(ico);
	init_dd(dd_pic_tggl, spgsp->settings());
	delete spgsp;

	layout();
	center_to_parent();
	initialization_complete();
}

void TestDropdown::init_dd(UI::Dropdown<std::string>& dd, const GameSettings& settings) {
	for (const Widelands::TribeBasicInfo& tribeinfo : settings.tribes) {
		dd.add(tribeinfo.descname, tribeinfo.name, g_image_cache->get(tribeinfo.icon),
			false, tribeinfo.tooltip);
	}

	auto n = dd.get_name().c_str();
	dd.selected.connect([this, n, &dd]() {
		log_info("Received signal for %s selected %s\n", n, dd.get_selected().c_str());
	});
	dd.checkmark_changed.connect([this, n](std::string e, bool v) {
		log_info("Received signal for %s entry %s chkchgto %s\n", n, e.c_str(), v?"T":"F");
	});
}

void TestDropdown::layout() {
	UI::Window::layout();
	if (!is_minimal()) {
		box_.set_size(get_inner_w(), get_inner_h());
	}
}

}  // namespace FsMenu
