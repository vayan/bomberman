#ifndef __SAVE_HH
#define __SAVE_HH

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <fstream>

#include "Object.hh"


class Save
{
public:
  Save();
  ~Save();

  void 		SaveFile(Level *lvl, std::list<AObject*> &objects_);
  std::string	GetLvl() const;
  std::string	GetFilename() const;
  void		restore();
private:
  std::string	filename;

};

#endif
