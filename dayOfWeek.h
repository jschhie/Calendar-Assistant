#ifndef DAYOFWEEK_H
#define	DAYOFWEEK_H

#include <iostream>
using namespace std;

class dayOfWeek 
{

  char monthName[10];
  int month;
  int day;
  int year;
  char dayName[10];

public:

  dayOfWeek(int mon, int day1, int year1);
  bool operator== (char c) const;
  friend istream& operator>> (istream &is, dayOfWeek &day); 
  friend ostream& operator<< (ostream &os, const dayOfWeek &day); 

}; // class dayOfWeek

#endif	// DAYOFWEEK_H
