# ENCAPSULATION
-notes taken from https://www.geeksforgeeks.org/encapsulation-in-c/

## What is it?
- binding together the data and functions that manipulates them.

Encapsulation also brings up that idea of data abstraction or hiding.

Example:
```
#include <iostream>
using namspace std;

class ExampleE
{
//hidden within the class
  private:
      int x;
      int y;
  public:
      //set the values of x and y
      void setVal(int r, int s)
      {
          x = r;
          y = s;
      }
      
      //returns the value of x
      int getX()
      {
          return x;
      }
      
      //returns the value of y
      int getY()
      {
          return Y;
      } 
};

int main()
{
    ExampleE K;
    
    K.setVal(18, 4);
    
    cout << "x: " << K.getX() << " y: " << K.getY() << endl;
    
    return 0;
}
```

OUTPUT
x: 18 y: 4

The x and y integers are private, and only can be accessed and manipulated by the functions setVal(int, int), getX(), and getY().

Access specifiers plays an important role in implementing encapsulation.
Two Steps:
  - data members should be labeled as private using private access specifiers
  - The member function which manipulates the data members should be labeled as public using the public access specifier
