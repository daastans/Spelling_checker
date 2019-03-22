#include "parser.h"
#include "error.h"

Parser::Parser(std::istream &is ):mSubmission(is),mLineNo(0){}//since streams cannot be assigned we use initialiser list here
unsigned int Parser:: LineNo() const
{
  return mLineNo;
}
std::string Parser :: Context() const
{
  return mLine;
}
bool Parser:: ReadLine()
{
  if(getline(mSubmission,mLine))
  {
    mIs.clear();
    mIs.str(mLine);
    mLineNo++;
    return true;
  }
  else if(mSubmission.eof())
  {
    return false;
  }
  else
    throw ScheckError("Errror in reading stream");
}
std::string Parser:: NextWord()
{
  std::string word;
  if(mIs>>word)
  {
    return word;
  }
  else if(mIs.eof())
  {
    if(ReadLine())
    {
      return NextWord();
    }
    else
    {
      return "";
    }
  }
  else
  {
    throw ScheckError("read error");
  }
}
