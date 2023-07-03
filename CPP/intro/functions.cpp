#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// functions need to be declared before the main function
int addition (int a, int b) {
    int r;
    r = a + b;
    return (r);
}

int subtraction (int a, int b) {
    int r;
    r = a - b;
    return (r);
}

void printmessage () {
    cout << "This is a void function";
}

// instead of working with the values, 
// we can work directly with the actual variables that are passed in 
void duplicate_ref (int& a) {
    a*=2;
}

// this function will not impact the actual variables that are sent in
void duplicate_non (int a) {
    a*=2;
}

// if the function does not have a value, 3 will be the default
void duplicate_default (int a = 3){
    a*=2;
}

// main() is where program execution begins.
int main() {
    int z; 
    z = addition(5,3);
    cout << "The result is " << z << "\n";
    int q;
    q = subtraction(5,3);
    cout << "The result is " << q << endl;
    duplicate_non(z); //remember this is '8'
    cout << "The result is " << z ;

    return 0; 
}

