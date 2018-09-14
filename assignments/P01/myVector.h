/**
*  Course: CMPS 2143 - OOP
*  @author Arshia Clare
*  @version 1.1 09/14/18 
*  @filename myVector.h
*/
#include <iostream>
#include <string>

using namespace std;

class myVector
{
private:
  int *theVector; //the array
  int vSize; //the current size
  int origSize; //stores the original size 
  int index; //the last location allocated
  
public:
  myVector(); //constructor w/o param- default
  myVector(int size); //constructor with a param
  void print(); //user friendly function to know the items in the array
  void push_back(int item); //pushing an item to the back of the array
  void push_back(string item); //pushing a string, error checking
  int pop_back(); //pops the item from the back of the array
  int size(); //the current size of the array
  int indexNum(); //tells how many items are currently in the array
  int AnythingIn(); //is it empty or not, false or true
  double percentFull(); //shows the amount of space used in the array
};
