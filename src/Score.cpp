//
// Score.cpp for Score in /home/haulot_a//C++/Bomber-Man/svn_bomberman/bomberman-2015-haulot_a
// 
// Made by alexandre haulotte
// Login   <haulot_a@epitech.net>
// 
// Started on  Wed May 30 11:55:05 2012 alexandre haulotte
// Last update Fri Jun  1 13:17:49 2012 yuguo cao
//

#include	"Score.hh"
#include 	"Utils.hh"
#include	<iostream>
Score::Score()
{
  filename = "HScore.html";

  std::string buff;
  std::ifstream infile;
  int		i = 0;

  if(!std::ifstream(filename.c_str()))
    {
      std::cout << "file does not exist" << std::endl;
      std::ofstream outfile (filename.c_str());
      outfile << "<html>" << std::endl;
      outfile << "<header>" << std::endl;
      outfile << "<title>The Best BomberMan</title>" << std::endl;
      outfile << "</header>" << std::endl;
      outfile << "<body style='background-color:ff9c00; text-align:center; font-size:2em'>" << std::endl;
      outfile << "<br/><h1>The Best Score Is :</h1><br/>" << std::endl;
      outfile << "<h2>First : " << std::endl;
      outfile << 0 << std::endl;
      outfile << "</h2>" << std::endl;
      outfile << "<h2> Second :" << std::endl;
      outfile << 0 << std::endl;
      outfile << "</h2>" << std::endl;
      outfile << "<h2> Third :" << std::endl;
      outfile << 0 << std::endl;
      outfile << "</h2>" << std::endl;
      outfile << "</body>" << std::endl;
      outfile << "</html>" << std::endl;
      outfile.close();
    }

  infile.open(filename.c_str());

  for (i = 0; i < 7 ; i++)
    getline(infile,buff);

  if (infile.good())
    {
      getline(infile,buff);
      H1score = to_number<int>(buff);
    }
  getline(infile,buff);
  getline(infile,buff);
  if (infile.good())
    {
      getline(infile,buff);
      H2score = to_number<int>(buff);
    }
  getline(infile,buff);
  getline(infile,buff);
  if (infile.good())
    {
      getline(infile,buff);
      H3score = to_number<int>(buff);
    }
}

int   Score::checkScore(int sc)
{
  if (sc > H3score)
    {
      std::ofstream outfile (filename.c_str());
      outfile << "<html>" << std::endl;
      outfile << "<header>" << std::endl;
      outfile << "<title>The Best BomberMan</title>" << std::endl;
      outfile << "</header>" << std::endl;
      outfile << "<body style='background-color:ff9c00; text-align:center; font-size:2em'>" << std::endl;
      outfile << "<br/><h1>The Best Score Is :</h1><br/>" << std::endl;
      if (sc > H1score)
	{
	  outfile << "<h2>First : " << std::endl;
	  outfile << sc << std::endl;
	  outfile << "</h2>" << std::endl;
	  outfile << "<h2> Second :" << std::endl;
	  outfile << H1score << std::endl;
	  outfile << "</h2>" << std::endl;
	  outfile << "<h2> Third :" << std::endl;
	  outfile << H2score << std::endl;
	  outfile << "</h2>" << std::endl;
	}
      else if (sc > H2score)
	{
	  outfile << "<h2>First : " << std::endl;
	  outfile << H1score << std::endl;
	  outfile << "</h2>" << std::endl;
	  outfile << "<h2> Second :" << std::endl;
	  outfile << sc << std::endl;
	  outfile << "</h2>" << std::endl;
	  outfile << "<h2> Third :" << std::endl;
	  outfile << H2score << std::endl;
	  outfile << "</h2>" << std::endl;
	}
      else if (sc > H3score)
	{
	  outfile << "<h2> First : " << std::endl;
	  outfile << H1score << std::endl;
	  outfile << "</h2>" << std::endl;
	  outfile << "<h2> Second :" << std::endl;
	  outfile << H2score << std::endl;
	  outfile << "</h2>" << std::endl;
	  outfile << "<h2> Third :" << std::endl;
	  outfile << sc << std::endl;
	  outfile << "</h2>" << std::endl;
	}
      outfile << "</body>" << std::endl;
      outfile << "</html>" << std::endl;
      outfile.close();
    }
  return (0);
}

Score::~Score()
{}
