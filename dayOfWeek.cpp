#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include "dayOfWeek.h"

using namespace std;

dayOfWeek::dayOfWeek(int month1, int day1, int year1) : month(month1), 
  day(day1), year(year1)
{
} // dayOfWeek() constructor


bool dayOfWeek::operator== (char c) const 
{
  switch (c)
  {
    case 'M':
      return (strcmp(dayName, "Monday") == 0);
    case 'T':
      return (strcmp(dayName, "Tuesday") == 0);
    case 'W':
      return (strcmp(dayName, "Wednesday") == 0);
    case 'R':
      return (strcmp(dayName, "Thursday") == 0);
    case 'F':
      return (strcmp(dayName, "Friday") == 0);
    case 'S':
      return (strcmp(dayName, "Saturday") == 0);
    case 'U':
      return (strcmp(dayName, "Sunday") == 0);
    default: 
      return false;
  } // Compares MTWRFSU with dayName
} // dayOfWeek overloaded operator


ostream& operator<< (ostream &os, const dayOfWeek &dayOfWeekRef)
{
  char line[80], dayStr[3], yearStr[10];
  strcpy(line, dayOfWeekRef.dayName);
  strcat(line, ", ");
  strcat(line, dayOfWeekRef.monthName);
  strcat(line, " ");
    
  if(dayOfWeekRef.day > 9)
  {
    dayStr[0] = dayOfWeekRef.day / 10 + '0';
    dayStr[1] = dayOfWeekRef.day % 10 + '0';
    dayStr[2] = '\0';
  } // if day > 9
  else // day < 10
  {
    dayStr[0] = dayOfWeekRef.day + '0';
    dayStr[1] = '\0';
  } // else day < 10
  
  strcat(line, dayStr);
  strcat(line, ", ");
   
  int copyYear = dayOfWeekRef.year / 1000;
  
  yearStr[0] = copyYear + '0';
  yearStr[1] = ( (dayOfWeekRef.year / 100) - (copyYear * 10) ) + '0';
  yearStr[2] = ( (dayOfWeekRef.year / 10 ) % 10) + '0';
  yearStr[3] = dayOfWeekRef.year % 10 + '0';
  yearStr[4] = '\0';

  strcat(line, yearStr);

  os << left << setw(30) << line << right;

  return os;

}  // operator<<


istream& operator>> (istream &is, dayOfWeek &dayOfWeekPtr) // NOTE: Changed day -> dayOfWeekPtr
{
  int dateNumber = (dayOfWeekPtr.month - 1) * 31 + dayOfWeekPtr.day - 1 + (dayOfWeekPtr.year - 1990) * 372;
  is.seekg(dateNumber * sizeof(dayOfWeek));
  is.read((char*) &dayOfWeekPtr, sizeof(dayOfWeek));
  return is;
}  // operator>>
