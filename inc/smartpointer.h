/* This file is not in use in program it was just made for learning purposes*/

#ifndef INC_SMARTPOINTER_H
#define INC_SMARTPOINTER_H
#include "reporter.h"
template <typename T>
class SmartPointer
{
public:
  SmartPointer(T* rep):mPointer(rep){}
  T* operator ->(){return mPointer;}
  ~SmartPointer(){delete mPointer;}
private:
  T* mPointer;

};
#endif
