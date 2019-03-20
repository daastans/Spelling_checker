#ifndef INC_SCHECK_PARSER_H
#define INC_SCHECK_PARSER_H

#include <string>
#include <iostream>

class Parser
{
private:
  std::istream &mSubmission;//reference is needed since stream  objects cannot be copied
public:
  Parser(std::istream &is);
  std::string NextWord();
  unsigned int LineNo() const;
  std::string Context() const;
};

#endif
