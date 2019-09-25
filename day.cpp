// Author: Sean Davis

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "day.h"
#include "appt.h"
#include "DayOfWeek.h"
#include "weeklyappt.h"

using namespace std;

Day::Day()
{
}  // Day()


Day::Day(int day1, int month1, int year1) : day(day1), month(month1), 
  year(year1)
{
}  // Day(int, int, int)


void Day::addAppointment()
{
  Appointment *appointment = new Appointment();
  appointment->addAppointment();
  appts += appointment;
}  // addAppointment()

Day& Day::operator+= (const WeeklyAppointment &weeklyAppt)
{
  appts += new WeeklyAppointment(weeklyAppt);
  return *this; 
} // operator+= ()


bool Day::operator== (const Day &day2) const
{
  return day == day2.day && month == day2.month 
    && year == day2.year;
} // operator== ()


bool Day::operator< (const Day &day2) const
{
  return (year < day2.year)
    || (year == day2.year && month < day2.month)
    || (year == day2.year && month == day2.month 
      && day < day2.day); 
} // operator< ()



Day& Day::operator= (const Day &rhs) 
{
  if(this == &rhs)
    return *this;
  
  day = rhs.day;
  month = rhs.month;
  year = rhs.year;
  appts = rhs.appts;
  return *this;
}  // operator= ()


ostream& operator<< (ostream &os, const Day &day)
{
  os << "Start End   Subject      Location\n";
  os << day.appts;
  os << "\n";
  return os;
} // operator<< ()


const Appointment* operator>> (istream &is, Day &day)
{
  char line[80];
  int typeAppt;

  is.getline(line, 80, ',');
  typeAppt = atoi(line);

  if (typeAppt == 0)
  {
    Appointment *appointment = new Appointment;
    is >> *appointment;
    is.getline(line, 80, '\n');
    day.appts += appointment;   
    return appointment;
  } // normal appt
  
  else // typeAppt == 1  
  {
    WeeklyAppointment *weeklyAppt = new WeeklyAppointment; 
    is >> *weeklyAppt;
    day.appts += weeklyAppt;
    return weeklyAppt;
  } // else
} // operator>> ()

void Day::subjectSearch(const char *subject) const
{
  const Appointment *appointmentPtr;
  
  while((appointmentPtr = appts.find(subject)))
  {
    ifstream inf("DOW.dat", ios::binary);
    DayOfWeek dayOfWeek(month, day, year);
    inf >> dayOfWeek;
    cout << dayOfWeek;
    cout << *appointmentPtr;
    inf.close();
  } // if appointment has the subject
} // subjectSearch()

int Day::getDay() const { return day; } //getDay

int Day::getMonth() const { return month; } //getMonth

int Day::getYear() const { return year; } //getYear
