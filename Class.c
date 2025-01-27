#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to have data and function pointers
struct class {
    // Attributes and Data
    int data;
    void *dynamic_data;
    int dynamic_data_size;

    // constructor and destructor
    void (* constructor)(struct class *this, int data_size);
    void (* destructor)(struct class *this);

    // Methods/Member functions
    int  (* get_data_attribute)(struct class *this);
    void (* set_dynamic_data_method)(struct class *this, char* name);
    void (* get_dynamic_data_method)(struct class *this);
};


// Functions to be used as part of the object
int get_attribute(struct class *this) {
    return this->data;
}

void set_dynamic_data(struct class *this, char* name) {
    strcpy(this->dynamic_data, name);
}

void get_dynamic_data(struct class *this) {
    printf("%s\n", (char *)this->dynamic_data);
}

void class_exit(struct class *this) {
    free(this->dynamic_data);
}

// Function that would serve as constructor
void class_init(struct class *this, int data_size) {
    // Set some initial value
    this->data = 42;

    // Allocate memory for the dynamic data
    this->dynamic_data = malloc(data_size);

    // Assign all the functions to the pointers
    this->get_data_attribute = get_attribute;
    this->set_dynamic_data_method = set_dynamic_data;
    this->get_dynamic_data_method = get_dynamic_data;

    // Assign the function that will serve as destructor
    this->destructor = class_exit;
}

// Example usage
void main() {
    struct class object;

    // Just assign the constructor
    object.constructor = class_init;

    // Constructor is ready to use, 7 == sizeof("vaseem")
    object.constructor(&object, 7);

    // Call member functions
    object.set_dynamic_data_method(&object, "vaseem");
    object.get_dynamic_data_method(&object);
    printf("Attribute Vale: %d\n", object.get_data_attribute(&object));

    // Call destructor
    object.destructor(&object);
}