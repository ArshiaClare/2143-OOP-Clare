Inheritance in C++
The capability of a class to derive properties and characteristics from another class is called **Inheritance**. Inheritance is one of the most important feature of Object Oriented Programming.

**Sub Class**: The class that inherits properties from another class is called Sub class or Derived Class.

**Super Class**:The class whose properties are inherited by sub class is called Base Class or Super class.

subtopics:

Why and when to use inheritance?

Modes of Inheritance

Types of Inheritance

**Why and when to use inheritance?**

Consider a group of vehicles. You need to create classes for Bus, Car and Truck. The methods fuelAmount(), capacity(), applyBrakes() will be same for all of the three classes. If we create these classes avoiding inheritance then we have to write all of these functions in each of the three classes as shown in below figure:

![inheritance](https://user-images.githubusercontent.com/35582387/49704717-10eacb80-fbdc-11e8-9a76-699ee7796685.png) 

You can clearly see that above process results in duplication of same code 3 times. This increases the chances of error and data redundancy. To avoid this type of situation, inheritance is used. If we create a class Vehicle and write these three functions in it and inherit the rest of the classes from the vehicle class, then we can simply avoid the duplication of data and increase re-usability. Look at the below diagram in which the three classes are inherited from vehicle class:inheritance2
Using inheritance, we have to write the functions only one time instead of three times as we have inherited rest of the three classes from base class(Vehicle).

![inheritance2](https://user-images.githubusercontent.com/35582387/49704727-442d5a80-fbdc-11e8-8df5-227728763cea.png)

**Implementing inheritance in C++**: For creating a sub-class which is inherited from the base class we have to follow the below syntax.

**Syntax**:
```
class child : "public/private/protected" parent
{
  //stuff to implement and define child
};
```
Here, child is the name of the sub class, and parent is the name of the base class from which you want to inherit the sub class.

**Note**: A derived class doesn’t inherit access to private data members. However, it does inherit a full parent object, which contains any private members which that class declares.

```
// C++ program to demonstrate implementation 
// of Inheritance 
   
#include <iostream>

using namespace std;

class Super
{
  public:
      int x;
      int y;
};

class Sub: public Super
{
  public:
    int A;
    int B;
};

int main()
{
    Sub E;
    
    //Sub has access to the public of Super
    E.x = 30;
    E.y = 9;
    E.A = E.x;
    E.B = 8;
    cout << "Super data members: " << E.x << " " <<  E.y << endl;
    cout << "Sub data members: " << E.A << " " << E.B << endl;
    
    return 0;
}
```

      Output:
      Super data members: 30 9
      Sub data members: 30 8
      
In the above program the ‘Sub’ class is publicly inherited from the ‘Super’ class so the public data members of the class ‘Super’ will also be inherited by the class ‘Sub’.

## **Modes of Inheritance**

1. **Public mode**: If we derive a sub class from a public base class. Then the public member of the base class will become public in the derived class and protected members of the base class will become protected in derived class.
2. **Protected mode**: If we derive a sub class from a Protected base class. Then both public member and protected members of the base class will become protected in derived class.
3. **Private mode**: If we derive a sub class from a Private base class. Then both public member and protected members of the base class will become Private in derived class.

**Note **: The private members in the base class cannot be directly accessed in the derived class, while protected members can be directly accessed.
```
// C++ Implementation to show that a derived class 
// doesn’t inherit access to private data members.  
// However, it does inherit a full parent object 
class Parent  
{ 
public: 
    int a; 
protected: 
    int b; 
private: 
    int c; 
}; 
  
class DerivedOne : public Parent 
{ 
    // a is public 
    // b is protected 
    // c is not accessible from B 
}; 
  
class DerivedB : protected Parent
{ 
    // a is protected 
    // b is protected 
    // c is not accessible from C 
}; 
  
class DerivedC : private Parent    // 'private' is default for classes 
{ 
    // a is private 
    // b is private 
    // c is not accessible from D 
};
```
The below table summarizes the above three modes and shows the access specifier of the members of base class in the sub class when derived in public, protected and private modes:

![table-class](https://user-images.githubusercontent.com/35582387/49704844-c9653f00-fbdd-11e8-9458-c329520cbcda.png)

**Types of Inheritance in C++**

1. **Single Inheritance**: In single inheritance, a class is allowed to inherit from only one class. i.e. one sub class is inherited by one base class only.
    Syntax:
    ```
    class subclass_name : access_mode base_class
    {
      //body of subclass
    };
    ```
```
// C++ program to explain  
// Single inheritance 
#include <iostream> 
using namespace std; 
  
// base class 
class Fruit { 
  public: 
    Fruit() 
    { 
      cout << "This is a fruit" << endl; 
    } 
}; 
  
// sub class derived from two base classes 
class Apple: public Fruit{ 
  
}; 
  
// main function 
int main() 
{    
    // creating object of sub class will 
    // invoke the constructor of base classes 
    Apple obj; 
    return 0; 
} 
```
    Output:
    This is a fruit
    
2. **Multiple Inheritance**: Multiple Inheritance is a feature of C++ where a class can inherit from more than one classes. i.e one sub class is inherited from more than one base classes.

![multiple-inheritance](https://user-images.githubusercontent.com/35582387/49707078-45b44e00-fbef-11e8-8dd0-e1f6c4416ed9.png)

    Syntax:

    class child : public/protected/private parent1, public/protected/private parent2, ....
    {
      //body of child
    };
    
**Note** Here, the number of base classes will be separated by a comma (‘, ‘) and access mode for every base class must be specified.
```
// C++ program to explain  
// multiple inheritance 
#include <iostream> 
using namespace std; 
  
// first base class 
class fruit { 
  public: 
    fruit() 
    { 
      cout << "This is a fruit" << endl; 
    } 
}; 
  
// second base class 
class Tree { 
  public: 
    Tree() 
    { 
      cout << "Grows on a tree" << endl; 
    } 
}; 
  
// sub class derived from two base classes 
class Apple: public fruit, public Tree { 
  
}; 
  
// main function 
int main() 
{    
    // creating object of sub class will 
    // invoke the constructor of base classes 
    Apple obj; 
    return 0; 
} 
```
    Output:
    This is a fruit
    Grows on a tree 

3. **Multilevel Inheritance**: In this type of inheritance, a derived class is created from another derived class. 

![multilevel-inheritance](https://user-images.githubusercontent.com/35582387/49707103-6e3c4800-fbef-11e8-977e-c951bd7b0a6b.png)
```
// C++ program to implement  
// Multilevel Inheritance 
#include <iostream> 
using namespace std; 
  
// base class 
class Fruit 
{ 
  public: 
    Fruit() 
    { 
      cout << "This is a fruit" << endl; 
    } 
}; 
class Color: public Fruit 
{  public: 
    Color() 
    { 
      cout << "It has some color" << endl; 
    } 
}; 
// sub class derived from two base classes 
class Apple: public Color{ 
   public: 
     Apple() 
     { 
       cout<<"Apple is red or green"<<endl; 
     } 
}; 
  
// main function 
int main() 
{    
    //creating object of sub class will 
    //invoke the constructor of base classes 
    Apple obj; 
    return 0; 
} 
```
    output:
    This is a fruit
    It has some color
    Apple is red or green
4. **Hierarchical Inheritance**: In this type of inheritance, more than one sub class is inherited from a single base class. i.e. more than one derived class is created from a single base class.

![hierarchical-inheritance](https://user-images.githubusercontent.com/35582387/49709849-e14bbb80-fbfb-11e8-8d40-59261702749f.png)

Example
```
// C++ program to implement  
// Hierarchical Inheritance 
#include <iostream> 
using namespace std; 
  
// base class 
class Fruit  
{ 
  public: 
    Fruit() 
    { 
      cout << "This is a fruit" << endl; 
    } 
}; 
  
  
// first sub class  
class Apple: public Fruit 
{ 
  
}; 
  
// second sub class 
class Banana: public Fruit 
{ 
      
}; 
  
// main function 
int main() 
{    
    // creating object of sub class will 
    // invoke the constructor of base class 
    Apple obj1; 
    Banana obj2; 
    return 0; 
}
```
      Output:
      This is a fruit
      This is a fruit
5. **Hybrid (Virtual) Inheritance**: Hybrid Inheritance is implemented by combining more than one type of inheritance. For example: Combining Hierarchical inheritance and Multiple Inheritance.
Below image shows the combination of hierarchical and multiple inheritance:

![hybrid-inheritance](https://user-images.githubusercontent.com/35582387/49709938-4c958d80-fbfc-11e8-8fad-5644d1ec051e.png)
```
// C++ program for Hybrid Inheritance 
  
#include <iostream> 
using namespace std; 
  
// base class  
class Fruit  
{ 
  public: 
    Fruit() 
    { 
      cout << "This is a fruit" << endl; 
    } 
}; 
  
//base class 
class Tree 
{ 
    public: 
    Tree() 
    { 
        cout<<"It is produced by a tree\n"; 
    } 
}; 
  
// first sub class  
class Banana: public Fruit 
{ 
  
}; 
  
// second sub class 
class Apple: public Fruit, public Tree 
{ 
      
}; 
  
// main function 
int main() 
{    
    // creating object of sub class will 
    // invoke the constructor of base class 
    Apple obj2; 
    return 0; 
} 
```
    Output:
    This is a fruit
    It is produced by a tree
