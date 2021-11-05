#include "aim.h"


void aim::DrawAimtoogled(Graphics& gfx) {
	for (int i = int(pos.x - (toogled_hud * 2.3)); i < pos.x - toogled_hud; i++) {
		gfx.PutPixel(i, int(pos.y), r, g, b);
	}for (int i = int(pos.x + toogled_hud); i < pos.x + (toogled_hud * 2.3); i++) {
		gfx.PutPixel(i, int(pos.y), r, g, b);
	}for (int i = int(pos.y - (toogled_hud * 2.3)); i < pos.y - toogled_hud; i++) {
		gfx.PutPixel(int(pos.x), i, r, g, b);
	}for (int i = int(pos.y + toogled_hud); i < pos.y + (toogled_hud * 2.3); i++) {
		gfx.PutPixel(int(pos.x), i, r, g, b);
	}

}
void aim::DrawAimtoogledtar(Graphics& gfx) {
	for (int i = int(pos.x - (toogled_hud * 2.3)); i < pos.x - toogled_hud; i++) {
		gfx.PutPixel(i, int(pos.y), r, 0, 0);
	}for (int i = int(pos.x + toogled_hud); i < pos.x + (toogled_hud * 2.3); i++) {
		gfx.PutPixel(i, int(pos.y), r, 0, 0);
	}for (int i = int(pos.y - (toogled_hud * 2.3)); i < pos.y - toogled_hud; i++) {
		gfx.PutPixel(int(pos.x), i, r, 0, 0);
	}for (int i = int(pos.y + toogled_hud); i < pos.y + (toogled_hud * 2.3); i++) {
		gfx.PutPixel(int(pos.x), i, r, 0, 0);
	}

}
void aim::DrawAim(Graphics& gfx) {
	for (int i = int(pos.x - (hud * 2.3)); i < pos.x - hud; i++) {
		gfx.PutPixel(i, int(pos.y), r, g, b);
	}for (int i = int(pos.x + hud); i < pos.x + (hud * 2.3); i++) {
		gfx.PutPixel(i, int(pos.y), r, g, b);
	}for (int i = int(pos.y - (hud * 2.3)); i < pos.y - hud; i++) {
		gfx.PutPixel(int(pos.x), i, r, g, b);
	}for (int i = int(pos.y + hud); i < pos.y + (hud * 2.3); i++) {
		gfx.PutPixel(int(pos.x), i, r, g, b);
	}
}