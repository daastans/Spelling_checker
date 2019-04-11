#include<iostream>
#include<string>
#include<memory>
#include "dictionary.h"
#include "parser.h"
#include "error.h"
#include "csvreporter.h"
#include "xmlreporter.h"
#include "commandline.h"
#include "settings.h"

Reporter* MakeReporter(Settings::Report rt)
{
  if(rt==Settings::inCSV)
    return new CSVReporter(std::cout);
  else if(rt==Settings::inXML)
    return new XMLReporter(std::cout);
  else
    throw ScheckError("Invalid Report Type\n");
}
void CheckSubmission(const Dictionary& dict,std::ifstream& sub,const std::string & subname ,Reporter& rep)
{
  Parser p(sub);
  std::string word;
  rep.ReportHeader();
  while((word=p.NextWord())!="")
  {
    if(!dict.check(word))
      rep.ReporterError(word,p.Context(),p.LineNo(),subname);
  }
  rep.ReportFooter();
}
int main(int argc,char *argv[])
{
  try
  {
    std::string dict;
    std::string filename="data/text.txt";
    std::cout<<"scheck v1.0"<<std::endl;
    std::ifstream sub("data/test.txt");
    if(!sub.is_open())
    {
      throw ScheckError("could not open data/test.txt");
    }
    Parser p(sub);
    CommandLine cmdl(argc,argv);
    Settings s(cmdl);

    std::unique_ptr <Reporter>rep(MakeReporter(s.ReportType()));
    Dictionary d(s.DictName());
    CheckSubmission(d,sub,filename,*rep);



  }
  catch (const ScheckError &e )
  {
    std::cerr<<"Error "<<e.what()<<std::endl;
    return 1;
  }
  catch(...)
  {
    std::cerr<<"Error: unknown exception "<<std::endl;
    return 2;
  }

}
