/**
***  Course: CMPS 2143 - OOP
***
***  Purpose: The program has 2 Lists that contain a particular amount of values (integers) produced 
***   by the use of for-loop that is combined to create a new List. The second list is added to the
***   first list for the third list. The main also calls the last term of the 2 main lists. The functions
***   help the push/insert the numbers into an order, print the last term, and print the list. 
***
***  @Authors: Dr. T. Griffin (wrote the code) Arshia Clare (wrote comments)
***  @Assignment: A02 (Homework 1)
***  @date 09/05/2018 
**/

#include <iostream>

using namespace std;

//Array of 100 integers
int A[100];

/**
***  @name: struct node
***  creates a node that contains a integers and pointer
***  @param: none
***  @return: none
**/
struct Node
{
    int x;
    Node *next;
    //constructor with no param
    //default
    Node()
    {
        x = -1;
        next = NULL;
    }
    //constructor with int param
    //int passed becomes the x var.
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};

/**
*** @name: class List
*** @Methods:
*** *List()
*** *void Push(int val)
*** *void Insert(int val)
*** *void PrintTail()
*** *string Print()
*** *int Pop() //not implemented
*** *List operator+(const List &Rhs)
*** *int operator[](int index)
*** *friend ostream &operator<<(ostream &os, List L)
**/
class List
{
  private:
    Node *Head; 
    Node *Tail;
    int Size;

  public: 
    /**
    *** @name: List()
    *** @param: none
    *** @return: none
    *** @purpose: set Head, Tail pointers to NULL
                 intialize size to 0
    **/
    List()
    {
        Head = Tail = NULL;
        Size = 0;
    }

    /**
    ***  void Push(int val)
    ***   Head points to the front of the list
           Tails will get a new "last num" until the list gets to the end.
           Size increases everytime.   
    ***  @param: int value
    ***  @return: none
    **/
    void Push(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);
        //if list is empty then set Head & Tail to Temp
        if (!Head && !Tail)
        {
            Head = Tail = Temp;
        }
        else
        {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    /**  void Insert(int val)
    ***  method like Push method
    ***     Head in the front & Tail in the end
    ***     Size increases everytime by 1
    ***  @param: integer
    ***  @return: none
    **/
    void Insert(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail)
        {
            Tail = Head;
        }
        Size++;
    }
    
    
    /**
    ***  void PrintTail()
    ***  prints out the Tail value (the last value)
    ***  @param: none
    ***  @return: none
    **/
    void PrintTail()
    {
        cout << Tail->x << endl;
    }

    /**
    ***  string Print()
    ***     returns the values in list with "->" in between each val
    ***  @param: none
    ***  @return: string
    **/
    string Print()
    {
        Node *Temp = Head;
        string list;

        while (Temp != NULL)
        {
            //adds to the list
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented 
    /**
    ***  int Pop()
    ***     decreases the size. doesn't have much to the function
    ***  @param: none
    ***  @return: int
    **/
    int Pop()
    {
        Size--;
        return 0; //
    }

    /**
    *** overloading operator for the symbol +
    *** @param: List
    *** @return: List
    **/
    List operator+(const List &Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    /**
    ***  Implementation of [] operator.  
    ***  @param: int
    ***  @return: int value as if the list were an array.
    **/
    int operator[](int index)
    {
        Node *Temp = Head;
        //checking basics can't use if it's out of bounds
        if (index >= Size)
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        //yay it exist
        else
        {

            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    /**
    *** friend lets you have access to private
    **/
    friend ostream &operator<<(ostream &os, List L)
    {
        os << L.Print();
        return os;
    }
};

/**
***  the main has two Lists and the program combine the List 2 to the end List 1 
*** creates the new List 3. Prints out the List 3 and an element (5th).
***
***  @param int & double array
***  @return int 
**/
int main(int argc, char **argv)
{
    List L1;
    List L2;
    //for-loop to put values in List 1
    for (int i = 0; i < 25; i++)
    {
        L1.Push(i);
    }
    //for-loop to put values in List 2
    for (int i = 50; i < 100; i++)
    {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;
    cout << L3 << endl;
    //print out specific value from list 3
    cout << L3[5] << endl;
    return 0;
}
