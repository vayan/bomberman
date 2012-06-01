#include "EndGame.hh"


EndGame::EndGame()
{
  state = 0;
  img_EndScreen = gdl::Image::load("assets/img/endgamescreen.png");
  img_P1Win = gdl::Image::load("assets/img/p1win.png");
  img_P2Win = gdl::Image::load("assets/img/p2win.png");
  img_ULoose = gdl::Image::load("assets/img/youloose.png");
  img_UWin = gdl::Image::load("assets/img/youwin.png");
}

EndGame::~EndGame()
{

}

void      EndGame::initialize(void)
{

}

void      EndGame::update(gdl::GameClock const &clock, gdl::Input &_input)
{
  clock.getElapsedTime();
  _input.getMousePositionX();
}

void      EndGame::draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	UI::glEnable2D();
	UI::DrawImage(img_EndScreen, X_OFFSET, Y_OFFSET);

	switch (state) {
		case 1:
			UI::DrawImage(img_ULoose, X_OFFSET + 200, Y_OFFSET + 250);
		break;
		case 2:
			UI::DrawImage(img_UWin, X_OFFSET + 250, Y_OFFSET + 250);
		break;
		case 3:
			UI::DrawImage(img_P1Win, X_OFFSET + 200, Y_OFFSET + 250);
		break;
		case 4:
			UI::DrawImage(img_P2Win, X_OFFSET + 200, Y_OFFSET + 250);
		break;
	}

	UI::glDisable2D();
}

int           EndGame::getX() const { return (0); }
int           EndGame::getY() const { return (0); }
