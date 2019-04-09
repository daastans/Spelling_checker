#include "commandline.h"

CommandLine::CommandLine(int argc,char* argv[])
{
  for(int i=0;i<argc;i++)
  {
    mArgs.push_back(argv[i]);
  }
}
bool CommandLine::HasOption(const std::string& option)
{
  for(Iter ptr=mArgs.begin();ptr<mArgs.end();ptr++)
  if(*ptr==option)    return true;
  return false;
}
bool CommandLine::MoreOptions() const
{
  if(Argc()>1) return true;
  else return false;
}
int CommandLine::Argc() const {return mArgs.size();}
std::string CommandLine::Argv (unsigned int i) const {return mArgs.at(i);}

CommandLine::Iter CommandLine::FindOption(const std::string& option)
{
  for(int i=1;i<Argc();i++)
  {
    if(option==Argv(i))
    return mArgs.begin()+i;
  }
  return mArgs.end(); //end() returns after end position in vector
}
bool CommandLine::ExtractOptions(const std::string& option, std::string &value)
{
  Iter position=FindOption(option);
  if(position!=mArgs.end() && position!=mArgs.end()-1)
  {
    value=*(position+1);
    mArgs.erase(position,position+2);
    return true;
  }
  else
    return false;
}
bool CommandLine::ExtractOptions(const std::string& option)
{
  Iter position=FindOption(option);
  if(position!=mArgs.end())
  {
    mArgs.erase(position,position+1);
    return true;
  }
  else
    return false;
}
