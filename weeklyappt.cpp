#include "weeklyappt.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

const char* WeeklyAppointment::getSeries() const
{
  return series;
} // getSeries()s

int WeeklyAppointment::getSeriesCount() const 
{
  return seriesCount;
} // getSeriesCount() 

WeeklyAppointment::WeeklyAppointment(): series(""), seriesCount(0) 
{
}; // WeeklyAppointment()

WeeklyAppointment::~WeeklyAppointment()
{
} // ~WeeklyAppointment()

WeeklyAppointment* WeeklyAppointment::clone() const
{
  return new WeeklyAppointment(*this);
} //clone

WeeklyAppointment::WeeklyAppointment(const WeeklyAppointment &WeeklyAppt) : 
  Appointment(WeeklyAppt), 
  seriesCount(WeeklyAppt.seriesCount)
{
  strcpy(series, WeeklyAppt.series);
}  // WeeklyAppointment copy constructor

void WeeklyAppointment::read(istream& is)
{
  Appointment::read(is);
  char line[80] = "";
  int count = 0;

  is.getline(line, 80, ',');
  strcpy(series, line);

  is.getline(line, 80, '\n');
  count = atoi(line);
  seriesCount = count;

} // read() for weekly Appt

void  WeeklyAppointment::write(ostream& os) const
{
  Appointment::write(os);           
  os << setw(8) <<  series << left  << "(" <<  seriesCount << ")";
} // write()
