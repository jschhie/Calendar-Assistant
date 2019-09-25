#ifndef WEEKLY_APPT_H
#define WEEKLY_APPT_H

#include "appt.h"

using namespace std;

class WeeklyAppointment: public Appointment 
{
  char series[8];
  int seriesCount;
public:
  const char* getSeries() const;
  int getSeriesCount() const;
  WeeklyAppointment();  
  ~WeeklyAppointment(); 
  WeeklyAppointment(const WeeklyAppointment &weeklyAppt);
  virtual WeeklyAppointment* clone() const;
  virtual void read(istream& is); 
  virtual void write(ostream& os) const;
}; // class WeeklyAppointment 




#endif // WEEKLY_APPT_H
