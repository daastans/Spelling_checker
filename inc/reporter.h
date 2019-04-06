#ifndef INC_REPORTER_H
#define INC_REPORTER_H
#include<string>
#include<ostream>

class Reporter
{
public:
  Reporter(std::ostream &os):mOut(os){}
  virtual ~Reporter(){}
  virtual void ReportHeader()=0;
  virtual void ReporterError(const std::string &word,const std::string &context,unsigned int line,const std:: string &filename)=0;
  virtual void ReportFooter()=0;
protected:
  std::ostream& Out(){return mOut;}
private:
  std::ostream& mOut;//protected data members are bad idea , they can be made exposed so i made it private and made it assesible through protected function.

};
/* The interface implemented by CSV or XML is ReportHeader() , ReporterError() , ReportFooter() notice that they have been declared Pure virtual function meaning they must be implemented by derive class.if one or more pure virtual functions are present in calss we call it abstract base class These classes can only be derived and not instantiated(meaning creating their objects)*/
#endif
