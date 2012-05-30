#include "Menu.hh"

Menu::Menu() 
{ 
	window_.setTitle("Bomberman Launcher");
	window_.create();
	window_.setWidth(800);
	window_.setHeight(600);	
	sp 			= 0;
	MainMenu_img 	= gdl::Image::load("assets/img/main_menu.png");
	SettingMenu_img = gdl::Image::load("assets/img/setting_menu.png");
	AI_img 			= gdl::Image::load("assets/img/icon_ai.png");
	Select_img 		= gdl::Image::load("assets/img/select_item.png");
	menu_select 	= 0;
	diff_select 	= conf.GetDifficulty();
	nb_icon_ai		 = conf.GetNb_AI();
	switch (conf.GetMapx())
	{
		case 11 :
		size_select = 0; break;
		case 22 :
		size_select = 1; break;
		case 33 :
		size_select = 2; break;
		default :
		size_select = 0; break;
	}
}



void 	Menu::DrawAIicon()
{
	int i = 0;
	int x = 387;
	int y = 250;

	while (i < nb_icon_ai)
	{
		if ((y >= 250 - 36))
		{
			UI::DrawImage(AI_img, x, y);
			x += 36;
			if (x >= 750)
			{
				x = 387; 
				y -= 36;
			}
		}
		i++;
	}
}

Menu::~Menu() { }

void 		Menu::MainMenu()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	UI::glEnable2D();
	UI::DrawImage(MainMenu_img, 0, 0);
	UI::glDisable2D();	
}

void Menu::PutSelect_size()
{
	int x = 0;
	int y = 126;

	switch (size_select)
	{
		case 0:
		x = 324; break;
		case 1:
		x = 444; break;
		case 2:
		x = 564; break;
	}
	UI::DrawImage(Select_img, x, y);
}

void  Menu::PutSelect_difficulty()
{
	int x = 0;
	int y = 170;

	switch (diff_select)
	{
		case 0:
		x = 324; break;
		case 1:
		x = 444; break;
		case 2:
		x = 564; break;
	}
	UI::DrawImage(Select_img, x, y);	
}

void 	Menu::MainMenu_input()
{
	if (input_.isMouseButtonDown(gdl::Mouse::Left) == true)
	{
		int x = input_.getMousePositionX();
		int y = input_.getMousePositionY();

		if (SINGLE_PLAYER_BUTTON)
		{
			conf.SetSVG(0);
			conf.SetNbPlayers(1);
			window_.close();
		}
		if (TWO_PLAYER_BUTTON)
		{
			conf.SetSVG(0);
			conf.SetNbPlayers(2);
			window_.close();
		}
		if (SETTING_BUTTON)
			menu_select = 1;
		if (EXIT_BUTTON)
		{
			conf.SetSVG(1);
			conf.SetNbPlayers(1);
			if(!std::ifstream("save.bm"))
				conf.SetSVG(0);
			window_.close();
		}
	}
}

void		Menu::save()
{
	conf.SetNb_AI(nb_icon_ai);
	conf.SetDifficulty(static_cast<Settings::Difficulty>(diff_select));
	switch (size_select)
	{
		case 0:
		conf.SetMapx(11);
		conf.SetMapY(11);
		break;
		case 1:
		conf.SetMapx(22);
		conf.SetMapY(22); 
		break;
		case 2:
		conf.SetMapx(33);
		conf.SetMapY(33);
		break;
	}
	menu_select = 0;
}

void 		Menu::SettingMenu()
{
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	UI::glEnable2D();
	glAlphaFunc( GL_GREATER, 0 );							
	glEnable( GL_ALPHA_TEST );
	UI::DrawImage(SettingMenu_img, 0, 0);
	DrawAIicon();
	PutSelect_difficulty();
	PutSelect_size();
	UI::glDisable2D();	
}

void 	Menu::SettingMenu_input()
{
	if (input_.isMouseButtonDown(gdl::Mouse::Left) == true)
	{
		int x = input_.getMousePositionX();
		int y = input_.getMousePositionY();

		usleep(40000);
		if (CANCEL_BUTTON)
			menu_select = 0;
		if (PLUS_BUTTON)
		{
			if (nb_icon_ai < 22)
				nb_icon_ai++;
		}
		if (MINUS_BUTTON)
		{
			if (nb_icon_ai > 0)
				nb_icon_ai--;
		}
		if (EASY_BUTTON)
			diff_select = 0;
		if (HARD_BUTTON)
			diff_select = 1;
		if (INFERNO_BUTTON)
			diff_select = 2;
		if (SAVE_BUTTON)
			save();
		if (SMALL_BUTTON)
			size_select = 0;
		if (MEDIUM_BUTTON)
			size_select = 1;
		if (BIG_BUTTON)
			size_select = 2;
	}
}



void      Menu::initialize(void) 
{ 
	menu_select = 0;
	time = 0;
	myClock.play();
}

void      Menu::update(void) 
{
	myClock.update();
	time += myClock.getElapsedTime();
	if (time >= 1.0 / 100.0)
	{
		time = 0;
		sp = sp + 1;
		camera_.update(gameClock_, input_);
		draw();
		switch (menu_select)
		{
			case 0:
			MainMenu_input(); break;
			case 1:
			SettingMenu_input(); break;
		}	
		if (sp == 20)
			sp = 0;
	}
}

void      Menu::draw(void) 
{
	switch (menu_select)
	{
		case 0:
		MainMenu(); break;
		case 1:
		SettingMenu(); break;
	}
	this->window_.display();
}

void  		Menu::unload(void) { }