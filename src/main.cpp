#include<iostream>
#include<string>
#include "dictionary.h"

int main()
{
  std::cout<<"scheck v1.0"<<std::endl;
  Dictionary d("data/mydict.dat");
  std::string word="dog";
  while(getline(std::cin,word))
  {
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
