Brief Intro: calendar-prog, Spring 2017, C++.

# Table of Contents
* [Introduction](https://github.com/jschhie/calendar-prog/blob/master/README.md#introduction)
* [How to Use](https://github.com/jschhie/calendar-prog/blob/master/README.md#how-to-use)
  * [Creating Executable](https://github.com/jschhie/calendar-prog/blob/master/README.md#creating-executable)
  * [Command Line Arguments I](https://github.com/jschhie/calendar-prog/blob/master/README.md#command-line-arguments-i)
  * [Command Line Arguments II](https://github.com/jschhie/calendar-prog/blob/master/README.md#command-line-arguments-ii)
    - [CSV Entries](https://github.com/jschhie/calendar-prog/blob/master/README.md#csv-entries)
    - [Additional Notes for CSV Entries](https://github.com/jschhie/calendar-prog/blob/master/README.md#additional-notes-for-csv-entries)
 * [Using calendar-prog](https://github.com/jschhie/calendar-prog/blob/master/README.md#using-calendar-prog)
  * [Remark on User Input](https://github.com/jschhie/calendar-prog/blob/master/README.md#remark-on-user-input)
    
# Introduction
A User-friendly Calendar, programmed in C++. Integrates templated polymorphism, doubly-linked lists, vectors, and operator overloading. 
Assists users in creating and finding events and arranges weekly appointments. It is designed to help students keep track of their academic schedules. 
Assumes each month has 30 days. Returns appointments in chrological order.


# How to Use

## Creating Executable
For convenience, the corresponding Makefile has been made available. After downloading it and the source code, you can use the command: 
```make all```

## Command Line Arguments I
This program can be run as-is (e.g., ```./calendar.out```). 

## Command Line Arguments II 
Alternatively, you can supply a comma-separated-values (csv) file as a command line argument (e.g., ```./calendar.out weeklyAppts.csv```).
For the latter, the csv file contains a list of appointments and must have the following format *and* heading:
> Date,Class,Subject,Start Time,End Time,Location,Series,Count.

### CSV Entries
| CSV Entry Label   | Expected Format     | Example           |
| ----------------- | -----------------   | -------           |
| Date              | MM/DD/YYYY          | 08/09/2012        |
| Class             | A digit             | 0                 |
| Subject           | Any string          | Spanish           |
| Start/End Time    | HH:MM:SS AM/PM      | 10:10:00 AM       |
| Location          | Any string          | 150 Wellman Hall  |
| Series            | String in all CAPS  | SMTWRFU           |
| Count             | A digit             | 7                 |

### Additional Notes for CSV Entries
* Abbreviations: S - Saturday, M - Monday, T - Tuesday, W - Wednesday, R - Thursday, F - Friday, and U - Sunday.
* For a non-weekly event, you can either (1) leave both the "Series" and "Count" blank, 
or (2) provide both, so that "Series" is a single character and "Count" is 1.   

# Using calendar-prog

While runnning the program, you are presented five options in the "Calendar Menu": 
> (0) Done, (1) Search for date, (2) Search for Subject, (3) Add an appointment, and (4) Print appointment count. 

## Remark on User Input
The program is *case-sensitive*. For example, 'Intro Spanish' and 'intro spanish' are regarded as different in the "Subject" field. 

