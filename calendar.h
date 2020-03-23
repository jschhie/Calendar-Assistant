#ifndef CALENDAR_H
#define	CALENDAR_H

#include "appt.h"
#include "day.h"
#include "dayOfWeek.h"
#include "vector.h"
#include "weeklyAppt.h"

class Calendar
{

  Vector<Day>days; 

public:

  Calendar();
  void addAppointment();
  void dateSearch() const;
  void getDate(int *day, int *month, int *year) const;
  friend istream& operator>> (istream &is, Calendar &calendar); 
  void subjectSearch() const;
  void createSeries(WeeklyAppointment weeklyAppt, 
                    int day, int month, int year);
  void date(int *month, int *day, int *year);

};  // class Calendar

#endif	// CALENDAR_H
