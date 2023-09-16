#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void increase (void* data, int psize) // makes more sense as a parameter declaration
{ 
 if ( psize == sizeof(char) ) 
 { char* pchar; pchar=(char*)data; ++(*pchar); } 
 else if (psize == sizeof(int) ) 
 { int* pint; pint=(int*)data; ++(*pint); } 
} 

int addition (int a, int b) 
{ return (a+b); } 
int subtraction (int a, int b) 
{ return (a-b); } 
int operation (int x, int y, int
(*functocall)(int,int)) 
{ 
 int g; 
 g = (*functocall)(x,y); 
 return (g); 
}
// main() is where program execution begins.
int main() {

    //when we declare a variable, we don't really care where in memory it goes
    //it will be helpful in some cases to know where the variable is in relation to 
    //other memory bites.

    //the address of memory is referend to as a reference to that variable
    //it is denoted as '&', and the variable that holds that reference 
    //is a pointer, defined as '<type> *'

    /* int andy = 25; 
    int fred = andy;
    int* ted = &andy;

    cout << fred << endl;
    cout << ted << endl;

*/ 

/*

    int firstvalue, secondvalue; //variables set without a value
    int * mypointer; //
    mypointer = &firstvalue; // mypointer now has the value of the memory location of firstvalue. its POINTING to it
    cout << "mypointer is " << mypointer << endl;
    cout << "mypointer is " << *mypointer << endl;
    *mypointer = 10; 
    cout << "mypointer is " << mypointer << endl; //the physical memory location hasn't changed
    cout << "mypointer is " << *mypointer << endl; //the value in that physical memory location has changed tho
    mypointer = &secondvalue; //now mypointer is POINTING to the address of secondvalue
    *mypointer = 20; //change the value in the address of secondvalue
    cout << "firstvalue is " << firstvalue << endl; 
    cout << "secondvalue is " << secondvalue << endl;
*/

// an interesting behavior is that pointers and arrays act very similarly to each other
// the pointer will save the value of the first element in an array,
// and the [] will offset the value based on the memory location

/*
    // this doesn't work without the 'const' 
    const char * terry = "hello";
    cout << *(terry+4) << endl;
    cout << terry[4] << endl;

    // there is also the void pointer type, which can be useful
    // it essentially allows a pointer to be any type
    // but requires that the assignment of a value be cast from the pointer    
    char a = 'x'; 
    int b = 1602;
    increase (&a,sizeof(a)); 
    increase (&b,sizeof(b));

    cout << a << endl;
*/

// last thing to keep in mind is that pointers can point to functions
// I can imagine this being useful if you need a function to have various behavior,
// I don't see myself using this, maybe could be useful for classes?
    int m,n; 
    int (*minus)(int,int) = subtraction; 
    m = operation (7, 5, addition); 
    n = operation (20, m, minus); 
    cout << n << endl;

    return 0;
}

