#include "pgfx.h"

pgfx_HBAR::pgfx_HBAR(int x, int y, int w, int h, char * name, U8GLIB_SSD1306_128X64 & display)
{
  _x = x;
  _y = y;
  _width = w;
  _height = h;
  _display = & display;
  _name = name;
}

void pgfx_HBAR::update(float value, float max)
{

  _display->drawStr(_x, _y+8, _name);
  // _display->setTextSize(1);
  // _display->setTextColor(WHITE);
  _display->drawRFrame(_x, _y+16, _width, _height-16, 4);
  if (max >0 && value > 0) {
  	int fp = (value / max) * (_height-20);
  	_display->drawRBox(_x+2, _y+18 + ((_height-20) - fp), _width-4, fp, 4);
  }
  // _display->setCursor(_x,_y);
  // _display->println(_name);

}

void pgfx_HBAR::update(float v1, float m1, float v2, float m2)
{
  _display->drawStr(_x, _y+8, _name);

  // _display->setTextSize(1);
  // _display->setTextColor(WHITE);
  _display->drawRFrame(_x, _y+16, _width, _height-16, 4);
  if (m1 > 0 && v1 > 0) {
  	int fp1 = (v1 / m1) * (_height-20);
  	_display->drawRBox(_x+2, _y+18 + ((_height-20) - fp1), (_width/2)-3, fp1, 2);
  }
  if (m2 > 0 && v2 > 0) {
  	int fp2 = (v2 / m2) * (_height-20);
  	_display->drawRBox(_x+(_width/2)+1, _y+18 + ((_height-20) - fp2), (_width/2)-3, fp2, 2);
  }
  // _display->setCursor(_x,_y);
  // _display->println(_name);

}
 
