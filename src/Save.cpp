#include "Save.hh"


Save::Save()
{
	filename = "save.bm";
}

void 	Save::SaveFile(Level *lvl, std::list<AObject*> all_obj)
{
	std::list<AObject*>::iterator it;

	std::ofstream outfile (filename.c_str());
	outfile << "###MAP####" << std::endl;
	outfile << lvl->pack() << std::endl;
	outfile << "###OBJ####" << std::endl;
	for (it = all_obj.begin(); it != all_obj.end(); it++)
	{
		switch ((*it)->_type)
		{
			case 2:
			outfile <<  static_cast<Player*>((*it))->pack() << std::endl; break;
			case 3:
			break;
		}
	}
	outfile.close();
}

std::string Save::GetLvl()
{
	std::string buff = "";
	std::ifstream infile;

	infile.open(filename.c_str());

	if (infile.good())
		getline(infile,buff);
	if (infile.good())
		getline(infile,buff);
	return (buff);
}

std::string 	Save::GetFilename() { return (filename); }

Save::~Save() 
{

}

void	Save::restore()
{


}