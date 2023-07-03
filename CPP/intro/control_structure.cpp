#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// main() is where program execution begins.
int main() {
    /*
    //if-else statements, based on a logical operator
    cout << "Enter a number:\n";
    int x;
    cin >> x;
    if (x == 100) {
        cout << "x is 100\n";
    }
    else if (x > 50){
        cout << "x is greater than 50\n";
    }
    else {
        cout << "x is not 100\n";
    }
    */

   //while loop useful as long as a condition is set. 
   //good when the loop is not a set amount of times before hand. 

    /* int n;
    cout << "Enter the starting number > "; 
    cin >> n; 
    
    while (n>0) { 
        cout << n << ", "; 
        --n; 
        // so this will decrement the number as it goes.
    } 
    */

   //the do-while loop is useful for preforming something 
   //before the condition is checked out. 

   /*int n;
    cout << "Enter the starting number > "; 
    cin >> n; 
    
    do {
        
        cout << n << ", "; 
        --n; 
        // so this will decrement the number as it goes.
    }
    
    while (n>0);
    */

    //for-loops are for iteration that is well defined 

    /*for (int i = 10; i>0; i--) {
        cout << i << ",";
    }
        cout << "\n";

    //changing the syntax will change how things behave
    for (int i = 10; i>=0; i--) {
        cout << i << ",";
    }
        cout << "\n";

    for (int i = 10; i>0; --i) {
        cout << i << ",";
    }
        cout << "\n";
    */

   //sometimes we will need to stop a loop prematurely
   //especially if we find what we are looking for. 
   //I'll challenge myself here, 
   //let's break out of a for loop when we reach the first perfect square
   
    /* int start_num;
    cout << "Enter a starting number:";
    cin >> start_num; 
    for ( int i = start_num; i > 0; i-- ){
        cout << i << "\n";
        float result = sqrt(i);
        if(result == int(result)){
            cout << "found the perfect square";
            break; // this will finish out the loop 
        }

   }*/

    int start_num;
    cout << "Enter a starting number:";
    cin >> start_num; 
    for ( int i = start_num; i > 0; i-- ){
        cout << i << "\n";
        float result = sqrt(i);
        if(result == int(result)){
            cout << "found the perfect square\n";
            continue; // this will let the loop finish, so we can identify the perfect square  
        }

   }



    
    return 0;
}