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
        // if (_input.isMouseButtonDown(gdl::Mouse::Left) == true)
	// {
	// 	int x = _input.getMousePositionX();
	// 	int y = _input.getMousePositionY();

	// 	//std::cout << " X " << x << " Y " << y << std::endl;
	// 	if (PAUSE_BUTTON_SAVE)
	// 	{
	// 		std::cout << "1 SAVE PUSH" << std::endl;
	// 	}
	// 	if (PAUSE_BUTTON_RESUME)
	// 	{
	// 		std::cout << "2 RESUME PUSH" << std::endl;
	// 		is_active = false;
	// 	}
	// 	if (PAUSE_BUTTON_EXIT)
	// 		exit (EXIT_SUCCESS);
	// }
}

void      Pause::draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	UI::glEnable2D();
	UI::DrawImage(Pause_img, X_OFFSET, Y_OFFSET);
	UI::glDisable2D();
}
