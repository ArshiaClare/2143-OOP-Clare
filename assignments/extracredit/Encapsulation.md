Encapsulation in C++
**Encapsulation** is defined as wrapping up of data and information under a single unit. In Object Oriented Programming, Encapsulation is defined as binding together the data and the functions that manipulate them.
Consider a real life example of encapsulation, in a company there are different sections like the accounts section, finance section, sales section etc. The finance section handles all the financial transactions and keep records of all the data related to finance. Similarly the sales section handles all the sales related activities and keep records of all the sales. Now there may arise a situation when for some reason an official from finance section needs all the data about sales in a particular month. In this case, they are not allowed to directly access the data of sales section. Someone will first have to contact some other officer in the sales section and then request them to give the particular data. This is what encapsulation is. Here the data of sales section and the employees that can manipulate them are wrapped under a single name “sales section”.



 



Encapsulation also lead to data abstraction or hiding. Encapsulation allows hiding data. In the above example the data of any of the section like sales, finance or accounts is hidden from any other section.

In C++ encapsulation can be implemented using Class and access modifiers. Look at the below program:

// c++ program to explain 
// Encapsulation 
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
output:

x: 18 y: 4
In the above program the variable x and y are made private. These variables can be accessed and manipulated only using the functions get() and set() that is provided inside the class. Thus we can say that here, the variables (x and y) and the functions get() and set() are binded together or encapsulation.

Role of access specifiers in encapsulation

As we have seen in above example, access specifiers plays an important role in implementing encapsulation in C++. The process of implementing encapsulation can be sub-divided into two steps:

The data members should be labeled as private using the private access specifiers
The member function which manipulates the data members should be labeled as public using the public access specifier
