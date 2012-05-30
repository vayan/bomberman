#include "Move.hh"


Move::Move()
{

}

Move::~Move()
{

}

bool  	Move::InMap(int new_x, int new_y, Player *pl, Level *lvl)
{
	std::map<int, std::map<int, char> > map = lvl->getMap();

	if (new_x < 0 || new_y < 0 || new_x >= lvl->getHeight() || new_y >= lvl->getWidth())
		return (false);
	return (true);
}

bool 	Move::TryMoveY(int new_y, Level *lvl, Player *pl)
{
	std::map<int, std::map<int, char> > map = lvl->getMap();

	if (map[pl->getX()][new_y] == 'f')
		return (true);
	return (false);	
}

bool 	Move::TryMoveX(int new_x, Level *lvl, Player *pl)
{
	std::map<int, std::map<int, char> > map = lvl->getMap();

	if (map[new_x][pl->getY()] == 'f')
		return (true);
	return (false);	
}

bool 	Move::TryMove(int new_x, int new_y, Player *pl, Level *lvl, std::list<AObject*> all_obj)
{
	std::list<AObject*>::iterator it;

	if (new_y != pl->getY() && new_x != pl->getX())
		return (false);
	if (InMap(new_x, new_y, pl, lvl) == false)
		return (false);
	// for (it = all_obj.begin(); it != all_obj.end(); it++)
	//     {
	//     	if (((*it)->_type > 1) && (new_x == (*it)->getX()) && (new_y == (*it)->getY()))
	// 			return (false);
	// 	}
	if (new_y != pl->getY())
		return (TryMoveY(new_y, lvl, pl));
	return (TryMoveX(new_x, lvl, pl));
}


