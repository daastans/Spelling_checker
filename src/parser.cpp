#include "parser.h"
#include "error.h"

Parser::Parser(std::istream &is ):mSubmission(is){}//since streams cannot be assigned we use initialiser list here
std::string Parser:: NextWord()
{
  std::string word;
  if(mSubmission>>word)
  {
    return word;
  }
  else if(mSubmission.eof())
  {
    return "";
  }
  else
  {
    throw ScheckError("read error");
  }
}
