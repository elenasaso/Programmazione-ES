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

