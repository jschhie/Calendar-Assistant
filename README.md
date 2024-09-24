# Calendar Assistant
> C++

## Project Overview
This project helps students track their academic schedules by enabling them to create and manage events and organize weekly appointments. It employs templated polymorphism, doubly-linked lists, vectors, and operator overloading for its implementation.

A visual demo can be found [here](https://github.com/jschhie/calendar-prog/blob/master/README.md#visual-demo).

## Table of Contents
* [Visual Demo](https://github.com/jschhie/calendar-prog/blob/master/README.md#visual-demo)
* [How to Use](https://github.com/jschhie/calendar-prog/blob/master/README.md#how-to-use)
  * [Creating Executable](https://github.com/jschhie/calendar-prog/blob/master/README.md#creating-executable)
  * [Command Line Arguments I](https://github.com/jschhie/calendar-prog/blob/master/README.md#command-line-arguments-i)
  * [Command Line Arguments II](https://github.com/jschhie/calendar-prog/blob/master/README.md#command-line-arguments-ii)
 * [Program Functionalities](https://github.com/jschhie/calendar-prog/blob/master/README.md#usage)
  * [Remark on User Input](https://github.com/jschhie/calendar-prog/blob/master/README.md#remark-on-user-input)

## Visual Demo
> This demo uses ```weeklyAppts.csv``` as a command line argument, initializing the calendar with 548 events. The program assumes each month has __30 days__, and appointments are displayed chronologically.

| Sample Program Outputs | Description |
| :---: | :--- |
| ![alt text](https://github.com/jschhie/Calendar-Assistant/blob/master/calendar_demos/Main%20Menu.png "Initial State Using Sample CSV File") | <dl><dt>Main Menu displayed.</dt></dl>|
| ![alt text](https://github.com/jschhie/Calendar-Assistant/blob/master/calendar_demos/New%20Search%20Subject%20Output.png "Query: Search by Subject") | <dl><dt> Search by Subject. </dt> <dd>Display all `Spanish` events.</dd> <dd> Note that the first date listed is `Feb. 2, 1994`.</dd></dl> |
| ![alt text](https://github.com/jschhie/Calendar-Assistant/blob/master/calendar_demos/New%20Search%20Date%20Output.png "Query: Search by Date")| <dl><dt>Search by Date.</dt> <dd>This example shows events occurring on `Feb. 2, 1994`. </dd> <dd> Note that the retrieved ```Spanish``` event from earlier is also returned. </dd> </dl> | 

## How to Use
### Creating Executable
For convenience, a corresponding `Makefile` has been provided. Assuming the user is inside the `source_code` directory, they can generate an executable called `calendar.out` by using the following command:

```bash
make all
```

### Command Line Arguments I
To run the program without any events, execute:
```bash
./calendar.out
```

### Command Line Arguments II 
Alternatively, to initialize the program with custom events, supply a comma-separated values (CSV) file as a command line argument:

```bash
./calendar.out filePath/weeklyAppts.csv
```

The CSV file should contain a list of appointments and have the following format and heading:
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
  <dd> The user can either: <li> (a) Leave both the "Series" and "Count" blank, or </li>
   <li> (b) Provide a single character for "Series" and set "Count" to 1.</li></dd>
 </dl>
</details>

## Usage
When running the program, you will see five options in the "Calendar Menu":
1. (0) Exit and save calendar events
2. (1) Search for date
3. (2) Search for Subject
4. (3) Add an appointment
5. (4) Retrieve total number of appointments

### Remark on User Input
The program is *case-sensitive*. For example, 'Intro to Spanish' and 'intro to spanish' are considered different in the "Subject" field. Users can also search by a key phrase (e.g., 'Spanish'), instead of the full subject name (e.g., 'Intro to Spanish').
