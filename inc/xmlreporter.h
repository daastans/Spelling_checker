#ifndef INC_XMLREPORTER_H
#define INC_XMLREPORTER_H

#include"reporter.h"

class XMLReporter:public Reporter
{
public:
  XMLReporter(std::ostream &os);
  void ReportHeader();
  void ReporterError(const std::string &word,const std::string &context ,unsigned int line ,const std::string &filename);
  void ReportFooter();
};

#endif
