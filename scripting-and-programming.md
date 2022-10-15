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
const char studentData[] = 
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
public void add(char studentID, char firstName, char lastName, char emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
``` 
- This function _sets_ the instance variables mentioned above and updates the roster


```c++
public void remove(char studentID)
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
public void printAverageDaysInCourse(char studentID)
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


### Hello World

```c++
#include <iostream>
using namespace std;

int main() {
  cout << “Hello world!” << endl;
  return 0;
}
``` 

> Note: a return value of `0` signals to the operating system that everything went smoothly. By default a C++ program will _always_ return `0` if there is _not_ a return value at the end of the `main` function

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

The hash (`#`) signifies the start of a preprocessor command

`#include` copies and pastes the entire text of the file specified between the angle brackets into the source code, for this example, the file is `iostream`.This file comes with the C++ compiler. This is short for, _input-output-streams_. It is responsible for displaying and getting text from the user.

_include_ allows you to include functionality without having to copy and paste into the source code every time. _include_ can be used for standard code provided by the compiler and reusable files created by you

`main()`

- The starting point for all C++ programs
- Called by the operating system

`cin` and `cout`

```c++
#include <iostream>
using namespace std;

int main() {
  cout << “Hello World!” << endl;
  return 0;
}
```

> `cout`: character output

> `cin`: character input

> Most function calls take the form of: `object.function_name(argument1, argument2)`

`<<` behave like functions

### Variables

#### Declaring variables

`<variable_type>` `<variable_name`

```c++
int myInt;
```

#### Assigning variables

```c++
int myInt = 0;
```

### Variable types

`int`

Total range of a variable
```
2^16 = 65536 bits
```

Divided by two, `32768`

That would make the range: `-32768` to `32767` (Not `32768`, `1` place is taken by `0`)


`integer`
- has no decimal places
- has different types

`short`
- usually a 16-bit integer

```c++
short variable1;
short int variable2;
signed short variable3;
```

`long`

- 32-bit number

`char`
- 8-bit integer
- _unsigned_ `char` can store between 0 and 255
- _signed_ `char` can store between -128 and 127
- _unsigned_ chars are commonly used to store text in ASCII format
- Can be initialized to hold a number or character, but will only store the ASCII value


`float`
- Floating point numbers
- Storage size of 4 bytes
- Can hold decimal places
- Have a fixed size in memory
- Usually stores a good approximation of a decimal value, _not_ the exact value

`double`
- Can store decimal places
- Store more information than `float`
- Storage size of 8 bytes
- Still only stores an approximation of a decimal value, however more precise than `float`

`bool`
- Storage size of 1 byte
- `true`: any number other than 0
- `false`: the number 0

```c++
#include <iostream>
using namespace std;

int main() {

    //define your variables here
    int intNumber = 30;
    float floatNumber = 30.78;
    double doubleNumber = 45.1234;
    bool boolean = true;
    char charName = ‘u’;
    cout << “Value of Integer is: “;
    //cout your integer variable here
    cout << intNumber << endl;
    cout << “Value of Float is: “;
    //cout your float variable here
    cout << floatNumber << endl;
    cout << “Value of Double is: “ ;
    //cout your double variable here
    cout << doubleNumber << endl;
    cout << “Value of Char is: “;
    //cout your char variable here
    cout << charName << endl;
    cout << “Value of Bool is: “;
    //cout bool double variable here
    cout <<  boolean << endl;
    return 0;
}
``` 

Using `cin` and `cout` to take input from user

```c++
#include <iostream>
using namespace std;

int main() {
  char name;
  char address;
  char phoneNumber;

  cout << “Enter your name” << endl;
  cin >> name;

  cout << “Enter your address”  << endl;
  cin >> address;

  cout << “Enter your phone number” << endl;
  cin >> phoneNumber;
  
  cout << “Name is:” << name;
  cout << “Address is:” << address;
  cout << “Phone number is:” << phoneNumber;
  return 0;
}
```

### Useful operators

`!` logical not

`~` bitwise not

`*` Indirection (dereference)

`&` address of

`new`, `new[]` dynamic memory allocation

`delete`, `delete[]` dynamic memory allocation

`+=`, `-=` assignment by sum and difference

`*=`, `/=`, `%=` assignment by product, quotient, and remainder

`<<=`, `>>=` assignment by bitwise left shift and right shift

`&=`, `^=`, `|=` assignment by bitwise, XOR, and OR

`?:` ternary conditional

### if/else, switch statements

#### if/else statements

```c++
#include <iostream>
using namespace std;

int main() {
  int x = 7;
  if (x == 7) {
    cout << “Value of x is 7” << endl;
  } else {
    cout << “Value of x is not 7” << `endl;
  } 
  return 0;
}
```

#### switch statements

```c++
#include <iostream>
using namespace std;
int main() {
  int x = 2;
  int temp;
  switch (x) {
  case 1:
    temp = 1;
    break;
  case 2:
    temp = 2;
    break;
  default:
    temp = 3;
    break;
  }
  cout << “Value of temp is: ”<< temp << endl;
  return 0;
}
```

### `for`, `while` and `do-while` loops

`while` loops

```c++
#include <iostream>
using namespace std;
int main() {
  int x = 4;
  int y;
  int iterations = 1;
  
  while (x == 4) {
    y += x;
    
    x += 1;
    
    iterations++;
  }
  
  cout << “The value of x is: “<< x << endl;
  cout << “The value of y is: “<< y << endl;
  return 0;
}
```

`do-while` loops

- Nearly identical to `while` loop
- Checks conditional statements after the first run

```c++
#include <iostream>
using namespace std;
int main() {
  int number = 5;
  
  do {
    cout << “Value of number is: “ << number << endl;
    number++;
  } while (number <= 9);
  
  return 0;
}
``` 

`for` loops

```c++
for (expression for initialization; expression for testing; expression for updating) {

}
```

```c++
#include <iostream>
using namespace std;

int main() {
  for (int i = 0; i < 10; i++) {
    cout << “The value of I is: “ << i << endl;
  }
  return 0;
}
```

### Functions and recursion

#### Functions

- Every C++ program must have a `main()` function, it is the entry point
- Include parameters in the `main()` function to allow input from the command line

```c++
int main(int argc, char * const argv[]) {
  …
}
``` 

- When using parameters with `main()`, every group of characters (separated by space) is saved inside of the `argv` array

```
program.exe text 1234
``` 

`argc: 3`

`argv: {program.exe, text, 234}`


`definition`

```c++
void testFunction(int num1, int num2) {}
```

`declaration`

```c++
int testFunction(int, int);
```

#### Parameters

##### Pass by value

- Happens by default
- Value of variable is passed, not the variable itself
- Original is not altered in any way

##### Pass by reference

- Function is given the address of the variable, giving direct access to information
- Use `&` after the data type in the function definition to allow direct access
- A `&` must be present in every forward declaration as well

```c++
testFunction(num1, 23);
``` 

```c++
void testFunction(int& arg1, int arg2)
```

```c++
#include <iostream>
using namespace std;

void testFunction(int& arg1, int arg2) {
  arg1 = arg2;
  // no return in void functions
}

int main() {
  int num1 = 4;
  
  cout << “num1 before passing to testFunction is: “ << num1 << endl;
  
  testFunction(num1, 23);
  
  cout << “Value of num1 is now: “ << num1 << endl;
  
  return 0;
}
```

##### Default parameters

```c++
int addTwoInts(int arg1 = 4, int arg2 = 5);
```

#### Recursion

```c++
#include <iostream>
using namespace std;

int factorial(int n) {
  if (n == 1 || n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main() {
  int temp = factorial(4);
  
  cout << “The value of the factorial computed is: “ << temp << endl;
  
  return 0;
}
```

### Pointers, arrays, and vectors

#### Pointers

> A variable that stores the address in memory of another variable and can be used to manipulate that variable

Pointers hold two pieces of information:
- The memory address, the value of the pointer
- The data type of the variable pointed to

#### Dereferencing pointers

> Dereferencing a pointer allows access to the value of the variable at the pointer’s address

```c++
void f(int* p) {
  int n = *p;
}
``` 

> All data stored in a program is stored in computer memory

#### Declaring pointers

```c++
int *ptr;

struct coord *pCrd;

void *vp;
```

> Pointers are not guaranteed to be initialized, only use them when they point to an existing object


#### Arrays

> Collection of similar data types under the same name

```c++
dataType arrayName[arraySize]

int arr[5] = {1,2,3,4,5};

int arr2[] = {1,2,3,4}; // compiler assumes size of 4 without specificity
```

> If you try to access an element outside of its bound, the compiler might not throw an error, however the value will be undefined

```c++
#include <iostream>
using namespace std;

int main() {
  int arr[5] = {1,2,3,4,5};
  
  cout << “The value of arr[6] is: “ << arr[6] << endl;
  
  return 0;
}

// The value of arr[6] is: -814033152
```

The output is a garbage value at `arr[6]`, which is an index of out of bounds

#### Accessing array values in loops

```c++
#include <iostream>
using namespace std;

int main() {
  int arr[5] = {};
  
  int num = 1;
  
  for (int i = 0; i < 5; i++) {
    arr[i] = num;
    num++;
    cout << “The value of arr[“<< i <<“] is equal to: “ << arr[i] << endl; 
  }
  
  return 0;
}

// The value of arr[0] is equal to: 1
// The value of arr[1] is equal to: 2
// The value of arr[2] is equal to: 3
// The value of arr[3] is equal to: 4
// The value of arr[4] is equal to: 5
```

#### Changing array values

```c++
#include <iostream>
using namespace std;

int main() {
  int arr[5] = {1,2,3,4,5};
  
  cout << “The value of arr[1] originally is: “ << arr[1] << endl;
  // 2
  arr[1] = 420;
  
  cout << “The value of arr[1] after is: “ << arr[1] << endl;
  // 420
  return 0;
}
```

#### Pointer implementation

##### Allocating variables

> An object, variable, or array can be created using the `new` operator, and freed with the `delete` operator

```c++
int *ptr = new int;

delete ptr;
```

> The `new` operator allocates an object from the heap and optionally initializes it

> When you have finished using it you should `delete` it. If you don’t, the pointed memory is inaccessible and will result in a memory leak

```c++
#include <iostream>
using namespace std;

int main() {
  int *ptr; // create a pointer named ptr
  
  int num = 4; // initializing a int type variable named num with a value of 4
  
  cout << “The integer input is: “ << num << endl;
  
  ptr = new int[num]; // using new to initialize the ptr array with size num which will dynamically allocate memory in the heap
  
  cout << “Input ” << num << “ integers\n”;
  
  for (int i = 0; i < num; i++) {
    ptr[i] = i + 1; // assigning value i + 1 to the index i of the ptr array
    cin >> ptr[i]; // cin this value
  }
  cout << “Elements entered by you are\n”;
  
  for (int i = 0; i < num; i++) {
    cout << ptr[i] << endl;
  }
  
  delete[] ptr;
  
  return 0;
}
```

- Allocating memory using `new` remains allocated until the program exits, although you can explicitly deallocate using `delete` beforehand
- In the example above, memory would have been deallocated once `main()` exited, however, using deleting `ptr` beforehand is considered good practice


##### Referencing variables

> The `&` operator is used to reference an object

Then using the `&` operator on an object, you are provided with a pointer to that object

The new pointer can be used as a parameter or be assigned to a variable

```c++
#include <iostream>
using namespace std;

int main() {
  int num;
  
  int *ptr;
  
  ptr = &num;
  
  cout << “Address stored in ptr is: “ << ptr << endl;
  
  *ptr = 7;
  
  cout << “Value of num is: “ << num << endl;
  
  return 0; 
}

// Address stored in ptr is: 0x7fff192223fc
// value of num is: 7
```

##### Pointers to arrays

> C++ allows you to create arrays, then use pointers to carry out operations in those arrays

```c++
#include <iostream>
using namespace std;

int main() {
  // declare an array
  int arr[4];
  // declare a pointer
  int *ptr;
  // make the pointer point to the first element of the arr array
  ptr = arr;
  // set the value of the first element of arr, `arr[0]` to `3`
  *ptr = 3;
  // increment the pointer to point to second element
  ptr++;
  // update the value of the second element in the array `arr`
  *ptr = 5;
  // directly store a value at an index, you need the address first
  ptr = &arr[3];
  // store `10` at index `arr[3]`
  *ptr = 10;
  // move pointer back to `arr[0]`
  ptr = arr;
  // store value at index `arr[2]`
  *(ptr+2) = 8;
  // display everything within the array
  for (int i = 0; i < 4; i++) {
    cout << “The value at arr[“<< i <<”] is “ << arr[i] << endl;
  }
  
  return 0;
}

// value at arr[0] is: 3
// value at arr[1] is: 5
// value at arr[2] is: 8
// value at arr[3] is: 10
```

#### Multi-dimensional arrays

> An array that allows nesting arrays

```c++
int grid[3][3];
```

The above will allocate 3*3 elements in one memory block

A multi-dimensional array is not a pointer-to-a-pointer

```c++
#include <iostream>
using namespace std;

int main() {
  // an array with 3 rows and 3 columns
  int grid[3][3];
  
  // setting the value of each array element
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      grid[i][j] = i + j;
      cout << “grid[“ << i << “][“ << j << “]: “ << grid[i][j] << endl;
    }
  }
  
  return 0;
}

// grid[0][0]: 0
// grid[0][1]: 1
// grid[0][2]: 2
// grid[1][0]: 1
// grid[1][1]: 2
// grid[1][2]: 3
// grid[2][0]: 2
// grid[2][1]: 3
// grid[2][2]: 4
```

#### Pointer to pointer

A pointer contains a reference to another variable, it may also point to another pointer

```c++
int **pptr;
```

```c++
#include <iostream>
using namespace std;

int main() {
  int x = 1;
  int *ptr1;
  int **ptr2;
  
  ptr1 = &x; // getting the address of x
  ptr2 = &ptr1; // getting the address of ptr1
  
  cout << “Value of x is: “ << x << endl;
  
  // the value being pointed to by ptr1
  cout << The value being pointed to by ptr1: “ << *ptr1 << endl;
  
  // the address being pointed to by ptr2
  cout << “The address being pointed to by ptr2: “ << *ptr2 << endl;
  
  // the value being pointed to by ptr2
  cout << “The value being pointed to by ptr2: “ << **ptr2 << endl;
  
  return 0;
}

// Value of x is: 1
// The value being pointed to by ptr1: 1
// The address being pointed to by ptr2: 0x7ffc16070684
// The value being pointed to by ptr2: 1
```

#### Linked List

The above allows for the implementation of a linked list:

```c++
class LinkedListOfIntsNode {
  int value;
  LinkedListOfIntsNode *next_node;
};
```

`LinkedListOfIntsNode` can be thought of a chain, each pointing to its neighbor to the right. You can traverse this list using `next_node`

#### Pointer to a function

> A pointer contains a reference, it may also point to a function

The syntax for declaring a function pointer is:

```
functionType (pointer to function)(datatype);
```

```c++
void (*fp)(float);
```

`*fp` is a pointer to a function that takes a `float` type argument and returns `void`

```c++
#include <iostream>
using namespace std;

void (*fp)();

void foobar() {
  std::cout << “Hello from foobar()” << std::endl;
}

int main() {
  // initialize the function pointer by giving it the address of the function `foobar`
  fp = &foobar;
  
  fp();
}
```

#### Vectors

> An ordered list of a given data type

- `#include <vector> statement must be included

```c++
vector<dataType> vectorName(numElements);
```

The type of each vector element ias specified within the `<>` brackets. The number of vector elements is specified within the parentheses following the vector name `vector<int> numberOfGoals(5)`

`vector` was added as a safer and more powerful form of arrays

A `vector` is useful when wanting to lookup an `nth` element in a list

A `vector` index *must be an unsigned integer*

Example:

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> bestSavePercentage(5);
  int nthGoaliePercentage;

  bestSavePercentage.at(0) = 943;
  bestSavePercentage.at(1) = 940;
  bestSavePercentage.at(2) = 934;
  bestSavePercentage.at(3) = 928;
  bestSavePercentage.at(4) = 914;

  cout << "Enter N (1...5):";
  cin >> nthGoaliePercentage;

  if ((nthGoaliePercentage >= 1) && nthGoaliePercentage <= 5>) {
    cout << "The #" << nthBestPercentage << "ranked goalie has a save percentage of: ";
    cout << bestSavePercentage.at(nthGoaliePercentage - 1) << endl;
  }

  return 0;
}
```

##### Looping and vectors

`size` returns the number of vector elements

Example

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cont int = NUM_VALS = 8;
  vector<int> userVals(NUMVALS);
  unsigned int i;

  cout << "Enter " << NUM_VALS << " integer values ..." << endl;

  for (i = 0; userVals.size(); ++i) {
    cout << "Value: ";
    cin >> userVals.at(i);
  }

  cout << "You entered: ";
  for (i = 0; i < userVals.size(); ++i) {
    cout << userVals.at(i) << " ";
  }
  cout << endl;

  return 0;
}
```

All `vector` elements are initialized with a value of `0`

`vector` elements can be initialized with another single value

Example

```c++
vector<int> myVector(3, 1);
```

This will create a `vector`, `myVector` with three elements, all with a value of `-1`

To initialize with each element having its own value, you can use braces `{}` syntax

Example

```c++
vector<int> goalieSaves = {21, 30, 18};
```

In the case above, a `vector` size is not needed as it is automatically assigned

##### Code challenge

```
Write three statements to print the first three elements of vector runTimes. Follow each with a newline. Ex: If runTimes = {800, 775, 790, 805, 808}, print:
800 
775 
790
```

##### Solution

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_VALS = 5;
   vector<int> runTimes(NUM_VALS);
   unsigned int i;

   // Populate vector
   for (i = 0; i < runTimes.size(); ++i) {
      cin >> runTimes.at(i);
   }

   cout << runTimes.at(0) << endl;
   cout << runTimes.at(1) << endl;
   cout << runTimes.at(2) << endl;

   return 0;
}
```

Common loop structure for `vector`

```c++
for (i = 0; i< vector.size(); ++i) {
  // access vector by vector.at(i)
}
```

##### Code challenge

```
Write a for loop to print all NUM_VALS elements of vector courseGrades, following each with a space (including the last). Print forwards, then backwards. End with newline. Ex: If courseGrades = {7, 9, 11, 10}, print:
7 9 11 10 
10 11 9 7 
```

##### Solution

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_VALS = 4;
   vector<int> courseGrades(NUM_VALS);
   int i;

   for (i = 0; i < courseGrades.size(); ++i) {
      cin >> courseGrades.at(i);
   }

   for (i = 0; i < NUM_VALS; ++i) {
      cout << courseGrades.at(i) << " ";
   }
   
   cout << endl;
   
   for (i = courseGrades.size() - 1; i >= 0; --i) {
      cout << courseGrades.at(i) << " ";   
   }
   
   cout << endl;

   return 0;
}
```

##### Code challenge

```
Find the average of the vector's element values
```

##### Solution

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int VALS_SIZE = 6;
   vector<int> valsVctr(VALS_SIZE);
   unsigned int i;
   int sumVal;
   int avgVal;

   valsVctr.at(0) = 30;
   valsVctr.at(1) = 20;
   valsVctr.at(2) = 20;
   valsVctr.at(3) = 15;
   valsVctr.at(4) = 5;
   valsVctr.at(5) = 10;

   sumVal = 0;
   avgVal = 0;
   for (i = 0; i < valsVctr.size(); ++i) {
      sumVal = sumVal + valsVctr.at(i);   
   }

   avgVal = sumVal / VALS_SIZE;

   cout << "Avg: " << avgVal << endl;

   return 0;
}
```

##### Code challenge

Assign numMatches with the number of elements in userValues that equal matchValue. userValues has NUM_VALS elements. Ex: If userValues is {2, 2, 1, 2} and matchValue is 2 , then numMatches should be 3.

##### Solution

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_VALS = 4;
   int matchValue;
   unsigned int i;
   int numMatches = -99; // Assign numMatches with 0 before your for loop
   vector<int> userValues(NUM_VALS);

   cin >> matchValue;

   for (i = 0; i < userValues.size(); ++i) {
      cin >> userValues.at(i);
   }

   /* Your solution goes here  */
   numMatches = 0;
   for (i = 0; i < userValues.size(); ++i) {
      if (userValues.at(i) == matchValue) {
         numMatches = numMatches + 1;   
      }
   }

   cout << "matchValue: " << matchValue << ", numMatches: " << numMatches << endl;

   return 0;
}
```

##### Code challenge

Write a for loop to populate vector userGuesses with NUM_GUESSES integers. Read integers using cin. Ex: If NUM_GUESSES is 3 and user enters 9 5 2, then userGuesses is {9, 5, 2}.

##### Solution

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_GUESSES = 3;
   vector<int> userGuesses(NUM_GUESSES);
   unsigned int i;

   for (i = 0; i < NUM_GUESSES; ++i) {
      cin >> userGuesses.at(i);         
   }

   for (i = 0; i < userGuesses.size(); ++i) {
      cout << userGuesses.at(i) << " ";
   }

   return 0;
}
```

##### Code challenge

Vector testGrades contains NUM_VALS test scores. Write a for loop that sets sumExtra to the total extra credit received. Full credit is 100, so anything over 100 is extra credit. Ex: If testGrades = {101, 83, 107, 90}, then sumExtra = 8, because 1 + 0 + 7 + 0 is 8.

##### Solution

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_VALS = 4;
   vector<int> testGrades(NUM_VALS);
   unsigned int i;
   int sumExtra = -9999; // Assign sumExtra with 0 before your for loop

   for (i = 0; i < testGrades.size(); ++i) {
      cin >> testGrades.at(i);
   }

   sumExtra = 0;
   for (i = 0; i < testGrades.size(); ++i) {
         if (testGrades.at(i) > 100) {
            sumExtra = sumExtra + testGrades.at(i) - 100;
         }
   }

   cout << "sumExtra: " << sumExtra << endl;
   return 0;
}
```

##### Code challenge

Write a for loop to print all NUM_VALS elements of vector hourlyTemp. Separate elements with a comma and space. Ex: If hourlyTemp = {90, 92, 94, 95}, print:
90, 92, 94, 95
Your code's output should end with the last element, without a subsequent comma, space, or newline.

##### Solution

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_VALS = 4;
   unsigned int i;
   vector<int> hourlyTemp(NUM_VALS);

   for (i = 0; i < hourlyTemp.size(); ++i) {
      cin >> hourlyTemp.at(i);
   }

   for (i = 0; i < hourlyTemp.size(); ++i) {
      if (i == hourlyTemp.size() - 1) {
         cout << hourlyTemp.at(i);   
      } else {
         cout << hourlyTemp.at(i) << ", ";   
      }
   }

   cout << endl;

   return 0;
}
```

##### Code challenge

Add each element in origList with the corresponding value in offsetAmount. Print each sum followed by a space. Ex: If origList = {40, 50, 60, 70} and offsetAmount = {5, 7, 3, 0}, print:
45 57 63 70   

##### Solution

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_VALS = 4;
   vector<int> origList(NUM_VALS);
   vector<int> offsetAmount(NUM_VALS);
   unsigned int i;

   for (i = 0; i < origList.size(); ++i) {
      cin >> origList.at(i);
   }

   for (i = 0; i < offsetAmount.size(); ++i) {
      cin >> offsetAmount.at(i);
   }
   
   for (i = 0; i < origList.size(); ++i) {
      cout << origList.at(i) + offsetAmount.at(i) << " ";      
   }

   cout << endl;

   return 0;
}
```

##### Code challenge

For any element in keysList with a value greater than 100, print the corresponding value in itemsList, followed by a space. Ex: If keysList = {42, 105, 101, 100} and itemsList = {10, 20, 30, 40}, print:
20 30 

##### Solution

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int SIZE_LIST = 4;
   vector<int> keysList(SIZE_LIST);
   vector<int> itemsList(SIZE_LIST);
   unsigned int i;

   for (i = 0; i < keysList.size(); ++i) {
      cin >> keysList.at(i);
   }

   for (i = 0; i < itemsList.size(); ++i) {
      cin >> itemsList.at(i);
   }

   for (i = 0; i < keysList.size(); ++i) {
      if (keysList.at(i) > 100) {
         cout << itemsList.at(i) << " ";   
      }   
   }

   cout << endl;

   return 0;
}
```

### Classes

> Independent, self-managing modules and their interactions. An object is an instance of mentioned module, and a class is its definition

```c++
class Dog {
  public: 
    char name[25];
    char gender;
    int age;
    int size;
    bool healthy;
};

int main() {
  // creating an object of Dog class
  Dog dogObj;
  
  // using the dot operator to access members of a class
  dobObj.gender;
}
```

#### Private members

> By default all members declared within a class are `private`

- They can only be referenced within the definitions of member functions
- If a `private` variable is accessed directly, it will result in a compiler error
- Can be variables or functions

```c++
#include <iostream>
using namespace std;

class Dog {
  private:
    char name[25];
    char gender;
    int age;
    int size;
    bool healthy;
};

int main() {
  Dog dogObj;
  dogObj.name;
}
``` 

The code above results in an error due to private members of the class being accessed directly:

```
main.cpp: In function ‘int main()’:
main.cpp:6:17: error: ‘char Dog::name [25]’ is private
     char name[25];
                 ^
main.cpp:16:10: error: within this context
   dogObj.name;  //this will give an error as data members are private 
```

#### Public members

> Members of a class that can be accessed from outside of the class

```c++
#include <iostream>
using namespace std;
class Dog
{
public:
    char name = “Nikita”;
    char gender  = “Female”;
    int age = 3;
    int size = 70;
    bool healthy = true;
};


int main() {
  Dog dogObj;
  cout << “Dog name is: “<<dogObj.name<<endl;
  cout << “Dog gender is: “<<dogObj.gender<<endl;
  cout << “Dog age is: “<<dogObj.age<<endl;
  cout << “Dog size is: “<<dogObj.size<<endl;
  cout << “Is dog healthy: “ <<dogObj.healthy<<endl;
}

// Dog name is: Nikita
// Dog gender is: Female
// Dog age is: 3
// Dog size is: 70
// Is dog healthy: 1
```

#### Member functions

- Declared in the class definition
- Identify the class in which the function is a member

```c++
class DayOfYear {
  public:
    void output();
    int month;
    int day;
};

// indicates function output is a member of the DayOfYear class
void DayOfYear::output() {
  cout << “Month = “ << month << endl;
  cout << “Day = “ << day << endl; 
}

int main() {
  // declaring multiple objects of class DayOfYear
  // birthday and today have their own versions of class member variables
  DayOfYear birthday, today;
  
  birthday.month = 10;
  birthday.day = 4;
  
  cout << “Your birthday date is: “ << endl;
  
  birthday.output();
  
  cout << Today’s date is: “ << endl;
  
  today.month = 10;
  
  today.day = 5;
  
  today.output();
}

// Your birthday date is: 
// Month = 10
// Day = 4
// Today’s date is: 
// Month = 10
// Day = 5
```

#### Setters and Getters

> `public` member functions used to `set` and `get` `private` member variables

```c++

#include <iostream>
using namespace std;

class DayOfYear {
  public:
    int myVar;
    void output();
    
    void set(int new_month, int new_day);
    // Precondition: new_month and new_day form a possible date
    // Postcondition: The date is reset according to the arguments
    
    int get_month();
    // Returns the month
    
    int get_day();
    // Returns the day
    
    private:
      void check_date();
      int month;
      int day;
};

int main() {
  DayOfYear today, birthday;
  
  today.set(10, 5);
  
  cout << “Today’s date is: “;
  
  today.output();
  
  birthday.set(10, 4);
  
  cout << “Birthday date is: “;
  
  birthday.output();
  
  if (today.get_month() == birthday.get_month() && today.get_day() == birthday.get_day())
    cout << “Happy Birthday!\n”;
  else
    cout << “It’s not your birthday\n”; 
  
  return 0;
}

void DayOfYear::output() {
  cout << “Month = “ << month
       << “ Day = “ << day << endl; 
}

void DayOfYear::set(int new_month, int new_day) {
  month = new_month;
  day = new_day;
  check_date();
}

void DayOfYear::check_date() {
  if ((month < 1) || (month > 12) || (day < 1) || (day > 31)) {
    cout << “Illegal date.\n”;
    exit(1);
  }
}

int DayOfYear::get_month() {
  return month;
}

int DayOfYear::get_day() {
  return day;
}


// Today’s date is: Month = 10 Day = 5
// Birthday date is: Month = 10 Day = 4
// It’s not your birthday
```

#### Constructors

- Automatically called when an object of the class is declared
- Member function, usually `public`
- Can be used to initialize member variables when an object is declared

> A constructor’s name must be the same as the name of the class it is declared in

> A constructor cannot return a value

> No return type, even `void`, can be used while declaring a constructor

##### Constructor declaration

```c++
class DayOfYear {
  public:
    DayOfYear(int new_month, int new_day);
  private:
    int month;
    int day; 
};
``` 

##### Constructor definition

```c++
#include <iostream>
using namespace std;

class DayOfYear {
  public:
    // declaring constructor
    DayOfYear(int new_month, int new_day);
    // default constructor without parameters
    DayOfYear();
    int myVar;
    void output();
    int get_month();
    int get_day();
  
  private:
    void check_date();
    int month;
    int day;
    
    
  int main() {
    // creating object and calling constructor
    DayOfYear birthday(11, 23);
    // creating object and calling default constructor 
    DayOfYear today;
    
    cout << “Birthday day is: “ << birthday.get_day() << endl;
    
    count << “Birthday month is: “ << birthday.get_month() << endl;
    
    cout << “Today the day is: “ << today.get_day() << endl;
    
    cout << “today the month is: “ today.get_month() << endl;
    
    return 0;
  }
  
  // defining constructor
  // class name and constructor are the same name
  DayOfYear::DayOfYear(int new_month, int new_day) {
    month = new_month;
    day = new_day;
  }
  // defining default constructor
  DayOfYear::DayOfYear() {
    month = 0;
    day = 0;
  }
  // returns private variable month
  int DayOfYear::get_month() {
    return month;
  }
  // returns private variable day
  int DayOfYear::get_day() {
    return day;
  }
}
```

##### Constructor overloading

> Constructors can be overloaded by defining constructors with different parameters list

```c++
DayOfYear(); // default
DayOfYear(int newmonth, int newday); // passing two int parameters
DayOfYear(double newmonth, double newday); // passing two double parameters
DayOfYear(float newday); // passing a float parameter
```

#### Inheritance

- Provides a way to create a new class from an existing class
- New class is a specialized version of the existing class

> Base class (parent): inherited by child class

> Derived class (child): inherits from the base class

```c++
// base class
class Student {
 // body
}
// derived class
class UnderGrad : public Student {
  // body
}
```

> Inheritance is a relationship between classes

> An object of the derived class is an object of the base class

> A derived object has all characteristics of the base class

An object of child class has:
- All members defined in the child class
- All members declared in the parent class
 
An object of child can use:
- All `public` members defined in the child class
- All `public` members defined in the parent class

##### Protected members

> `protected` member access specification: similar to `private`, but accessible by objects of a derived class

##### Class access specifiers

> `public`: the object of the derived class can be treated as an object of the base class

> `protected`: more restrictive than `public`, but allows derived class to know details of parents

> `private`: prevents objects of the derived class to be treated as objects of base class

base class `Shape` and derived class `Square`

```c++
#include <iostream>
using namespace std;

// base class
class Shape {
  public:
    // default constructor
    Shape() {
      length = 0;
    }
   void setlength(int l) {
      length = l;
   }
    protected:
      int length;
};

// derived class
class Square: public Shape {
  public:
    // declaring and initializing derived class constructor
    Square() : Shape() {
      length = 0;
    }
    int get_Area() {
      return (length * length);
    }
};

int main(void) {
  // making object of child class Square 
  Square sq;
  // setting length equal to 5
  sq.setlength(5);
  
  cout << “Total area of square is: “ << sq.get_Area() << endl;
  
  return 0;
}

// Total are of square is: 25
``` 

#### Polymorphism and virtual functions

> Virtual function: a member function which is declared in the base class using the keyword `virtual` and is re-defined (overridden) by the derived class

> Polymorphism: the ability to take many forms. It happens when a hierarchy of classes which are all related to each other by inheritance

##### Without virtual functions

```c++
#include <iostream>
using namespace std;

// base class
class Shape {
  public:
    Shape(int l, int w) {
      length = l;
      width = w;
    }
    
    int get_Area() {
      cout << This is a call to parent class area” << endl;
    }
    
  protected:
    int length, width;
};

class Square: public Shape {
  public:
    // declaring and initialing derived class constructor
    Square(int l = 0, int w = 0) : Shape(l, w){}
    
    int get_Area() {
      cout << “square area: “ << length * width << endl;
      return (length * width);
    }
};

// derived class
class Rectangle: public Shape {
  public:
    // declaring and initializing a derived class constructor
    Rectangle(int l = 0, int w = 0) : Shape(l, w) {}
    int get_Area() {
      cout << “Rectangle area: “ << length * width << endl;
      return (length * width);
    }
};

int main(void) {
  Shape *s;
  // making object of child class Square
  Square sq(5, 5);
  // making an object of child class Rectangle
  Rectangle rec(4, 5);
  
  s = &sq;
  
  s -> get_Area();
  
  s = &rec;
  
  s -> get_Area();
  
  return 0;
}

// This is call to parent class area
// This is call to parent class area
```

The above does not call `get_Area()` from either child class, but rather only calls `get_Area()` defined in the base class

This is called `static linkage`; the call to `get_Area()` is only set once by the compiler in the base class

You can avoid this by using `virtual` functions

##### Using `virtual` functions

- Defined in the base class
- Another version in the derived class
- Allows for the selection of the function you want to call at any point based on the kind of object that is called

```c++
#include <iostream>
using namespace std;

// Base class
class Shape {
  public:
    // default constructor
    Shape(int l, int w) {
      length = l;
      width = w;
    }
    
    // `get_Area()` is now a `virtual` function
    virtual int get_Area() {
      cout << “This ia a call to the parent class” << endl;
    }
    
  protected:
    int length, width;
};

// Derived class
class Square: public Shape {
  public:
    // declaring and constructing derived class constructor
    Square(int l = 0, int w = 0) : Shape(l, w) {}
    
    int get_Area() {
      cout << “Square area: “ << length * width << endl;
      return (length * width);
    }
};

// Derived class
class Rectangle: public Shape {
  public:
    Rectangle(int l = 0, int w = 0) : Shape(l, w) {}
    
    int get_Area() {
      cout << “Rectangle area: “ << length * width << endl;
    }
};

int main(void) {
  Shape *s;
  // Making object of child class Square
  Square sq(5, 5);
  // Making object of child class Rectangle
  Rectangle rec(4, 5);
  
  s = &sq;
  s -> get_Area();
  s = &rec;
  s -> get_Area();
  
  return 0;
}

// Square area: 25
// Rectangle area: 20
```

When the addresses of the objects are stored in `*s`, the respective `get_Area()` is called since the compiler looked at the contents of the pointer, rather than its type.

#### Templates

> Mechanism used to implement generic code that behaves the same way in different situations

Non-generic example

```c++
#include <iostream>
using namespace std;

int multiply(int x, int y) {
  return (x * y);
}

double multiply(double x, double y) {
  return (x * y);
}

int main() {
  int temp1;
  double temp2;
  
  temp1 = multiply(4, 5);
  temp2 = multiply(4.5, 5.5);
  
  cout << “Value of temp1 is: “ << temp1 << endl;
  
  cout << “Value of temp2 is: “ temp2 << endl;
  
  return 0;
}
```

Declaration

```c++
template<class Type>
// or
template<typename Type>
```

`class` and `typename` have the same meaning in this case, however, some compilers may replace the words with each other

`Type` is our generic data type, and when the template is used, it would be as if `Type` was a `typedef` for your datatype

Generic example

```c++
#include <iostream>
using namespace std;

template<Class Type>
Type multiply(Type x, Type y) {
  return (x * y);
}

int main() {
  int result = multiply<int>(2, 5);
  
  cout << “Result when integers are passed is: “ << result << endl;
  
  double result2 = multiply<double>(2.5, 5.5);
  
  cout << “Result when double values are passed is: “ << result2 << endl;
  
  return 0; 
}
```

> For a template with three types, `First`, `Second`, and `Third`:

```c++
template<class First, class Second, class Third>
```

##### Class templates

> Classes that can have members of the generic type

```c++
template<Class T>
class Score {
  private:
    T scorenumber;
  public:
    Score(T args) {
      scorenumber = args;
    }
};
```

The variable `scorenumber` could be an `int`, `float`, or `double`

Declaring the object

```c++
Score<int> myscore(40);
// or
Score<double> myscore(23.9)
```

Another example

```c++
#include <iostream>
using namespace std;

template<class T>
class myvalues {
  // teo values of type T
  T myval1, myval2;
  public:
    myvalues(T arg1, T arg2) {
      myval1 = arg1;
      myval2 = arg2;
    }
    T max();
};

template<class T>
T myvalues<T>::max() {
  if (myval1 > myval2) {
    return myval1;
  } else {
    return myval2;
  }
}

int main() {
  myvalues<int> obj(20, 50);
  
  cout << “Max value is: “ << obj.max();
  
  return 0;
}

// Max value is: 50
```