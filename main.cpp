/* Driver Program for User-Friendly Calendar 
 * Written by Jennifer Chhie and Tammy Lee
 * Sean Davis provided the template header files and .csv
 */
#include <iostream>
#include <fstream>
#include "calendar.h"

using namespace std;

int getChoice()
{
  int choice = 0;
  char line[80];
  
  while(true)
  {
    cout << "Calendar Menu\n";
    cout << "0. Done\n";
    cout << "1. Search for date.\n";
    cout << "2. Search for subject. CASE SENSITIVE\n";
    cout << "3. Add an appointment.\n";
    cout << "4. Print appointment count.\n";
    cout << "\nYour choice >> ";
    cin >> choice;
    
    if(choice >= 0 && choice < 5)
      break;
    
    cout << "Choice must be between 0 and 4.  Please try again.\n\n";
  }  // while invalid choice
  
  cin.getline(line, 80);
  return choice;
} // getChoice()


int printPrompt()
{
  cout << "---------------------------------------------------------------------------\n";
  cout << "\nUsage: ./calendar.out <weeklyAppts.csv>";
  cout << "\nThis program allows users to search appointments based on dates/subject,\nadd weekly appointments, and tally total appointments.\n";
  cout << "\nInput file 'weeklyAppts.csv' must have the following format and heading:\nDate,Class,Subject,Start Time,End Time,Location,Series,Count\n";
  cout << "---------------------------------------------------------------------------\n\n";
  return 0;
} // printPrompt()

int main(int argc, char **argv) 
{
  // Program Initialization
  printPrompt();
  Calendar calendar;
  int choice;
  
  ifstream inf(argv[1]);
  inf >> calendar;
  inf.close();
  choice = getChoice();
  
  // Execute user's choice
  while(choice)
  {
    switch(choice)
    {
      case 1: calendar.dateSearch(); break;
      case 2: calendar.subjectSearch(); break;
      case 3: calendar.addAppointment(); break;
      case 4: 
        cout << "Appointment count: " << Appointment::getCount()  << "\n\n";
        break;
    }  // switch
    
    choice = getChoice();
  } 

  return 0;
} // main()

