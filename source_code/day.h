#ifndef DAY_H
#define	DAY_H

#include <iostream>

#include "appt.h"
#include "dayOfWeek.h"
#include "linkedlist.h"
#include "vector.h"
#include "weeklyAppt.h"

using namespace std;

class Day
{

  short day;
  short month;
  short year;
  LinkedList<Appointment*>appts; 

public:

  Day();
  Day(int day1, int month, int year);
  void addAppointment();
  Day& operator+= (const WeeklyAppointment &weeklyAppt);
  bool operator== (const Day &day2) const;
  bool operator< (const Day &day2) const;
  Day& operator= (const Day &day);
  friend ostream& operator<< (ostream &os, const Day &day); 
  friend const Appointment* operator>> (istream &is, Day &day); 
  void subjectSearch(const char *subject) const;
  int getDay() const;
  int getMonth() const;
  int getYear() const;
}; // class Day

#endif	// DAY_H 
