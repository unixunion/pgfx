#ifndef _PSIMAX_GFX_H
#define _PSIMAX_GFX_H

/* 

https://code.google.com/p/u8glib/


// EXAMPLE

// pins 
// OLED Display
#define OLED_MOSI  1
#define OLED_CLK   2
#define OLED_DC    4
#define OLED_CS    3
#define OLED_RESET 5

// driver
U8GLIB_SSD1306_128X64 display(OLED_CLK, OLED_MOSI, OLED_CS, OLED_DC, OLED_RESET);

// setup
// display.setFont(u8g_font_profont12);
// display.setFontPosTop();

// Gauges
pgfx_HBAR fbar = pgfx_HBAR( 0, 0,20,64,"FUEL",display);
pgfx_HBAR mbar = pgfx_HBAR(26, 0,20,64,"MONO",display);
pgfx_HBAR ebar = pgfx_HBAR(52, 0,20,64,"ELEC",display);
pgfx_HBAR gbar = pgfx_HBAR(78, 0,20,64,"G's",display);

// single bargraphs
fbar.update(VData.LiquidFuelS, VData.LiquidFuelTotS, VData.LiquidFuel, VData.LiquidFuelTot);
mbar.update(VData.MonoProp, VData.MonoPropTot);
ebar.update(VData.ECharge, VData.EChargeTot);
gbar.update(VData.G, 15);
display.display();

*/

#include <U8glib.h>

class pgfx_HBAR {
public:
	pgfx_HBAR(int x, int y, int w, int h, char * name, U8GLIB_SSD1306_128X64 &display); // Constructor

	void
		update(float value, float max),
		update(float v1, float m1, float v2, float m2);

private:
	int
		_width, _height,
		_x, _y;
	U8GLIB_SSD1306_128X64 * _display;
	char * _name;
};

#endif