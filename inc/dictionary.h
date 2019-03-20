#include<string>
#include<set>
#include <fstream>
#include"error.h"

class Dictionary
{
private:
  std::set<std::string> mWords;
public:
  Dictionary(const std::string &fname)
  {
    std::string word;
    std::ifstream wlist(fname);
    if(!wlist.is_open())
    {
      throw ScheckError(" could not open dictionary file" + fname);
    }
    else
    {
      std::cout<<fname<<" Dictionary Loaded"<<std::endl;
    }
    while(getline(wlist,word))
    {
      mWords.insert(word);
    }
    if ( ! wlist.eof() )
    {
       throw ScheckError( "Error reading dictionary file " + fname );
    }

  };
  bool check(const std::string &word) const
  {
    return mWords.find(word)!=mWords.end();
  };
};
