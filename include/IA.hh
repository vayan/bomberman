#ifndef __IA_HH__
#define __IA_HH__

#include "Level.hh"
#include "Player.hh"

class Player;

class  IA
{
private:
  int			level;
  int			escape;
  int			wait;
  int			time_wait;
  bool			allies;
  int			i;
  int			x;
  int			y;
  char			prev;
  char			last;
  Player		*_pl;
  std::list<AObject*>	object;
  int			oldDir;
public:
  IA(int level, Player *pl);
  ~IA();

  void	IA_moves(Level *lv, const std::list<AObject*>& all_object);
  // Map pas const car on ne peut pas faire appel à [][]
  void	prev_move(std::map<int, std::map<int, char> >& map, Level *lv);
  int	see_left(std::map<int, std::map<int, char> >& map, Level *lv);
  int	see_up(std::map<int, std::map<int, char> >& map, Level *lv);
  int	see_down(std::map<int, std::map<int, char> >& map, Level *lv);
  int	see_right(std::map<int, std::map<int, char> >& map, Level *lv);
  int	search_bomb(std::map<int, std::map<int, char> >& map, Level *lv);

  enum level
    {
      EASY,
      HARD,
      INFERNO
    };
};

#endif
