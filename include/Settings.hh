#ifndef __SETTINGS_
#define __SETTINGS_

#include <iostream>
#include <string>
#include <fstream>

// 1er ligne -> difficulty
// 2em ligne -> nb_ai
// 3em ligne -> map_x
// 4em ligne -> map_y
// 5em ligne -> nb de joueurs
// 6em ligne -> restore svg
// 7em ligne -> typekeyboard (1 azerty / 2 qwerty)

class Settings
{
public:
  enum Difficulty
    {
      Easy,
      Hard,
      Inferno
    };


  Difficulty	GetDifficulty() const;
  void 		aff_settings();
  int		GetNb_AI() const;
  int		GetMapx() const;
  int		GetMapY() const;
  int 		GetNbPlayers() const;
  int 		GetSVG() const;
  void 		SetSVG(int rest);
  void 		SetDifficulty(Difficulty);
  void		SetNb_AI(int);
  void		SetMapx(int);
  void		SetMapY(int);
  void    	SetKeyboard(int);
  void		SetNbPlayers(int);
  void	   	RefreshSettings();
  int     	GetTypeKeyboard() const;

  Settings();
  ~Settings();
private:
  std::string	filename;
  Difficulty 	diffuclt;
  int 		nb_ai;
  int		map_x;
  int		map_y;
  int 		nb_players;
  int 		restore_svg;
  int     	type_keyboard;
};

#endif
