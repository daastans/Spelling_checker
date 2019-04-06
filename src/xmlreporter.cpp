#include "xmlreporter.h"
#include <string>

static const std::string ToXML(const std::string &s)
{
  std::string xml;
  for(unsigned int i=0;i<s.size();i++)
  {
    xml+=s[i];
  }
  return "\t<td>"+xml+"</td>\n";
}
XMLReporter::XMLReporter(std::ostream &os):Reporter(os){}
void XMLReporter::ReportHeader(){Out()<<"<table>\n";}
void XMLReporter::ReportFooter(){Out()<<"</table>\n";}
void XMLReporter::ReporterError(const std::string &word,const std::string &context ,unsigned int line ,const std::string &filename)
{
  Out()<<"<tr>\n"<<ToXML(word)<<ToXML(context)<<"\t<td>"<<line<<"</td>\n"<<ToXML(filename)<<"</tr>\n";
}
