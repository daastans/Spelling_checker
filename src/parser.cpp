#include "parser.h"
#include "error.h"

Parser::Parser(std::istream &is ):mSubmission(is),mLineNo(0),mPos(0),mState(stInSpace){}//since streams cannot be assigned we use initialiser list here
unsigned int Parser:: LineNo() const
{
  return mLineNo;
}
std::string Parser :: Context() const
{
  return mLine;
}

bool Parser::ReadLine() {
    if (getline(mSubmission, mLine)) {
        mPos = 0;
        mLineNo++;
        mLine +=" ";
        return true;
    } else if (mSubmission.eof()) {
        return false;
    } else {
        throw
        ScheckError("file read error");
    }
}
std::string Parser:: NextWord()
{
  std::string word;
  while(char c=NextChar())
  {
    switch (mState) {
      case stInSpace:
      if(std::isalpha(c))
      {
        mState=stInWord;
        word+=c;
      }
      else if(std::isdigit(c))
      {
        mState=stInNum;
      }
      break;

    case stInWord:
    if(std::isalpha(c)||c=='\'')
    {
      word+=c;
    }
    else if(std::isdigit(c))
    {
      mState=stInNum;
    }
    else
    {
      mState=stInSpace;
      return word;
    }
    break;
    case stInNum:
    if(isalnum(c)||c=='\'')
    {
      word+=c;
    }
    else
    {
      mState=stInSpace;
      word="";
    }
    break;
    default:
    ScheckError("Bad State");break;
  }
}
return word;
}
char Parser::NextChar() {
    if (mPos >= mLine.size()) {
        if (!ReadLine()) {
            return 0;
        }

    }
    return mLine[mPos++];
}
