#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    char* name;
    int age;
    void (*introduce)(struct Person*);
    void (*birthday)(struct Person*);
} Person;

//method_1
void person_introduce(Person* self) {
    printf("Hi, I'm %s, %d years old\n", self->name, self->age);
}

//method_2
void person_birthday(Person* self) {
    self->age++;
    printf("%s is now %d years old\n", self->name, self->age);
}

/*

constructor -> Initialized the struct elements with required values

variables will get assigned with values
Function pointers will get assigned to functions (replicating Java Class's methods)

*/
Person* constructor(const char* name, int age) {
    Person* p = malloc(sizeof(Person));
    p->name = strdup(name);
    p->age = age;
    
    p->introduce = person_introduce;
    p->birthday = person_birthday;
    
    return p;
}

//destructor
void destructor(Person* p) {
    free(p->name);
    free(p);
}

int main() {
    Person* Data = constructor("Vaseem", 23);
    
    Data->introduce(Data);
    Data->birthday(Data);
    
    destructor(Data);
    return 0;
}

/*

OUTPUT:
Hi, I'm Vaseem, 23 years old
Vaseem is now 24 years old


Tried to replicate Java Classes.

------------------------------------------------

In Java:

class MyClass{

    variable_1
    variable_2

    method_1(){
    
    }

    method_2(){
    
    }

}

MyClass myObject = new MyClass(5, "hello");
myObject.getSquare();
myObject.getUpperCaseText();

------------------------------------------------

In C:

struct MyClass{

    variable_1
    variable_2

    functionPointer_1(); //replicating methods
    functionPointer_2(); //replicating methods
}

method_1
function_1(){

}

method_2
function_2(){

}


int main(){
    Person* Data = constructor("Vaseem", 23);

    Data->introduce(Data);
    Data->birthday(Data);

    destructor(Data);



}




*/