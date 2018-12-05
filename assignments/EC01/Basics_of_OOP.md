Basic Concept
- notes taken from https://www.geeksforgeeks.org/basic-concepts-of-object-oriented-programming-using-c/

-It takes real world concepts like inhertance, hiding, polymorphism, and turns it to programming. 

-the concept is to "bind" data and the functions influencing the data, and nothing else in the code can 
  access the data without the function. 

-- OBJECT: instances of a class that are user defined data types. 

- each object contains data and code used to manipulate that data.

- objects can interact without the need for details of others.
    
    example: 
    ```
    class fruit
    {
     private:
        int color;
        string name;
     public:
        fruit();
        void getColor();
    };
     
    int main()
    {
        fruit F;   //F is an object
    }
    ```
    
-- CLASS: blueprint of data and functions(methods)

- default class variables -> private but in case of structure -> public

Structure of a class:
```
class NAME
{
  //each section can have data members and functions
  private: 
  public:
  protected:
};
```
-- ENCAPSULATION: combining data and functions into one case.

- Not available to outside itself.

- hiding

-- DATA ABSTRACTION: necessary details are provided outside while hiding implementatio. 

- the programmer has control of the privates and hide the background action.

-- INHERITANCE: one object can access the properties of another class.

- hierarhical classification. 

- provides re-usability

- the programmer can add to the existing class without implementing it in that class.

-- POLYMORPHISM: take more than one form. So a method that has different behaviors in different instances. 

- type of data important. 

- main example: overloading (can be operators)

- useful in implementing inheritance.

-- Dynamic Binding: execution in response to function call in runtime.

-- MESSAGE PASSING: communication between objects. Involves specifying the name of the object, function and necessary information needed to be sent. 
