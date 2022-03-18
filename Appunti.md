## Learn to program in C++

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

## Hello
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
  - Or use EXIT_SUCCESS and EXIT_FAILURE from <cstdlib>
  - The exit value is available to the shell via the $? variable
```
#include <cstdlib>
int main() 
{
  int n;
  std::cin >> n;
  if (std::cin.fail() || n < 0) {
    std::cerr << "Invalid number\n";
    return EXIT_FAILURE;
  }
  ···
 }
```
   
                 
                 
  
