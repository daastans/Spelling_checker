#ifndef INC_CSVREPORTER_H
#define INC_CSVREPORTER_H

class CSVReporter:public Reporter
{
  CSVReporter(std::ostrem& os);
  void ReportHeader();
  void ReporterError(const std::string &word,const std::string context ,unsinged int line ,const std::string &filename);
  void ReportFooter();
};



#endif
