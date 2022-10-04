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
  string name;
  string address;
  string phoneNumber;

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

### Pointers and arrays

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