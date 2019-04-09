#ifndef INC_SETTINGS_H
#define INC_SETTINGS_H
#include<string>
#include "commandline.h"
#include "reporter.h"
#include "error.h"
class Settings
{
public:
  enum Report { inCSV , inXML};
  Settings(CommandLine& cmdl);
  Report ReportType() const;
  std::string DictName() const;
private:
  Report mReportType;
  std::string mDictName;
};
#endif
