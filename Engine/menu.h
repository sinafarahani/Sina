#pragma once

#include "MainWindow.h"
#include "Font.h"
#include "Graphics.h"
#include "Colors.h"
#include "settings.h"

class menu {
public:
	enum class options {
		Start,
		Settings,
		Leave,
		Control,
		Modify_scar,
		Modify_pump,
		Empty
	};
	void draw(bool& Started,bool& setting, Graphics& gfx, MainWindow& wnd, settings& settings);
	void detect(Vei2& pos,bool& Started, bool& setting, MainWindow& wnd, settings& settings);
	bool control = false;
	bool is_modify_scar = false;
	bool is_modify_pump = false;
	Font F = "Images\\Fixedsys16x28.bmp";
private:
	void modify_scar(MainWindow& wnd, settings& settings);
	void modify_pump(MainWindow& wnd, settings& settings);
	bool is_on(Vei2 pos, Vei2 line, Vei2 size) const;
	options option(Vei2& pos, bool& Started,bool& setting, MainWindow& wnd, settings& settings);
	Vei2 line_1 = { 500, 100 };
	Vei2 line_2{ 500 , 200 };
	Vei2 line_2_2{ 700 , 200 };
	Vei2 line_3{ 500 , 300 };
	Vei2 line_3_2{ 700 , 300 };
	Vei2 size_1 = { 100, 50 };
};