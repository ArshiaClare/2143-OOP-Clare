# Polymorphism in C++
The word **polymorphism** means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form.
Real life example of polymorphism, a person at a same time can have different characteristic. Like a man at a same time is a father, a husband, a employee. So a same person posses have different behavior in different situations. This is called polymorphism.
Polymorphism is considered as one of the important features of Object Oriented Programming.
In C++ polymorphism is mainly divided into two types:

- Compile time Polymorphism

- Runtime Polymorphism

1. **Compile time polymorphism**: This type of polymorphism is achieved by function overloading or operator overloading. 

 

    - **Function Overloading**: When there are multiple functions with same name but different parameters then these functions are overloaded. Functions can be overloaded by **change in number of arguments** or/and **change in type of arguments** (difference to the signature).

```
// C++ program for function overloading 
#include <iostream>
      
using namespace std;
      
class Point
{
private:
  double x;
public:
  Point()
  {
    x = 0;
  }
  void set(int X)
  {
      x = X;
  }
  void set(double S)
  {
      x = S;
  }
  double get()
  {
     return x;
  }
};
      
int main()
{
    Point P;
    P.set(2);
    cout << P.get() << endl;
    P.set(2.3);
    cout << P.get() << endl;
    return 0;
}
```
      OUTPUT: 
      2
      2.3 
      
in the example set acts differently depending on the parameter

- **Operator Overloading**: C++ also provide option to overload operators. For example, we can make the operator (‘+’) for string class to concatenate two strings. We know that this is the addition operator whose task is to add to operands. So a single operator ‘+’ when placed between integer operands , adds them and when placed between string operands, concatenates them.
Example:

```
// Operator Overloading 

        #include <iostream>
        
        using namespace std;
        
        class Rectangle
        {
          private:
            int width;
            int height;
          public:
            Rectangle(int w, int h)
            {
              width = w;
              height = h;
            }
            int getW()
            {
              return width;
            }
            int getH()
            {
              return height;
            }
            
            //+ operator overload
            //change the + to -, *, / to the programmer's needs
            Rectangle operator+(const Rectangle R2)
            {
              width += R2.width;
              height += R2.height;
              return Rectangle(width,height);
            }
        }; 
        
        int main()
        {
            Rectangle R(4,5);
            Rectangle S(3,5);
            
            R = R + S;
            cout << R.getW() << " " << R.getH() << endl;
            
            return 0;
        }
```
        OUTPUT:
        
        7 10

2. **Runtime polymorphism**: This type of polymorphism is achieved by Function Overriding.
- **Function overriding** on the other hand occurs when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden.

```
// C++ program for function overriding 
#include <iostream>
    
using namespace std;
    
class Parent
{
  public:
    virtual void get()
    {
      cout << "Hello from the parent";
    }
    int Age()
    {
          return 35;
    }
};
    
class child: public Parent
{
  public:
      
      void get()
      {
          cout << "Hello from the child";
      }
      int Age()
      {
          return 8;
      }
};
    
int main()
{
  Parent *A;
  child B;
  A = &B;
        
  // Virtual function, binded at runtime (Runtime Polymorphism)
  A->get();
  cout << endl;
  // Non-virtual function, binded at compile time
  cout << A->Age() << endl;
        
  return 0;
}
```
        OUTPUT
    
        Hello from the child
        35
