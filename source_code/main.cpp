/* Driver Program for User-Friendly Calendar
 * Created in Spring 2017
 */
#include <iostream>
#include <fstream>
#include <string>

#include "calendar.h"

using namespace std;

int getChoice()
{
  int choice = 0;
  char line[80];
  
  while(1)
  {
    // Center header and add borders to Menu
    int numReps = 80;
    cout << string(numReps, '=') << endl;
    string header = "Calendar Assistant Menu\n";
    int numSpaces = (numReps - header.size()) / 2;
    cout << string(numSpaces, ' ') << header;
    cout << string(numReps, '-') << endl;
    // Display choices
    cout << "0. Exit and save calendar.\n";
    cout << "1. Search for date.\n";
    cout << "2. Search for subject (case sensitive).\n";
    cout << "3. Add an appointment.\n";
    cout << "4. Print appointment count.\n";
    cout << string(numReps, '=') << endl;

    // Get user choice
    cout << "\nYour choice >> ";
    cin >> choice;
    
    if (choice >= 0 && choice < 5)
      break;
    else
      cout << "Choice must be between 0 and 4. Please try again.\n\n";
  }  // while invalid choice

  cin.getline(line, 80);
  return choice;

} // getChoice()


int printPrompt()
{
  // Center header and add borders
  int numReps = 80;
  cout << string(numReps, '*') << endl;
  string header = "About Calendar Assistant\n";
  int numSpaces = (numReps - header.size()) / 2;
  cout << string(numSpaces, ' ') << header << endl;
  cout << "Usage: ./calendar.out <filePath/weeklyAppts.csv>\n";
  cout << "\n'weeklyAppts.csv' needs the following format and heading:\n";
  cout << "Date,Class,Subject,Start Time,End Time,Location,Series,Count\n";
  cout << string(numReps, '*') << endl << endl;
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
      case 1: 
        calendar.dateSearch(); 
        break;
      case 2: 
        calendar.subjectSearch(); 
        break;
      case 3: 
        calendar.addAppointment(); 
        break;
      case 4: 
        cout << "Appointment count: " << Appointment::getCount()  << "\n\n";
        break;
    }  // switch
    
    choice = getChoice();
  } 

  return 0;
} // main()

