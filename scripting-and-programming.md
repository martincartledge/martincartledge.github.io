# Scripting and programming

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