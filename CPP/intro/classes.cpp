#include <string>
#include <iostream>

using namespace std;

// this is the class declaration format
class CRectangle { 
    // a CRectangle is defined by its x and y value
    int width, height; 

    // these are the public functions that the class can do
    public:
        CRectangle(); 
        CRectangle (int,int); //constructor
        CRectangle operator + (CRectangle); //operator overload
        void set_values (int,int); 
        int area () {return ((width) * (height));} 
        static int rectangle_num; // variable that is accessible between classes
};

int CRectangle::rectangle_num = 0;


//The constructor function written outside the class scope
CRectangle::CRectangle (int a, int b) {
    width = a; 
    height = b; 
    rectangle_num++;
} 

// An example of overloading a constructor
// depending on the context of the function, the constructor will behave accordingly
// When declaring a default function, don't include the parantheses
CRectangle::CRectangle () { 
 width = 5; 
 height = 4; 
 rectangle_num++;
} 

CRectangle CRectangle::operator + (CRectangle param) { 
    CRectangle temp(5,5); 
    temp.width = width + param.width; 
    temp.height = height + param.height; 
    rectangle_num--;
    return (temp); 
}

//This is a function of CRectangle defined outside of the class
//Needs to match the function prototype within class
void CRectangle::set_values (int a, int b) { 
    width = a; 
    height = b; 
} 

int main () {
    CRectangle rect (3,4), rectb;
    cout << "rect area: " << rect.area() << endl; 
    cout << "rectb area: " << rectb.area() << endl; 

    CRectangle rect_sum;
    cout << "rect_sum area: " << rect_sum.area() << endl;
    rect_sum = rect + rectb; //something is wrong here
    cout << "rect_sum area: " << rect_sum.area() << endl;
    cout << "number of objects: " << CRectangle::rectangle_num << endl;
 
    return 0;
}


// I will need to practice dynammic memory allocation. 