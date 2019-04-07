#include<iostream>
#include<string>
#include<memory>
#include "dictionary.h"
#include "parser.h"
#include "error.h"
#include "csvreporter.h"
#include "xmlreporter.h"


int main(int argc,char *argv[])
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
    //Reporter* rep=0;
    std::unique_ptr <Reporter>rep;
    if(argc==1)
    {
      rep=std::unique_ptr<Reporter>(new CSVReporter(std::cout));
    }
    else
    {
      rep=std::unique_ptr<Reporter>(new XMLReporter(std::cout));
    }

    Dictionary d("data/mydict.dat");
    rep->ReportHeader();

    std::string word="dog";
    while ((word=p.NextWord())!="") {
      if(d.check(word))
      {
        //std::cout<<word<<" is ok!"<<std::endl;
      }
      else
      {
        //std::cout<<word<<" is Not present in Dictionary! at "<<p.LineNo()<<std::endl;
        rep->ReporterError(word,p.Context(),p.LineNo(),"data/test.txt");
      }

    }
    rep->ReportFooter();
    //delete rep;//since it is dynamically created its memory management is in our hands
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
