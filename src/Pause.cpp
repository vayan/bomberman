#include "Pause.hh"

Pause::Pause() : AObject()
{
	Pause_img = gdl::Image::load("assets/img/pause.png");
	is_active = false;
	svg = new Save();
}

Pause::~Pause()
{


}

void      Pause::initialize(void)
{


}

void      Pause::update(gdl::GameClock const &clock, gdl::Input &_input)
{
  clock.getElapsedTime();
  _input.getMousePositionX();
  return;
}

void      Pause::draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	UI::glEnable2D();
	UI::DrawImage(Pause_img, X_OFFSET, Y_OFFSET);
	UI::glDisable2D();
}
