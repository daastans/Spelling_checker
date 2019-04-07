/* This file is not in use in program it was just made for learning purposes*/

#ifndef INC_SMARTPOINTER_H
#define INC_SMARTPOINTER_H
#include "reporter.h"
class SmartPointer
{
public:
  SmartPointer(Reporter* rep):mPointer(rep){}
  Reporter* operator ->(){return mPointer;}
  ~SmartPointer(){delete mPointer;}
private:
  Reporter* mPointer;

};
#endif
