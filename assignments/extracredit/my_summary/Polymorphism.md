# POLYMORPHISM
-Notes taken from https://www.geeksforgeeks.org/polymorphism-in-c/

- means having many forms
- 2 types: Compile time polymorphism and runtime polymorphism

1. Compile time polymorphism: function overloading or operator overloading
    
    1. Function Overloading: multiple functions that have the same name but with different parameters.
        - functions can be overloaded by change in number of arguments and/or change intype of arguments.
      
      ```
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
          double get(){
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
      
    2. Operator Overloading: the programmer can overload the operations (+,-,*,/).
        - combining two string to form one. 
        
        ```
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
        
        The example adds two rectangles (their width and height) together.
        
2. RUNTIME POLYMORPHISM: is achieved by function overriding.
    - Function overiding: when a derived class has a definition for one of the member functions on the base case. that base function is orerriden.
    
    ```
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
    
    
