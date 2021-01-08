#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>

#include "calendar.h"

using namespace std;

Calendar::Calendar(): days(30) {} // create()

void Calendar::addAppointment()
{
  int pos, day, month, year;
  getDate(&day, &month, &year);
  Day dayTemp (day, month, year); 
  pos = days += dayTemp; 
  days[pos].addAppointment();
    
}  // addAppointment()


void Calendar::dateSearch() const
{
  int day = -1, month = -1, year = -1;
  getDate(&day, &month, &year);
  Day dayTemp(day, month, year);
  
  for(int i = 0; i < days.getCount(); i++)
    if(days[i] ==  dayTemp)
    {
      cout << days[i];
      return;
    } // if found matching date
  
  cout << "That date was not found.\n";
}  // dateSearch()


void Calendar::getDate(int *day, int *month, int *year) const
{
  while(1)
  {
    char line[80], line2[80], *ptr;
    cout << "\nPlease enter the month, day, and year (mm/dd/yyyy) >> ";
    
    if (! fgets(line, 80, stdin))
      cout << " is not a valid date.\nPlease try again.\n";
    else // User entered something
    {
      strtok(line, "\n");
      strcpy(line2, line);
      ptr = strtok(line, "/");
      
      if(ptr)
      {
        *month = atoi(ptr);
        ptr = strtok(NULL, "/");
        
        if(ptr)
        {
          *day = atoi(ptr);
          ptr = strtok(NULL, "\n");
          
          if(ptr)
            *year = atoi(ptr);
        } // if something before a second /
      } // if something before the first /
      
      if(*day >= 1 && *day <= 31 && *month >= 1 && *month <= 12 
         && *year >= 1000 && *year <= 2017)
         break;
      
      cout << line2 << " is not a valid date.\nPlease try again.\n";
    } // else use entered something
  } // while invalid date
}  // getDate()


istream& operator>> (istream &is, Calendar &calendar)
{
  char line[80];
  int day, month, year, pos;
  is.getline(line, 80);  // get rid of label line;
  
  while(is.getline(line, 80, '/'))
  {
    month = atoi(line);
    is.getline(line, 80, '/');
    day = atoi(line);
    is.getline(line, 80, ',');
    year = atoi(line);
    
    Day dayTemp(day, month, year); 
    pos = calendar.days += dayTemp;
    
    const WeeklyAppointment *weeklyAppt = 
    dynamic_cast<const WeeklyAppointment*>(is >> calendar.days[pos]);

    if (weeklyAppt)
    {
      calendar.createSeries(*(weeklyAppt), 
      calendar.days[pos].getDay(), calendar.days[pos].getMonth(),
      calendar.days[pos].getYear());
    } // dynamic cast
  } // while more lines in the file
  
  return is;
}  // operator>> ()


void Calendar::subjectSearch() const
{
  char subject[80];
  cout << "Please enter the subject >> ";
  fgets(subject, 80, stdin);
  
  if(strlen(subject) > 0)
    subject[strlen(subject) - 1] = '\0';  // eliminate the '\n'
  
  string header = "Date                          Start End   Subject      Location";
  cout << header << endl << string(80, '-') << endl;

  for(int i = 0; i < days.getCount(); i++)
    days[i].subjectSearch(subject);
  
  cout << "\n";
}  // subjectSearch()


void Calendar::createSeries(WeeklyAppointment wk, int day, int month, int year)
{
  ifstream inf("../refs/DOW.dat", ios::binary); // Include filepath
  int i = 1, pos = 0;
  
  while (i < wk.getSeriesCount())
  {
    day++;

    if(day > 31) 
    { 
      month++;
      
      if (month <= 12)
        day = 1;

      else // reset all 
        date(&month, &day, &year);
    
    } // not valid date

    dayOfWeek dayOfWeek2(month, day, year);
    inf >> dayOfWeek2;

    for(unsigned int j = 0; j < strlen(wk.getSeries()); j++) 
    {
      if (dayOfWeek2 == wk.getSeries()[j]) 
      {
        Day dayTemp(day, month, year);
        pos = days += dayTemp;
        days[pos] += wk;
        i++;
      } // if   
    } // loop through series
  } // while i < seriesCount

  inf.close();	
} // createSeries()


void Calendar::date(int *month, int *day, int *year)
{
  *month = 1;
  *day = 1;
  *year += 1;
} // date()
