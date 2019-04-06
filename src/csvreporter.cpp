#include "csvreporter.h"
#include<string>

static const std::string ToCSV(const std::string& s) //defined static since it has no use outside this file
{
  std::string csv;
  for(unsigned int i=0;i<s.size();i++)
  {
    if(s[i]=='"')
    {
      csv+='"';
    }
    csv+=s[i];
  }
  return '"'+csv+'"';
}
CSVReporter::CSVReporter(std::ostream &os):Reporter(os){ }
void CSVReporter::ReportHeader(){Out()<<"word,context,line,file\n";}
void CSVReporter::ReporterError(const std::string &word,const std::string &context ,unsigned int line ,const std::string &filename)
{
  Out()<<ToCSV(word)<<','<<ToCSV(context)<<","<<'"'<<line<<'"'<<','<<ToCSV(filename)<<"\n";
}
void CSVReporter::ReportFooter(){}
