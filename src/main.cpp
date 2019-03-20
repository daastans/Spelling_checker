#include<iostream>
#include<string>
#include "dictionary.h"
#include "parser.h"
#include "error.h"

int main()
{
  try
  {
    std::cout<<"scheck v1.0"<<std::endl;
    std::ifstream sub("data/test.txt");
    if(!sub.is_open())
    {
      throw ScheckError("could not open data/test.txt");
    }
    Parser p(sub);

    Dictionary d("data/mydict.dat");

    std::string word="dog";
    while ((word=p.NextWord())!="") {
      if(d.check(word))
      {
        std::cout<<word<<" is ok!"<<std::endl;
      }
      else
      {
        std::cout<<word<<" is Not present in Dictionary!"<<std::endl;
      }

    }
  }
  catch (const ScheckError &e )
  {
    std::cerr<<"Error "<<e.what()<<std::endl;
    return 1;
  }
  catch(...)
  {
    std::cerr<<"Error: unknown exception"<<std::endl;
    return 2;
  }

}
