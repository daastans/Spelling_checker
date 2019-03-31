#ifndef INC_SCHECK_PARSER_H
#define INC_SCHECK_PARSER_H

#include <string>
#include <iostream>
#include<sstream>

class Parser
{
private:
  char NextChar();
  enum State {stInSpace , stInWord, stInNum };
  State mState;
  std::istream &mSubmission;//reference is needed since stream  objects cannot be copied
  bool ReadLine();
  std::istringstream mIs;
  unsigned int mLineNo,mPos;
  std::string mLine;
public:

  Parser(std::istream &is);
  std::string NextWord();
  unsigned int LineNo() const;
  std::string Context() const;
};

#endif
