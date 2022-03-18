## Imparare a programmare in C++

#### Compilare e rinominare 
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
#### Formattare
```
clang-format minimal.cpp // serve per formattare il codice e renderlo più leggibile
int main ( )
```
#### Input/Output
- One mechanism offered by C++ to do input and output is the I/O streams interface, which allows the creation and the manipulation of stream entities
- Input and output streams connected to the terminal are automatically available to a program
◦ std::cin, std::cout (and std::cerr for errors)
- To extract values, use the stream operators >>
- To insert values, use the stream operators <<

## Hello
Dall'editor:
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
Dal terminale:
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
◦ has a storage duration/lifetime
◦ has a type
◦ can have a name
 
 #### Types
- A type givees meaning to a piece of storage 
- A type identifies a set of values and the operations that can be applied to those values
◦ C++ is a strongly typed language (mostly)
- The compiler checks that program instructions are compatible with the type system
◦ C++ is a statically typed language (mostly)
- C++ defines a few fundamental types and provides mechanisms to build compound types on top of them

#### Fundamental Types
- Arithmetic types: int, char, bool
- Floating-point types: float, double 
- std::nullptr_t
- void

<img width="646" alt="Schermata 2022-03-18 alle 14 37 17" src="https://user-images.githubusercontent.com/99679794/159012846-96b3056f-166b-4888-95ec-0b373dd30361.png">

### Variables
- A variable is a NAME for an object
- A name is an identifier: a sequence of letters (including _ ) and digits, starting with a letter
◦ Avoid _ at the beginning 
◦ Choose meaningful names

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
◦ "hello" "hello'\n'world" "hello \"world\"" 
◦ \n means “newline”
• The type of a string literal is **not** std::string

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
<img width="645" alt="Schermata 2022-03-18 alle 14 52 09" src="https://user-images.githubusercontent.com/99679794/159015306-ddee6efd-3484-4d73-987f-52a4a95f7f69.png">

## Sum of two numbers 
[https://github.com/elenasaso/pf2021/blob/5d540d0a46f313a710d4482591b7ed0c162c0e42/sum_two_numbers.cpp]

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

## The smallest of two numbers 
A program that reads two numbers from input and writes the smallest to output

[https://github.com/elenasaso/Programmazione-ES/blob/94cf40488376963b84b1e2cb8b032fff203d0289/smallest_two_numbers.cpp]

### If then else
- Selection statement to choose one of two flows of control depending on a boolean condition
- Two (basic) forms:
◦ if (_condition-expr_) _statement_ else _statement_ 
◦ if (_condition-expr_) _statement_ 
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
<img width="989" alt="Schermata 2022-03-18 alle 17 43 20" src="https://user-images.githubusercontent.com/99679794/159045990-e404834c-2586-4ff7-a46b-c05524e56712.png">

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
  int num;         // scope of num begins here
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
