#include "settings.h"
#include "commandline.h"


const char* const DEF_DICT = "data/mydict.dat";
const char* const DICT_OPT = "-d";
const char* const CSV_OPT = "-csv";
const char* const XML_OPT = "-xml";

Settings::Settings(CommandLine& cmdl):mReportType(inCSV),mDictName(DEF_DICT)
{
  if(cmdl.HasOption(CSV_OPT)&&cmdl.HasOption(XML_OPT))
    throw ScheckError("Only one export format can be specified\n");
  if(cmdl.ExtractOptions(CSV_OPT))
    mReportType=inCSV;
  if(cmdl.ExtractOptions(XML_OPT))
    mReportType=inXML;
  cmdl.ExtractOptions(DICT_OPT,mDictName);
  //if(cmdl.MoreOptions())
    //throw ScheckError("Invalid command line\n");
}
Settings::Report Settings::ReportType() const {return mReportType;}
std::string Settings::DictName() const {return mDictName;}
