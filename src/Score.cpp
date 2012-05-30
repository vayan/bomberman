//
// Score.cpp for Score in /home/haulot_a//C++/Bomber-Man/svn_bomberman/bomberman-2015-haulot_a
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed May 30 11:55:05 2012 alexandre haulotte
// Last update Wed May 30 12:26:29 2012 alexandre haulotte
//

#include	"Score.hh"
#include 	"Utils.hh"

Score::Score()
{
  filename = "HightScore.scr.html";

  std::string buff;
  std::ifstream infile;
  int		i = 0;

  if(!std::ifstream(filename.c_str()))
    {
      std::ofstream outfile (filename.c_str());
      outfile << "<html>" << std::endl;
      outfile << "<header>" << std::endl;
      outfile << "<title>The Best BomberMan</title>" << std::endl;
      outfile << "</header>" << std::endl;
      outfile << "<body style='background-color:ff9c00; text-align:center; font-size:2em'>" << std::endl;
      outfile << "<br/><h1>The Best Score Is :</h1><br/>" << std::endl;
      outfile << "<h2>" << std::endl;
      outfile << 0 << std::endl;
      outfile << "</h2>" << std::endl;
      outfile << "</body>" << std::endl;
      outfile << "</html>" << std::endl;
      outfile.close();
    }

  infile.open(filename.c_str());

  for (i = 0; i < 6 ; i++)
    getline(infile,buff);

  if (infile.good())
    {
      getline(infile,buff);
      Hscore = to_number<int>(buff);
    }
}

int   Score::checkScore(int sc)
{
  if (sc > Hscore)
    {
      std::ofstream outfile (filename.c_str());
      outfile << "<html>" << std::endl;
      outfile << "<header>" << std::endl;
      outfile << "<title>The Best BomberMan</title>" << std::endl;
      outfile << "</header>" << std::endl;
      outfile << "<body style='background-color:ff9c00; text-align:center; font-size:2em'>" << std::endl;
      outfile << "<br/><h1>The Best Score Is :</h1><br/>" << std::endl;
      outfile << "<h2>" << std::endl;
      outfile << sc << std::endl;
      outfile << "</h2>" << std::endl;
      outfile << "</body>" << std::endl;
      outfile << "</html>" << std::endl;
      outfile.close();
    }
  return (0);
}

Score::~Score()
{}
