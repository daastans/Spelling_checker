#ifndef INC_COMMANDLINE_H
#define INC_COMMANDLINE_H
#include<string>
#include<vector>

class CommandLine
{
public:
  CommandLine(int argc,char* argv[]);
  bool HasOption(const std::string& option);
  bool ExtractOptions(const std::string& option);
  bool ExtractOptions(const std::string& option,std::string& value);
  bool MoreOptions() const;
  int Argc() const;
  std::string Argv(unsigned int i) const;
private:
  typedef std::vector<std::string> ArgVector;
  typedef ArgVector::iterator Iter;
  Iter FindOption(const std::string& option);
  ArgVector mArgs;
};
#endif
