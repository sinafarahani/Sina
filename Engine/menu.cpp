#include "menu.h"

void menu::draw(bool& Started,bool& setting, Graphics& gfx, MainWindow& wnd, settings& settings)
{
	if (!setting) {
		if (!Started) {
			F.Drawtext("Start", line_1, Colors::White, gfx);
		}
		else {
			F.Drawtext("Leave", line_1, Colors::White, gfx);
		}
		F.Drawtext("Setting", line_2, Colors::White, gfx);
	}
	else {
		if (!control) {
			F.Drawtext("control", line_1, Colors::White, gfx);
		}
		else {
			if (is_modify_scar) {
				modify_scar(wnd, settings);
				F.Drawtext("modify", line_2_2, Colors::Red, gfx);
			}
			else {
				F.Drawtext("modify", line_2_2, Colors::Blue, gfx);
			}
			if (is_modify_pump) {
				modify_pump(wnd, settings);
				F.Drawtext("modify", line_3_2, Colors::Red, gfx);
			}
			else {

				F.Drawtext("modify", line_3_2, Colors::Blue, gfx);
			}
			string sc = "scar: " + string(1, settings.scar_key);
			string pu = "pump: " + string(1, settings.pump_key);
			F.Drawtext("keys", line_1, Colors::White, gfx);
			F.Drawtext(sc, line_2, Colors::White, gfx);
			F.Drawtext(pu, line_3, Colors::White, gfx);
		}
	}
}

void menu::detect(Vei2& pos, bool& Started, bool& setting, MainWindow& wnd, settings& settings)
{
	switch (menu::option(pos,Started,setting,wnd,settings))
	{
	case menu::options::Start:
		Started = true;
		break;
	case menu::options::Settings:
		setting = true;
		break;
	case menu::options::Leave:
		Started = false;
		break;
	case menu::options::Control:
		control = true;
		break;
	case menu::options::Modify_scar:
		is_modify_scar = true;
		break;
	case menu::options::Modify_pump:
		is_modify_pump = true;
		break;
	case menu::options::Empty:
		break;
	}
}

void menu::modify_scar(MainWindow& wnd, settings& settings)
{
	while (!wnd.kbd.KeyIsEmpty()) {
		const auto evt = wnd.kbd.ReadKey();
		if (evt.GetCode() == VK_RETURN) {
			is_modify_scar = false;
		}
		else if (evt.GetCode() == VK_ESCAPE) {
			is_modify_scar = false;
		}
		else {
			settings.scar_key = (char)evt.GetCode();
			settings.create();
		}
	}
}

void menu::modify_pump(MainWindow& wnd, settings& settings)
{
	while (!wnd.kbd.KeyIsEmpty()) {
		const auto evt = wnd.kbd.ReadKey();
		if (evt.GetCode() == VK_RETURN) {
			is_modify_pump = false;
		}
		else if (evt.GetCode() == VK_ESCAPE) {
			is_modify_pump = false;
		}
		else {
			settings.pump_key = (char)evt.GetCode();
			settings.create();
		}
	}
}

bool menu::is_on(Vei2 pos, Vei2 line, Vei2 size) const
{
	return pos.x >= line.x && pos.x <= line.x + size.x && pos.y >= line.y && pos.y <= line.y + size.y;
}

menu::options menu::option(Vei2& pos, bool& Started,bool& setting, MainWindow& wnd, settings& settings)
{
	if (!setting) {
		if (is_on(pos,line_1,size_1)) {
			if (!Started)
				return options::Start;
			else
				return options::Leave;
		}
		else if (is_on(pos, line_2, size_1)) {
			return options::Settings;
		}
		else
			return options::Empty;
	}
	else {
		if (!control) {
			if (is_on(pos, line_1, size_1)) {
				return options::Control;
			}
			else
				return options::Empty;
		}
		else {
			if (is_on(pos, line_2_2, size_1)) {
				return options::Modify_scar;
			}
			else if (is_on(pos, line_3_2, size_1)) {
				return options::Modify_pump;
			}
			else
				return options::Empty;
		}
	}
}
