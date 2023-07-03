#include <iostream>
#include <string>
using namespace std;

// main() is where program execution begins.
int main() {
   // 'printf' prints Hello World to the console. 
   printf("Hello World\n"); 
   
   // The basics of variables
   short a = 5; // starting a new variable? must start out as an identifier!
   short b = 2; // short is used for smaller variables
   a = a + 1; 
   short result = a - b;
   cout << result << endl; //answer should be '4' 5+ 1 - 2 
   
   // 'strings' are useful for working with longer text. 
   string mystring = "This is a string\n"; 
   cout << mystring << endl;
   mystring = "We just changed the string";
   cout << mystring << endl;
   

   // 'constant' variables can be declared, 
   // but do not change after their initiation
   const int age = 65; 
   const char tabulation = '\t';

   // to make arithmetic shorter, we can utilize compund assignment
   short fog = 20;
   fog += 5; // should equal 25 
   fog -= 9; // 16
   fog /= 4; // 4
   cout << fog << endl;

   // Something that could be potentially useful
   // is the 'conditional operator'

   7==5 ? 4 : 3; //if true return 4, false return 3

   //Type casting to change one type to another type
   int s;
   float pi = 3.14;
   s = (int) pi;
   // int(pi) would achieve the same thing

   cout << s << endl;

   //Working with std input and output
   //we already have used the command cout previously
   int i; 
   cout << "Please enter an integer value: "; 
   cin >> i; 
   cout << "The value you entered is " << i; 
   cout << " and its double is " << i*2 << ".\n";

return 0;}