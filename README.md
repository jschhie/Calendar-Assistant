# Calendar Assistant

## Project Overview
This project was designed to help students keep track of their academic schedules. It assists users in creating and finding events and arranges weekly appointments. Its implementation makes use of templated polymorphism, doubly-linked lists, vectors, and operator overloading. 

A visual demo can be found [here](https://github.com/jschhie/calendar-prog/blob/master/README.md#visual-demo).


## Table of Contents
* [How to Use](https://github.com/jschhie/calendar-prog/blob/master/README.md#how-to-use)
  * [Creating Executable](https://github.com/jschhie/calendar-prog/blob/master/README.md#creating-executable)
  * [Command Line Arguments I](https://github.com/jschhie/calendar-prog/blob/master/README.md#command-line-arguments-i)
  * [Command Line Arguments II](https://github.com/jschhie/calendar-prog/blob/master/README.md#command-line-arguments-ii)
 * [Program Functionalities](https://github.com/jschhie/calendar-prog/blob/master/README.md#usage)
  * [Remark on User Input](https://github.com/jschhie/calendar-prog/blob/master/README.md#remark-on-user-input)
* [Visual Demo](https://github.com/jschhie/calendar-prog/blob/master/README.md#visual-demo)


## How to Use


### Creating Executable
For convenience, the corresponding ```Makefile``` has been provided. Assuming the user is inside the source_code directory, they can use the ```make all``` command, which will generate an executable called ```calendar.out```.

### Command Line Arguments I
This program can be run as-is (i.e., ```./calendar.out```); here, the program will not be initialized with any events.


### Command Line Arguments II 
Alternatively, the user can supply a comma-separated-values (CSV) file as a command line argument (e.g., ```./calendar.out filePath/weeklyAppts.csv```). In this case, the program will be initialized with custom events prior to runtime.

The CSV file should contain a list of appointments and have the following format *and* heading:
> Date,Class,Subject,Start Time,End Time,Location,Series,Count.


#### CSV Entries
| CSV Entry Label   | Expected Format     | Example           |
| ----------------- | -----------------   | -------           |
| Date              | MM/DD/YYYY          | ```08/09/2012```        |
| Class             | A digit             | ```0```                 |
| Subject           | Any string          | ```Spanish```           |
| Start/End Time    | HH:MM:SS AM/PM      | ```10:10:00 AM```       |
| Location          | Any string          | ```150 Wellman Hall```  |
| Series            | String in all CAPS  | ```SMTWRFU```           |
| Count             | A digit             | ```7```                 |


<details>
 <summary><b>Show Notes</b></summary>
 <dl>
  <dt> Abbreviations </dt>
  <dd> S - Saturday, M - Monday, T - Tuesday, W - Wednesday, R - Thursday, F - Friday, and U - Sunday. </dd>
  <dt> Adding Non-Weekly Events </dt>
  <dd> The user can either (1) leave both the "Series" and "Count" blank, 
   or (2) provide both, so that "Series" is a single character and "Count" is 1. </dd>
 </dl>
</details>

## Usage

While runnning the program, you are presented five options in the "Calendar Menu": 
> (0) Exit and save calendar events, (1) Search for date, (2) Search for Subject, (3) Add an appointment, and (4) Retrieve total number of  appointments. 


### Remark on User Input
The program is *case-sensitive*. For example, 'Intro to Spanish' and 'intro to spanish' are regarded as different in the "Subject" field. Users can also search by a key phrase (e.g., 'Spanish'), instead of the full subject name (e.g., 'Intro to Spanish').


## Visual Demo
> This demo uses ```weeklyAppts.csv``` as a command line argument, which initializes the calendar with 548 events. Program assumes each month has __30 days__. Appointments will be displayed in chronological order.

| Sample Program Outputs | Description |
| :---: | :---: |
| ![alt text](https://github.com/jschhie/Calendar-Assistant/blob/master/calendar_demos/Main%20Menu.png "Initial State Using Sample CSV File") | Main Menu displayed. |
| ![alt text](https://github.com/jschhie/Calendar-Assistant/blob/master/calendar_demos/New%20Search%20Subject%20Output.png "Query: Search by Subject") | Search by Subject. Display all `Spanish` events. Note that the first date listed is `Feb. 2, 1994`. |
| ![alt text](https://github.com/jschhie/Calendar-Assistant/blob/master/calendar_demos/New%20Search%20Date%20Output.png "Query: Search by Date")| Search by Date. In this example, the user requests events that occur on `Feb. 2, 1994`. Note that the retrieved ```Spanish``` event from earlier is also returned. | 
