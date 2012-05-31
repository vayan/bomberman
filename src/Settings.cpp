#include "Settings.hh"
#include "Utils.hh"

Settings::Settings()
{
	filename = "settings.conf";

	std::string buff;
	std::ifstream infile;

	if(!std::ifstream(filename.c_str()))
	{
		std::ofstream outfile (filename.c_str());
		outfile << "0" << std::endl;
		outfile << "1" << std::endl;
		outfile << "11" << std::endl;
		outfile << "11" << std::endl;
		outfile << "1" << std::endl;
		outfile << "0" << std::endl;
		outfile << "1" << std::endl;
		outfile.close();
	}

	infile.open(filename.c_str());

	if (infile.good())
	{
		getline(infile,buff);
		diffuclt = static_cast<Settings::Difficulty>(to_number<int>(buff));
	}
	if (infile.good())
	{
		getline(infile,buff);
		nb_ai = to_number<int>(buff);
		if (nb_ai > 22)
			nb_ai = 22;
	}
	if (infile.good())
	{
		getline(infile,buff);
		map_x = to_number<int>(buff);
	}
	if (infile.good())
	{
		getline(infile,buff);
		map_y = to_number<int>(buff);
	}
	if (infile.good())
	{
		getline(infile,buff);
		nb_players = to_number<int>(buff);
		if (nb_players > 2)
			nb_players = 1;
	}
	if (infile.good())
	{
		getline(infile,buff);
		restore_svg = to_number<int>(buff);
	}
	if (infile.good())
	{
		getline(infile,buff);
		type_keyboard = to_number<int>(buff);
	}
	infile.close();
	aff_settings();
}

Settings::~Settings()
{

}

void Settings::SetDifficulty(Settings::Difficulty diff)
{
	diffuclt = diff;
	RefreshSettings();
}

void 			Settings::SetSVG(int rest)
{
	restore_svg = rest;
	RefreshSettings();
}

void		   Settings::SetNb_AI(int _nb_ai)
{
	nb_ai = _nb_ai;
	RefreshSettings();
}

void		   Settings::SetMapx(int x)
{
	map_x = x;
	RefreshSettings();
}

void		   Settings::SetMapY(int y)
{
	map_y = y;
	RefreshSettings();
}

void 			Settings::SetNbPlayers(int nb)
{
	nb_players = nb;
	RefreshSettings();
}

void 		Settings::SetKeyboard(int type)
{
	type_keyboard = type;
	RefreshSettings();
}


void	   Settings::RefreshSettings()
{
	std::ofstream outfile (filename.c_str());
	outfile << diffuclt << std::endl;
	outfile << nb_ai << std::endl;
	outfile << map_x << std::endl;
	outfile << map_y << std::endl;
	outfile << nb_players << std::endl;
	outfile << restore_svg << std::endl;
	outfile << type_keyboard << std::endl;
	outfile.close();
}


void 	Settings::aff_settings()
{
	// std::cout << "Mode : " << diffuclt << std::endl;
	// std::cout << "nbr AI : " << nb_ai << std::endl;
	// std::cout << "Talle x " << map_x << " y " << map_y << std::endl;
	// std::cout << "nb player : " << nb_players << std::endl;
}

Settings::Difficulty Settings::GetDifficulty() { return (diffuclt); }
int		   Settings::GetNb_AI()  { return (nb_ai); }
int		   Settings::GetMapx() { return (map_x); }
int		   Settings::GetMapY() { return (map_y); }
int		 	Settings::GetNbPlayers() { return (nb_players); }
int 		Settings::GetSVG() { return (restore_svg); }
int 		Settings::GetTypeKeyboard() { return (type_keyboard); }