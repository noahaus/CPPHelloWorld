#include <string>
#include <iostream>

using namespace std;

/* class CRectangle { 
    int width, height; 
    public: 
        void set_values (int, int); 
        int area () {return (width * height);} 
        friend CRectangle duplicate (CRectangle); //why does it need to be a friend?
}; 
void CRectangle::set_values (int a, int b) { 
    width = a; 
    height = b; 
}

CRectangle duplicate (CRectangle rectparam) // this is a regular method which can work without outside the scope of the class
{ 
    CRectangle rectres; 
    rectres.width = rectparam.width*2; 
    rectres.height = rectparam.height*2; 
    return (rectres); 
} 
int main () { 
    CRectangle rect, rectb; 
    rect.set_values (2,3); 
    rectb = duplicate (rect); 
    cout << rectb.area() << endl; 
    return 0; 
} */

// virtual members

class CPolygon { 
    protected: 
    int width, height; 
    public: 
        void set_values (int a, int b) 
        { width=a; height=b; } 
    //virtual int area () { return (0); } // the virtual member will allow you to refer to the most recent member 
    virtual int area () = 0; // this declaration creates an abstract class. 
 }; 

class CRectangle: public CPolygon { 
    public: 
    int area () 
        { return (width * height); } 
 }; 

class CTriangle: public CPolygon { 
    public: 
        int area () 
        { return (width * height / 2); } 
 }; 

int main () { 
    CRectangle rect; 
    CTriangle trgl; 
    //CPolygon poly; // as an abstract class, we cannot initiate this  
    CPolygon * ppoly1 = &rect; 
    CPolygon * ppoly2 = &trgl; 
    //CPolygon * ppoly3 = &poly; 
    ppoly1->set_values (4,5); //will use the CRectangle area function
    ppoly2->set_values (4,5); //will use the CTriangle area function
    //ppoly3->set_values (4,5); //will use the CPolygon area function
    cout << ppoly1->area() << endl; 
    cout << ppoly2->area() << endl; 
    //cout << ppoly3->area() << endl; 
    return 0; 
} 