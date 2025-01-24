# Object-Like Struct Implementation in C 

`(JavaLikeClassImplementationInC.c)`

## Overview
Object-oriented programming in pure C using structs, function pointers, and manual memory management. It creates a `Person` struct with methods that mimic class-like behavior typically found in object-oriented languages like Java.

## Features
- Custom constructor for creating `Person` instances
- Function pointers to simulate class methods
- Dynamic memory allocation
- Simple lifecycle management with constructor and destructor

## Code Structure

### `Person` Struct
- Contains fields:
  - `name`: Person's name (dynamically allocated string)
  - `age`: Person's age
  - `introduce`: Function pointer for introduction method
  - `birthday`: Function pointer for age increment method

### Methods
- `person_introduce()`: Prints person's name and age
- `person_birthday()`: Increments age and prints updated information

## Memory Management
- `constructor()`: Allocates memory and initializes a `Person`
- `destructor()`: Frees allocated memory to prevent leaks

## Usage Example
```c
Person* person = constructor("Vaseem", 23);
person->introduce(person);    // Prints introduction
person->birthday(person);     // Increments age
destructor(person);           // Cleanup
```

## License
Open source. Use and modify as needed.
