## Learn C++ programming

#### Compile and rename 
- In C++ the translation into a binary format is the job of the compiler, which produces an EXECUTABLE file
Source file (minimal.cpp) --> compilation (g++-11) --> Executable binary file (a.out)
```
% g++-11 minimal.cpp // to compile the cpp
% ls // to have a list of the files in the directory
a.out   minimal.cpp
% g++-11 minimal.cpp -o minimal // to rename the cpp
% ls
a.out   minimal    minimal.cpp
% ./minimal # to run the renamed cpp
```
#### Format
```
clang-format minimal.cpp // used to format the code and make it more readable
int main ( )
```
#### Input/Output
- One mechanism offered by C++ to do input and output is the I/O streams interface, which allows the creation and the manipulation of stream entities
- Input and output streams connected to the terminal are automatically available to a program
- std::cin, std::cout (and std::cerr for errors)
- To extract values, use the stream operators >>
- To insert values, use the stream operators <<

## [Hello](https://github.com/elenasaso/Programmazione-ES/blob/d7122092fe853e758460fc144701663dbd4d2d18/hello.cpp)
In the editor:
```
#include <iostream> // import I/O utilities
#include <string> // import string utilities
int main() // start the program from here
{
  std::cout << "What's your name? "; // print a message on the terminal
  std::string name; // some space is needed in memory for a string
  std::cin >> name; // read a string from the terminal into that space
  std::cout << "Hello, " << name << '\n'; // print a multi-part message
}
```
In the terminal:
```
% g++-11 hello.cpp -o hello
% ./hello
What's your name? Elena
Hello, Elena 
%
```

### Objects 
- The constructs in a C++ program create, destroy, refer to, access, and manipulate objects
- An object is a region of storage (i.e. memory) 
- has a storage duration/lifetime
- has a type
- can have a name
 
 #### Types
- A type givees meaning to a piece of storage 
- A type identifies a set of values and the operations that can be applied to those values
C++ is a **strongly typed** language (mostly)
- The compiler checks that program instructions are compatible with the type system
C++ is a **statically typed** language (mostly)
- C++ defines a few fundamental types and provides mechanisms to build compound types on top of them

#### Fundamental Types
- Arithmetic types: int, char, bool
- Floating-point types: float, double 
- std::nullptr_t
- void

<img width="650" alt="Schermata 2022-03-18 alle 14 37 17" src="https://user-images.githubusercontent.com/99679794/159012846-96b3056f-166b-4888-95ec-0b373dd30361.png">

### Variables
- A variable is a NAME for an object
- A name is an identifier: a sequence of letters (including _ ) and digits, starting with a letter
- Avoid _ at the beginning 
- Choose meaningful names

```
int i; // declaration; the value is undefined
i = 4321; // assignment of a constant
int j = 1234; // declaration and initialization
i = j; // assignment of j's value to i
```
NB At the end i and j have the same value but remain **distinct objects**

### Literals
A literal is a constant value of a certain type included in the source code
- integer
- floating point
- character
- string
- boolean
- nullptr

#### Integer literals 
- **decimal** non-0 decimal digit followed by zero or more digits
- **binary** 0b or 0B followed by binary digits
- **exadecimal** 0x or 0X followed by hexadecimal digits
- **octal** 0 followed by octal digits
Integer literals are of type int

#### std::string
- A compound (user-defined) type to represent a string of characters
- Provided by the C++ Standard Library
- Many operations available
- An std::string can be initialized with a string literal, a sequence of escaped or non-escaped characters between double quotes
- "hello" "hello'\n'world" "hello \"world\"" 
- \n means “newline”
- The type of a string literal is **not** std::string

### Expressions
- An expression is a sequence of operators and their operands that specifies a computation
- Literals and variables are typical operands, but there are others
```
1+2
i = 1 + 2 // assignment
i == j // equality comparison sqrt(x) > 1.42
std::cout << "hello, " << name << '\n'
```
- The evaluation of an expression typically produces a result
- Some expressions have side-effects. They modify the state of the program, i.e. the state of memory, or the external world

### Operators
<img width="650" alt="Schermata 2022-03-18 alle 14 52 09" src="https://user-images.githubusercontent.com/99679794/159015306-ddee6efd-3484-4d73-987f-52a4a95f7f69.png">

## [Sum of two numbers](https://github.com/elenasaso/pf2021/blob/5d540d0a46f313a710d4482591b7ed0c162c0e42/sum_two_numbers.cpp)
A program that reads two numbers from input and writes the sum to output

### Expression statement
- An expression followed by a semicolon (;)
- The value of the expression (if any) is discarded
- The expression can have side effects
```
b + 2;
a = b + 2;
std::cin >> a >> b;
; // empty statement
```
### Compound statement (or BLOCK)
A sequence of zero or more statements enclosed between braces ({}) 
```
{
   found = true;
   ++i;
   int n = 3;
   std::cout << n;
}
```
```
{ found = true; ++i; ··· } // all on one line
```

### Declaration statement
- A declaration statement introduces one or more new identifiers into a C++ program, possibly initializing them
◦ typically variables, but not only
- A declaration of a **variable in a block** makes the variable of **automatic storage duration**, unless otherwise specified
◦ the corresponding object is **automatically created** each time the declaration is executed
◦ the corresponding object is **automatically destroyed** each time the execution reaches the end of the block
- A declaration should introduce only one identifier
- A variable should be declared only in the moment it’s actually
needed
- A variable should be initialized at the point of declaration, if there is a meaningful initial value

## [The smallest of two numbers](https://github.com/elenasaso/Programmazione-ES/blob/94cf40488376963b84b1e2cb8b032fff203d0289/smallest_two_numbers.cpp)
A program that reads two numbers from input and writes the smallest to output

### If then else
- Selection statement to choose one of two flows of control depending on a boolean condition
Two (basic) forms:
- if (_condition-expr_) _statement_ else _statement_ 
- if (_condition-expr_) _statement_ 
```
if (a < b) {
  result = a; // "true" branch
} else {
  result = b; // "false" branch
}
```
```
int i = ···; if (i < 0) {
  i = -i;   // "true" branch
}
```
- _condition-expr_ can be any expression whose result is of type (convertible to) bool, i.e. either true or false
- _statement_ can be a block, possibly including multiple statements 
◦ In fact, the statement should always be a block

### Bool
Type representing a boolean value 
- Set of values: _false_, _true_
- Operations: conjunction (_and_), disjunction (_or_), negation (_not_), ...
- Size: typically 1 byte
- Representation: like the ints 0 and 1
- Literals: false and true
```
bool b = true;
b = i == j; // the first "=" is an assignment, "==" means equality
bool b2 = i != 1234; // "!=" means inequality
bool b3 = b2 && i < j;    // "&&" means "and"
bool b4 = i < j || i < k; // "||" means "or"
bool b5 = !(i == j);      // "!" means "not"
```
- Note the use of parenthesis in !(i == j) to have the right precedence of application of operators

#### Logical operations 
<img width="650" alt="Schermata 2022-03-18 alle 19 09 28" src="https://user-images.githubusercontent.com/99679794/159059618-7c9cf79f-46d0-4636-a90c-ac9fb9752bc0.png">

### Scope 
The scope of a name appearing in a program is the, possibly discontiguous, portion of source code where that name is valid
- block scope
- function scope
- class scope
- namespace scope (including the global one) 
- ...

#### Block scope
- The scope of a name declared in a block starts at the point of declaration and ends at the }

```
{
···
  int num; // scope of num begins here
  std::cin >> num; // ok
} // scope of num ends here
std::cout << num;  // error
``` 

- The scope of a variable should be as small as possible
◦ Declare a variable only when it’s needed 
◦ If possible/meaningful, initialize it

## Is a number even? 
A program that reads a number from input and tells if it’s even

[https://github.com/elenasaso/Programmazione-ES/blob/866f85b45ef84ae9da8fc4a8e3caa1da7313508b/number_even.cpp]

## Exercise: the smallest of three numbers 
Write a program that reads three numbers from standard input and writes the smallest one to standard output

### while loop
```
while ( condition expr ) statement
```
- Execute repeatedly _statement_ until _condition-expr_ becomes false 
- _condition-expr_ is evaluated at the beginning of each iteration
- If _condition-expr_ is already false at the beginning, _statement_ is never executed
- _statement_ can be any statement, including of course a block
- _statement_ should modify something so that the evaluation of _condition-expr_ may change
- Otherwise the loop may never terminate

## [Integer square root (_while loop_)](https://github.com/elenasaso/Programmazione-ES/blob/4a6c8586e47224e3bed489506e8401e85bf13a42/integer_square_root_while.cpp)
Write a program that computes the integer square root of a non-negative integer number, i.e. the largest integer number whose square is not greater than the given number

<img width="350" alt="Schermata 2022-03-18 alle 17 55 07" src="https://user-images.githubusercontent.com/99679794/159047913-9fbf9f23-8910-408b-af57-ea5ebbcc8618.png">

## [Sum of the first N numbers (_while loop_)](https://github.com/elenasaso/Programmazione-ES/blob/a63a958cafd9053f9147863b8e77df6c71a8d2de/sum_first_N_numbers_while.cpp)
Write a program that reads a non-negative integer number N from standard input, computes the sum of the first N numbers and writes the result to standard output

### for loop
```
for ( init-statement; condition-expr<sub>opt</sub> ; expression<sub>opt</sub> ) statement 
```
- Execute _init-statement_, which may be a single
- If _init-statement_ contains declarations, the scope of the declared names is the loop
- Execute repeatedly statement until _condition-expr_ becomes false 
_condition-expr_ is evaluated at the beginning of each iteration
If _condition-expr_ is already false at the beginning, statement is never executed
But _init-statement_ is always executed
-  _expression_ is evaluated at the end of each iteration
-  _statement_ and/or _expression_ should modify something so that the evaluation of condition-expr may change
-  Otherwise the loop may never terminate
- A for loop can always be transformed into a while loop and viceversa
- Prefer a for loop when there is an obvious loop variable

## [Integer square root (_for loop_)](https://github.com/elenasaso/Programmazione-ES/blob/508abf20bc20c993d25c4f78cc017f6cb94ed47b/integer_square_root_for.cpp)

## [Sum of the first N numbers (_for loop_)](https://github.com/elenasaso/Programmazione-ES/blob/508abf20bc20c993d25c4f78cc017f6cb94ed47b/sum_first_N_numbers_for.cpp)

## Exercise: the smallest of N numbers
Write a program that reads an arbitrary sequence of numbers from standard input and writes the smallest one to standard output 
Hint 1: press Ctrl-D to tell the program there is nothing more to read from standard input
Hint 2: the expression std::cin.good() tells if it’s still possible to read something from std::cin

### Double 
Type representing a floating-point number
- Set of values: subset of R
- Operations: addition, subtraction, multiplication, division, comparisons, . . .
- Precision is about 16 decimal digits
- Literals in the form _sign<sub>opt</sub>  significand  exponent<sub>opt</sub>_
- 42.0 1. -1.5 12.34e3 -.34E-3 -1234e-2 ◦ ···en/···En means x10<sup>n</sup>

### Float
Type representing a floating-point number
- Set of values: subset of R
- Operations: addition, subtraction, multiplication, division, comparisons, . . .
- Precision is about 7 decimal digits
- Literals in the form _sign<sub>opt</sub>  significand  exponent<sub>opt</sub>_ F
- 42.0f 1.F -1.5f 12.34e3F -.34E-3f -1234e-2F 
- Same as double but with an f or F suffix

<img width="650" alt="Schermata 2022-03-18 alle 19 08 36" src="https://user-images.githubusercontent.com/99679794/159059382-68f9018d-8e45-44ef-b7e9-0a50109edcd1.png">

### Standard mathematical functions 
The cmath header includes many ready-to-use mathematical functions
- Exponential
- Power
- Trigonometric
- Interpolation
- Hyperbolic 
- Floating point manipulation and comparison
- ...
```
#include <cmath> 
...
double x = ...;
std::sqrt(x);
std::pow(x, .5); 
std::sin(x); 
std::log(x); 
std::abs(x);
``` 

### Type conversion 
- A value of type T1 may be converted implicitly to a value of type T2 in order to match the expected type in a certain situation
```
1 + 2.3
```
- Between numbers and bool, signed and unsigned numbers, numbers of different size, integral and floating point numbers, ...)
- Conversions sometimes are surprising
- Conversions can be explicit using static_cast
```
1 + static_cast<int>(2.3)
```
- Mechanims exist to define implicit and explicit conversions involving user-defined types

### const-safety
- Data qualified as const is logically immutable 
- Data that is meant to be immutable should be const 
```
int const x = 1'000'000'000; // or const int
std::cout << x + 32; // ok, read-only
x += 32; // error, trying to modify
int const y; // error, not initalized and not modifiable later
```
```
std::string const message = "Hello";
std::cout << message + "Elena"; // ok, read-only
message += "Elena"; // error, trying to modify
std::string const empty_message; //ok! empty string
```
Primitive types (e.g. int) and user-defined types (such as std::string) behave differently with respect to default initialization, i.e. without an explicit initial value
- User-defined types can define what default initialization means 
- For std::string it means “empty string”
- More later

## Functions 
A function abstracts away a piece of code that performs a well-defined task behind a well-definded interface.
A function associates a bloch of statements with 
- a name 
- a list of zero or more parameters 
A function may return a result 

Let's consider the code that computes the **integer square root**:
- Let's give it a name -> isqrt
- We pass isqrt a number -> the list of parameters has only one item of type int 
- isqrt computes a value that we want back -> the function returns a value of type int

<img width="500" alt="Schermata 2022-03-18 alle 21 14 04" src="https://user-images.githubusercontent.com/99679794/159077156-1c8948f5-dc23-49b0-a223-19b137f8c667.png">    <img width="500" alt="Schermata 2022-03-18 alle 21 14 13" src="https://user-images.githubusercontent.com/99679794/159077201-f85361cf-5f6d-42be-b309-0600380aea52.png">

- **A function needs to be declared/defined before its use**
```
return-type function-name ( parameter lyst );
return-type function-name ( parameter lyst ) { ... }

int isqrt(int);
double pow(double base, double exponenent);
void print(std::string);
int generate_random_number();
```
- Each parameter in the parameter list is of the form
_type name<sub>opt</sub>_
_type_ is mandatory, _name_ is optional
- Parameters are separated by commas
- The parameter list can be empty, i.e. ()
- The return statement returns the result (and the control) to the calling function
- If the function returns nothing, the return type is _void_

A function has only one entry point, but it may have multiple exit points, i.e. there can be multiple return statements
- For a function returning a non-void type -> **return _expression_;** // The result of expression must be convertible to the return type
- For a function returning void -> **return;** // In this case the return is optional (at the end of the function)

Calling/invoking a function is a type of expression of the form **_F(E1,E2,...,EN)_**
  - F is an expression that identifies a function, typically its name
  - Each E<sub>i</sub> is an expression, whose value is used to initialize the corresponding parameter (i.e. in the same position) in the function              declaration
```
  int s = isqrt(24);
  std::cout << count_words("Hello, " + name);
  print(std::to_string(pow(isqrt(24), 2)));
```
- A function can call other functions
- A function should not be too long; if it is, try to break it into multiple parts, each implemented as a function
- A function can call itself, directly or indirectly
  - This is called _recursion_
  - Often an elegant alternative to a loop 
  - Not easy to master, don’t abuse

### The main function
- The main (special) function is the entry point of a program 
- It can have two forms
  - int main() {···}
  - ...(seelater)
- If there is no return statement, an implicit return 0; is assumed
  - 0 means success, different from 0 means failure
  - Or use EXIT_SUCCESS and EXIT_FAILURE from cstdlib
- The exit value is available to the shell via the $? variable
 
## Exercises
- Write a function pow that takes two ints and computes and returns the value of the first (the base) raised to the power of the second (the exponent)
- Write a function gcd that takes two ints and computes the Gratest Common Denominator using the Euclid’s algorithm
- Write a function lcm that takes two ints and computes the Least Common Multiple
- Write a function is_prime that takes an int and tells if it’s a prime number
- More on edabit, leetcode, . . .
                 
### How do we know the code we write is correct?
- One of the most effective techniques is testing
  - Execute the code with reasonable and unreasonable input and see if it behaves according to the expectations
  - The purpose of testing is to (try to) **break** the code
- Here we focus on a form of testing called _**unit testing**_, where the units (of code) under test are, for example, functions
- There are many tools/frameworks to do unit testing (Google Test, Catch, Doctest, Boost.Test, . . . )
- Let’s use **Doctest**

### How to use Doctest
- On [godbolt](https://godbolt.org) it’s available selecting it under “Libraries”
- Otherwise download locally a single _header file_ into the directory containing your code, e.g. using wget or curl 
- At the top of your C++ file add the lines
```
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
```
- Don't add main into your file 
- After the code of the function(s) you have written, add lines like the following:
```
TEST_CASE("Testing isqrt") {
  CHECK(isqrt(0) == 0);
  CHECK(isqrt(9) == 3);
  CHECK(isqrt(10) == 3);
  CHECK(isqrt(-1) == 0);
···
}
```

### Memory layout of a process
- A process is a running program. 
When a program is started the operating system brings the contents of the corresponding file into memory according to well-defined conventions
- **Stack**
  - function local variables
  - function call bookkeeping
- **Heap**
  - dynamic allocation
- **Global data** 
  - literals and variables 
  - initialized and uninitialized (set to 0)
- **Program instructions**

<img width="200" alt="Schermata 2022-03-19 alle 12 15 12" src="https://user-images.githubusercontent.com/99679794/159118822-b7d4007d-8d64-497a-a5d4-b897c9aee184.png">

### Pass by value, return by-value
<img width="650" alt="Schermata 2022-03-19 alle 12 19 53" src="https://user-images.githubusercontent.com/99679794/159118991-c2d45e0f-40bd-4868-a7a4-d3f6afa0231c.png">

### Stack frame
- A piece of memory allocated and dedicated to the execution of a function
- It contains local variables (including function parameters), return address, saved registers, . . .
- Managed in a Last-In, First-Out (LIFO) way
- The size of the stack frame is **computed by the compiler**
- There is a special register (the stack pointer register, **%rsp**) that indicates the frame of the currently running function
- At runtime the allocation/deallocation of a frame consists simply in subtracting/adding that frame size to the stack pointer register

### Passing by value may be expensive
<img width="650" alt="Schermata 2022-03-19 alle 13 35 52" src="https://user-images.githubusercontent.com/99679794/159121380-4200d5e8-1d86-4b76-b1dc-8a083b981e5a.png">

### References (&)
A variable declared as a _**reference**_ of a type T is another name (an alias) for an existing object of type T
<img width="500" alt="Schermata 2022-03-19 alle 13 38 53" src="https://user-images.githubusercontent.com/99679794/159121456-b5bd2400-e15b-45c7-9b1c-a3fd3309a591.png">

<img width="500" alt="Schermata 2022-03-19 alle 13 37 49" src="https://user-images.githubusercontent.com/99679794/159121421-32ec36f8-e8a8-44d3-9d58-5dfb852c34c0.png">

<img width="500" alt="Schermata 2022-03-19 alle 13 39 07" src="https://user-images.githubusercontent.com/99679794/159121463-e2523177-da80-4ec6-ae2d-5bbd43fee453.png">

```
int i = 12; 
int j = 56;
int& ri = i; // reference declarator
ri == 12; // true
ri = 34;
ri == 34 && i == 34  // true
ri == j;
ri == 56 && i == 56 // true
int& r; // error
```
- A reference must be initialized to refer to a valid object
- A reference cannot _rebind_ (be re-associated) to another object
- For a given type T, T& is a compound type, distinct from T

### Recap: passing by value vs passing by reference
Think of the coffe in the cup as the data in a variable. One is a copy and one is the original
![pass-by-reference-vs-pass-by-value-animation](https://user-images.githubusercontent.com/99679794/159121128-a2494106-8f99-4fc9-a9a8-4de36d4b678c.gif)
#### Pass by reference
Pass by reference (also called pass by address) means to pass the reference of an argument in the calling function to the corresponding formal parameter of the called function so that a copy of the address of the actual parameter is made in memory, i.e. the caller and the callee use the same variable for the parameter. **If the callee modifies the parameter variable, the effect is visible to the caller’s variable.**

Overview:
1. Passes an argument by reference.
2. Callee gives a direct reference to the programming element in the calling code.
3. The memory address of the stored data is passed.
4. Changes to the value **have an effect** on the original data.

#### Pass by value 
Pass by value means that **a copy of the actual parameter’s value is made in memory**, i.e. the caller and callee have two independent variables with the same value. If the callee modifies the parameter value, the effect is not visible to the caller.

Overview:
1. Passes an argument by value.
2. Callee does not have any access to the underlying element in the calling code.
3. A copy of the data is sent to the callee.
4. Changes made to the passed variable **do not affect** the actual value.

### const and references
```
std::string name = "Elena";
std::string& rname = name; // ok, can read/modify name via rname
std::string const& crname = name; // ok, crname is a read-only view of name
```
```
std::string const name = "Elena";
std::string& rname = name; // error, could modify via rname
std::string const& crname = name; // ok, can only read name via crname
```

### How to pass arguments to functions 
- For input parameters 
  - If the type is primitve, pass by value
```
int isqrt(int n); // good
int isqrt(int const& n); // bad!
```
  - Otherwise, pass by const reference
```
int count_words(std::string const&);
```
- For input-output or output parameters, pass by non-const reference
```
void to_lowercase(std::string& s);
void read_from_cin(int& n)
```

### Function overloading
- Multiple functions can have the same name
- But different lists of parameters (number and/or types)
- The compiler chooses the function that best matches the arguments in the call
  - It usually does what is expected, possibly applying appropriate implicit conversions, but not always
  - Compilation error if there is no match or no unique best match
- The return type doesn’t matter

```
void foo(int);
int foo(int, char);
bool foo(double);
int foo(std::string s);

foo(0); // call foo(int)
foo(0, 'O'); // call foo(int, char)
foo(0,); // call foo(double)
foo(std::string{}); // call foo(std::string)
foo(0L); // long int, ambigous, error
foo('a'); // call foo(int)
foo("a"); // call foo(std::string)
```
**NB.** 
- When used as a function return type, the _**void**_ keyword specifies that the function doesn't return a value. When used for a function's parameter list, void specifies that the function takes no parameters. When used in the declaration of a pointer, void specifies that the pointer is "universal".
- _**foo**_ is used as a place-holder name, usually in example code to signify that the object being named, or the choice of name, is not part of the crux of the example.

### Conditional/ternary operator expression
_expression<sub>condition</sub>_ ? _expression<sub>true</sub>_ : _expression<sub>false</sub>_
```
int gdc(int a, int b)
{
return (b == 0) ? a : gdc(b, a % b);
}
```
NB. gdc computes the greatest common divisor of the integers a and b
- Evaluate expression<sub>condition</sub>, whose value is of type (convertible to) bool
- If true, expression<sub>true</sub> is evaluated and the resulting value is the value of the whole expression
- If false, expression<sub>false</sub> is evaluated and the resulting value is the value of the whole expression
- Similar to an if statement, but usable (and useful) where only an expression is allowed
- The types of expression<sub>true</sub> and expression<sub>false</sub> are subject to some constraints, but let’s assume that they have to be the same

### break and continue for loops
- Within a loop block, the **break** statement allows to terminate the loop
- Within a loop block, the **continue** statement allows to jump to the end of the current iteration of the loop
- The same effect can be obtained with appropriate use of conditionals, but the resulting code may be more complicated

### Object initialization with braces
- An object can be initialized specifing its value between {}
```
int i{123};
float f{123.F);
std::strinf s{"hello"};
```
- Introduced as a _universal_ form of initialization that could replace all others, but there are situations where it’s not usable
- Protects against _narrowing_, i.e. loss of information caused by implicit conversions
```
double d{1.}; // ok, no conversion
float d1{1.} // ok, no information loss
float f2{d}; // error
float f3{9'999'999};  // ok, no information loss
float f3{99'999'999}; // error
int i{1.};            // error
int g{d};             // error
```

### char 
Type representing a character
- Set of values: letters in the alphabet (lower- and upper-case), digits, punctuation marks, some special characters, . . .
- Size: typically 1 byte, but not necessarily
- Literals: characters between single quotes
  - 'a' 'B' '7' ',' '?' '#' '/'
- Some character literals need to be expressed as \-escaped sequences
  - '\'' '\\' '\n' '\t' '\0'
- A char is an integral type so it supports integral operations
  - ``` std::cout << '9' - '0'; // 9 ```
  - ``` c < 'z'; ```

### _range-for_ loop
``` for ( range-declaration : range-expression ) statement ```
- Simplified form of a for loop, to iterate on all the elements of a _range_ (sequence), such as a string of characters
- Execute repeatedly _statement_ for all the elements of the range
- _range-declaration_ declares a variable of the same type of an element of the range
  - Can (and should) be a (const) reference
- _range-expression_ represents the range to iterate over
- More on ranges later
```
std::string s{"Hello!"};
for (char& c : s) {
  c = std::toupper(c);
}

for (int i: {1, 2, 3, 4, 5}) {
  std::cout << i << ' ';
}
```
NB. _**std**_::toupper converts the given character to uppercase according to the character conversion rules defined by the currently installed C locale.
In the default "C" locale, the following lowercase letters abcdefghijklmnopqrstuvwxyz are replaced with respective uppercase letters ABCDEFGHIJKLMNOPQRSTUVWXYZ.

### Exercises 
- Write a function that takes a char and returns the corresponding lowercase character if it is a letter; the same char otherwise
  - e.g. 'A'→'a','a'→'a',';'→';'
- Write a function that takes two numeric operands of type double and one operator of type char and returns the result of applying that operator to the two operands. For example if the two operands have values 2.0 and 3.0 respectively and the operator has value '+', then the function returns a result with value 5.0. If the operator is invalid, the function returns 0.

### Returning a reference
- A function can return a reference only if the referenced object survives the end of the function
  - In the caller, the reference would refer to an object that doesn’t exist anymore
- In particular do not return a reference to a function local variable
```
// bad
int& add(int a, int b)
{
  int result = a + b;
  return result;
}
```
```
int& increment(int& a) // ok
{
++a;
return a; 
}
```
- Useful to compose multiple function calls on the same object
```
std::string s{···}; 
trim_left(trim_right(tolower(s)));
```
NB. 
- trim_left(): Removes all leading white spaces from the string.
- trim_right(): Removes all trailing white spaces from the string.
- trim(): Removes all leading and trailing white spaces from the string.
- tolower(): Convert uppercase letter to lowercase using locale

### Data abstraction
- The C++ language has a strong focus on building lightweight data abstractions
  - The source code can use terminology and notation close to the problem domain, making it more expressive
  - There is little (if any) overhead in terms of space or time during execution
- class and struct are the primary mechanism to define new compound types on top of fundamental types

### Data structure
Let's introduce a type to represent complex numbers
```
struct Complex {
  double r; // data member
  double i;
};

double norm2(Complex c);
Complex sqrt(Complex c);
Complex c{1., 2.};
double n = norm2(c);
Complex c2 = sqrt(c);

Complex& cr = c; // reference
double norm2(Complex c) {
  return c.r * c.r + c.i * c.i;
}

double norm2(Complec const& c) {
  return c.r * c.r + c.i * c.i;
}
```
- A complex is composed of two doubles
- The . (dot) operator allows to access a member of an object of class type (such as struct)

> #### Struct
> - C++ struct, short for C++ Structure, is an user-defined data type. 
> - It allows a user to combine data items of (possibly) different data types under a single name.
> - C++ structs are different from _arrays_ because arrays only hold data of similar data-types; C++ struct, on the other hand, can store data of multiple > data-types.
> - Each element in the structure is called a _member_.

### Operations 
It's possible to define operations on user-defined types
```
struct Complex {
  double r; 
  double i;
};

bool operator==(Complex const& a, Complex const& b) {
  return a.r == b.r && a.i == b.i;
}

Complex operator+(Complex const& a, Complex const& b) {
  return Complex{a.r + b.r, a.i + b.i};
}

c2 = c1 // generated by the compiler, if used
c1 == c2
c1 + c2
z = z * z + c
2. * c1
... 
```

### Operator overloading
- C++ offers the possibility to define the meaning of most of the operators available for fundamental types when applied to user defined types
- Syntactically this is done via the definiton of appropriate functions 
- Given an operator @, the function name is called operator@
- Although there are some constraints on the number and types of the parameters and on the type of the return value, the overloaded operators are just functions
- The behaviour of the overloaded operator should reproduce the behaviour of the original one 
- Some behaviours cannot be changed, e.g. associativity

## Exercises 
- Define some other operators and functions for Complex
- Write a function to compute the solutions of an equation of the form ax2 + bx + c = 0, given the three coefficients

### auto
Let the compiler deduce the type of a variable from the initializer, i.e. from the expression used to initialize the object
```
auto z; // error, no initializer
auto i = 0; // int
auto const f = 0.F; // float const
auto r = i + f; // float 
auto c = Complex{1, 2}; // Complex
auto& rc = c; // Complex&
auto const& cri = i; // int const&
auto j = ri; // int - auto never deduces a reference
auto& g = f; // float const& - the constness is preserved
auto& rcr = c.r; // double&
auto& crcr = std::as_const(c).r; // double const&
``` 

### auto/trailing return type
- When the return type of a function is auto the compiler will deduce it from the return statement(s)
  - Only usable in a function definition
```
auto isqrt(int n)
{
  int result;
  ...
  return result;
}
```
- If there are multiple return statements their expressions must have the same type
- Trailing return type
```
int foo(...);
auto foo(...) -> int; // equivalent
```

### More data abstraction 
Imagine to change the Complex tyope to use the polar form
```
struct Complex {
  double rho;
  double theta;
};
```
- As a consequence, all client code has to change 
``` 
double norm2(Complex const& c) { return c.rho * c.rho }; 
```
- Not all combinations of (ρ, θ) are valid 
  - ρ ≥ 0, θ ∈ [0,2π]
```
Complex c{-1; -1}; // valid?
c.rho = -1; // valid?
```
- We wish we could 
  - have more isolation between client code and implementation
  - enforce an internal relation (_class invariant_) between data members

### Private representation, public interface
See slides (page 102-106)

### Member vs free function
```
class Complex {
  public:
    double norm 2() const { // member function
      return r * r + i * i;
    }
    ...
};

double norm2(Complex const& c) { // free function
  return c.real() * c.real() + c.imag() * c.imag();
}

Complex c{...};
c.norm2(); // call the member function
norm2(c); // call the free function
```
- The public part of a class should ideally provide a safe, efficient and complete interface, yet minimal 
- Prefer a free function, if possible 
  - Extend the functionality of a class without modifying existing code

### Construction 
- A constructor should initialize the data members in order to establish the _class invariant_
- The default constructor can be automatically generated by the compiler, but only if there are no other constructors

### operator@ in terms of operator@=
- Typically, a symmetric operator@ (e.g. operator+) is implemented in terms of a member operator@= (e.g. operator+=)
```
Complex operator+(Complex const& lhs, Complex const& rhs)
{
  Complex result{lhs}; // create the result as a copy of lhs
  result += rhs; // add rhs to the result
  return result; // return it
}
```
- Typically, operator@= returns a reference to the object being operated on
```
class Complex {
  ...
  Complex& operator+=(Complex const& rhs) {
    r += rhs.r; i += rhs-i;
    return *this;
  }
};
```
* this means _self_, see later in the course

## Example: rational numbers
- Let's implement a class to represent rational numbers
- The representation is with two integers, such that
  - The fraction is irreducible, i.e. their GDC (Greatest Common Denominator) is one
  - If the number is negative, the sign is kept in the numerator 
  - The denominator is different from 0
```
class Rational
{
  int n_;
  ind d_;
 public:
  Rational(int num = 0, int den = 1) : n_{num}, d_{den}
  {
    if (d_ == 0) {
    // conscruction must fail 
    }
    // reduce
    auto const g = std::gcd(n_, d_); // in <numeric>
    n_ /= g;
    d_ /= g;
    // fix sign
    if (d_ < 0) {
      n_ = -n_;
      d_ = -d_;
    }
  }
  ...
};
```

### Class invariant 
- A **class invariant** is a relation between the data members of a class that constraints the values that such members can assume
  - It defines what is a valid state for an object of that class
  - It must always hold for an object of that class
- The invariant is established by the constructor
- The invariant is preserved by **public** methods
  - The invariant holds when the function is entered -> the implementation can make assumptions
  - The invarian may be violated during the execution of the function

### assert
Check that a certain boolean expression is satisfied at run time 
- for examble, a class invariant at the end of a constructor or a condition at the beginning of a function (a _pre-condition_)
```
#include <cassert>

class Rational {
  ...
  Rational(int num = 0, ind den = 1) : n{num}, d{den} {
    ...
    assert (std::gcd(n, d) == 1 && d > 0);
  }
  Rational& operator/=(int n) {
    assert(n != 0);
    ...
 }
};

bool operator==(Rational const& 1, Rational const& r)
{
  assert(std::gcd(1.num(), 1.den()) == 1 && std::gcd(r.num(), r.den()) == 1);
  return 1.num() == r.num() && 1.den() == r.den();
}
```
- If the asserted condition is not satisfied, it means that the state of the program does not conform to the expectations of the programmer, i.e. to the design
- The state may even be corrupteed -> it's probably wiser to ```terminate``` the program as soon as possible to avoid causing damage
- Useful during testin/debugging
- Can be disabled for performance reasons (g++ DNDEBUG ...)
  - Avoid side effects in asserts (e.g. assignements or calls to non-const methods), because they would disappear from the executable
- assert (but also Doctest's CHECK) is a _preprocessor macr_
- Macros obey syntactic rules that are different from those of C++ proper
```
assert(Rational{1,2} == Rational {2,4}); // error (*)
assert(Rational(1,2) == Rational (2,4)); // ok
assert((Rational{1,2} == Rational {2,4})); // ok
```
( * ) macro "assert" passed 3 arguments, but takes just 1
- Macros _expand_ to arbitrary text, which is then passed to the real C++ compiler

### Exceptions
- Exceptions provide a general mechanism to:
  - notify the occurrence of an error in the program execution
    - using a throw expression
  - transfer control to a handler defined in a previous function in the call chain
    − using a try/catch statement
- Exceptions help separate application logic from error management 
- A typical use is in constructors and operators
- Exceptions cannot be ignored 
  - If a handler is not found the program is terminated
```
struct E {};

auto low() {
  ... // this part is executed
  throw E{};
  ... // this part is not executed
}

auto mid() {
  ... // this part is executed 
  low ();
  ... // this part is not executed
}

auto high() {
  try {
    ... // this part is executed
    mid();
    ... // this part is not executed
  } catch (E& e) {
    ... // use e
  }
}
```
- An exception is an object
- After being raised (thrown), an exception is propagated up the stack of function calls until a suitable catch clause (handler) is found
- If no suitable handler (i.e. one compatible with the type of exception) is found, the program is terminated
- Exceptions should be caught by (const) reference
- During _stack unwinding_ the stack frames are properly cleaned up
