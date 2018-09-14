/**
*  Course: CMPS 2143 - OOP
*  @author Arshia Clare
*  @version 1.1 09/14/18 
*  @filename myVector.cpp
*/
#include <iostream>
#include <string>
#include "myVector.h"

using namespace std;

/**
*  default constructor that initialize origSize, vSize, the   
*  Vector, and the index its values. Default size is 10 and 
*  index starts at 0 always.
*  @param none
*/
myVector::myVector()
{
  origSize = 10;
  vSize = 10;
  theVector = new int[vSize]; // create the array of vSize
  index = 0;
}

/**
*  constructor that initialize origSize, vSize, the   
*  Vector, and the index its values. Size is determined
*  by the parameter and index is 0.
*  @param {int} value which is the size of the array
*/
myVector::myVector(int size)
{
  origSize = size;
  vSize = size;
  theVector = new int[vSize]; // create the array of vSize
  index = 0;
}

/**
*  pushes/stores the items passed to the back of the array
*  @param {int} value which is the item passed into the array.
*  @return void
*/
void myVector::push_back(int item)
{
  int *temp;    //temporary pointer
  int tempSize = 0;   //temp size holder
  //stores the item to the array
  theVector[index++] = item;
  //checks if the array is full.
  if(percentFull() == 1)
  {
    //vSize is altered by x1.5
    tempSize = vSize * 1.5;
    temp = new int[tempSize];
    //then temp pointer is used to transfer items from the full array to a bigger array.
    for(int i = 0; i < vSize; i++)
    {
      temp[i] = theVector[i];
    }
    vSize = tempSize; //update vSize
    theVector = temp; //pointing theVector to temp
 } //end of if statement
}

/**
*  the user or input tries to pass a string, which is an error
*  @param {string}
*  @return void
*/
void myVector::push_back(string item)
{
  cout << "You cannot push in a word or string\n";
}

/**
*  pops off the item from the back of the array, and
*  checks to see if the size needs to be reduced
*  @param none
*  @return {int} the value which is in the back of the array.
*/
int myVector::pop_back()
{
  //checks for an empty array
  if(index == 0 || index < 0)
  {
    cout << "this array has no values, don't try to pop from an empty array... ";
    //prints 0 for false if its empty
    return AnythingIn();
  }
  // range to see if the array needs to be reduced
  // 40% full reduce by vSize by 50%
  //cannot be less than orginial size
  if((percentFull() <= 0.41 && percentFull() >= 0.39) && vSize >= origSize)
  {
    // cout << "the array is 40% full, resizing the array by reducing 50%\n";
    vSize*= 0.5;
    // cout << "its 40% full: (new size) " << vSize << endl;
  } //end of the if-statement
  
  int item;
  item = theVector[--index];  //stores last value to item
  return item;
}

/**
*  Called to identify the current size of the array
*  @param none
*  @return {int} the size of the array to whereever it is 
*     called.
*/
int myVector::size()
{
  //compares if the vSize went below original size
  if(vSize < origSize)
  {
    cout << endl;
    //error message
    cout << "Resizing error. Cannot be less than the original size provided which is: " << origSize << endl << endl;
  } // end of if-statement
 return vSize;
}

/**
*  Called to identify the current last placement of item in the array
*  @param none
*  @return {int} the index.
*/
int myVector::indexNum()
{
  return index;
}

/**
*  prints out the items in the array using the for-loop.
*  @param none
*  @return nothing
*/
void myVector::print()
{
  //makes sure the array isn't empty
  if(index == 0 || index < 0)
  {
    cout << "Well (user) stop it... why try to print an empty one????? ";
    //prints 0 for false if its empty
    cout << AnythingIn() << endl;
  } //end of if-statement
  else //it has stuff
  {
    //prints out the items in the array until last index.
    cout << "< " ;
    for(int i=0;i<index;i++){
      cout << theVector[i] << " ";
    } //end of for-loop
    cout << "> \n";
  } //end of else-statement
}

/**
*  the percentage of items occupying the array
*  @param none
*  @return {double} the percent used
*/
double myVector::percentFull()
{
  double percent;
  //type-cast to get a double
  percent = (double)index/(double)vSize;
  return percent;
}

/**
*  A function that checks if the array is occupied or not.
*  If it is a empty array then it is false, otherwise it's true.
*  @param none
*  @return {int} false or true.
*/
int myVector::AnythingIn()
{
  //checks for empty array
  if(index == 0 || index < 0)
  {
    cout << "false : " ;
    return false;
  } //end of if-statement
  return true;
}
