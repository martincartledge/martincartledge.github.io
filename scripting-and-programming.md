# Scripting and programming

### Final project requirements

#### IDE

Visual Studio or XCode

#### Scenario

Migrate student system to a new platform using c++

- Write two classes, `Student` and `Roster`
 
- Program will maintain the current roster of students within a given course
 
- Student data for the program will consist of:
- `Student ID`
- `First Name`
- `Last Name`
- `Email Address`
- `Age`
- `Days in Course`[]
- `Degree Program`
 
- The program will read a list of 5 students and use function calls to manipulate data
 
- The program should create `Student` objects
 
- The entire student list will be stored in one array called `classRosterArray`
 
- Data-related output will be directed to the console

**Output:** 

```c++
const string studentData[] = 
{“A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY”, “A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK”, “A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE”, “A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY”, “A5,[firstname],[lastname],[emailaddress],[age], [numberofdaystocomplete3courses],SOFTWARE”
``` 

#### Requirements

- Modify `studentData` table to include your personal info as last item
- Create the following files:
- `degree.h`
- `student.h`
- `student.cpp`
- `roster.h`
- `roster.cpp`
- `main.cpp`
 
- Define enumerated data type, `DegreeProgram` that contain the following data type values (this should be included in `degree.h`):
- `SECURITY`
- `NETWORK`
- `SOFTWARE`

- For the `Student` class:
- Create a class, `Student` in `student.h` and `student.cpp` and include the following variables:
- `student ID`
- `first name`
- `last name`
- `email address`
- `age`
- `array of number of days to complete each course`
- `degree program`

- Create each of the following functions in the `Student` class:
- An accessor (getter) for each instance variable (outlined above)
- A mutator (setter) for each instance variable (outlined above)
- All external access and changes to _any_ instance variables of the `Student` class must be done using `accessor` and `mutator` functions
- Constructor using _all_ of the input parameters provided in the table
- `print()` to print specific student data

- Create a `Roster` class (`roster.cpp`) by doing the following:
- Create an array of pointers, `classRosterArray` to hold the data provided in the `studentData` table
- Create a student object for _each_ student in the data table and populate `classRosterArray`:
- a. Parse _each_ set of data identified in the `studentData` table
- b. Add each student object to `classRosterArray`

- Define the following functions:
 
```c++
public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
``` 
- This function _sets_ the instance variables mentioned above and updates the roster


```c++
public void remove(string studentID)
``` 
- This function removes students from the roster by `studentID`
- If the `studentID` _does not_ exist, the function prints an error message indicating that `the student was not found`

```c++
public void printAll()
``` 
- This function prints a complete tab-separated list of student data in the provided format:

```
A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security
``` 
- `printAll()` should loop through _all_ students in the `classRosterArray` and call `print()` for each student

```c++
public void printAverageDaysInCourse(string studentID)
``` 
- This function correctly prints a student’s average number of days in three courses
- The student is identified by the `studentID` parameter\

```c++ 
public void printInvalidEmails()
```
- This function verifies that student email addresses and 
- Displays all invalid emails addresses to the user
- A valid email should include `@` and `.`
- A valid email _should not_ include `’ ‘`

```c++
public void printByDegreeProgram(DegreeProgram degreeProgram)
``` 
- This function should print out student information for a degree program specified by an enumerated type

- Add a `main()` function in the `main.cpp` file, this will include the following function calls:
- a. Print out: `course title`, `programming language used`, `WGU student ID`, `name`
- b. Create an instance of the `Roster` class called `classRoster`
- c. Add each student to `classRoster`
- d. Convert the pseudo code below to complete the rest of the `main()` function:
```c++
classRoster.printAll();
classRoster.printInvalidEmails();

// loop through classRosterArray and for each element:
classRoster.printAverageDaysInCourse(/*current object’s student id*/);

// use an accessor (getter) for the classRosterArray to access the student id

classRoster.printByDegreeProgram(SOFTWARE);
classRoster.remove(“A3”);
classRoster.printAll();
classRoster.remove(“A3”);
// expected: the line above should print a message saying such a student with this ID was not found.
``` 

- e. Implement the destructor to release the memory that was allocated dynamically in `Roster`

- Demonstrate professional communication in the content and presentation of your submission

#### Submitting

- One zip file with all files
- Include screenshot of the console run

### Basic input

Below, the `>>` operator is used to get an input value and will also put that value into the `x` variable 

```c++
int main() {
    int wage;
    
    cin >> wage;
    
    cout << “Salary is ”;
    cout << wage * 40 * 52;
    cout << endl;
    
    return 0;
}
```

Returning a `0` indicates that there was an error within the program.

> `cin` is a class of `iostream` and is used to get input from input devices such as keyboards, etc

