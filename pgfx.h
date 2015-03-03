#ifndef _PSIMAX_GFX_H
#define _PSIMAX_GFX_H

/* EXAMPLE
 * pgfx_HBAR fbar = pgfx_HBAR(0, 0,20,64,"FUEL",display);
 * pgfx_HBAR mbar = pgfx_HBAR(32,0,20,64,"MONO",display);
 * pgfx_HBAR gbar = pgfx_HBAR(64, 0,20,64,"FUEL",display);
 * pgfx_HBAR hbar = pgfx_HBAR(96,0,20,64,"MONO",display);
 * // single bargraphs
 * fbar.update(32,100);
 * mbar.update(100,100);
 * // dual bargraphs
 * gbar.update(32,100,100,100);
 * hbar.update(4,100,10,100);
 * display.display();
*/

#include <Adafruit_SSD1306.h>

class pgfx_HBAR {
public:
	pgfx_HBAR(int x, int y, int w, int h, char * name, Adafruit_SSD1306 &display); // Constructor

	void
		update(float value, float max),
		update(float v1, float m1, float v2, float m2);

private:
	int
		_width, _height,
		_x, _y;
	Adafruit_SSD1306 * _display;
	char * _name;
};

#endif