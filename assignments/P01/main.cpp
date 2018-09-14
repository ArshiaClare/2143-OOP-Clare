/**
*  Course: CMPS 2143 - OOP    
*  Purpose: An array is created with a size given by the user 
*  or the default size of 10. A class is created that emulate 
*  a C++ vector. The vector stores integers. The items are
*  pushed into the array, and it is placed in the last index. 
*  When the array is full, then the size is increased by 1.5
*  from the current size until not necessary. When the items 
*  are being popped from the back, and the index becomes 40%
*  full then the size is reduced to 50% until not necessary.
*  There are functions in the class that identify size of the 
*  current array, the last placement (index),prints the array,
*  and finds the percentage full. 
*
*  @author Arshia Clare
*  @version 1.1 09/14/18 
*  @filename main.cpp
*/

#include <iostream>
#include <string>
#include "myVector.h"

using namespace std;

int main()
{

  //creating V to have the size of 10
  myVector V(10);
  // V.push_back("nope");

  //testing the methods
  cout << "The values in the vector will be printed inside < >\n\n";
  //pops off from an empty array
  //returns a comment and 0 for false
  cout << V.pop_back() << endl << endl; 
  
  //pushes three values provided into the array
  V.push_back(13); //first element
  V.push_back(31); //second element
  V.push_back(73); //third element

  //prints the array this time not empty..
  V.print();
  //for the user. useful info about the array
  //size, # of items, and percentage filled
  cout << "Size: " << V.size() << endl;
  cout << "Items: " << V.indexNum() << endl;
  cout << "percent: " << V.percentFull() << endl << endl;
  
  //Pushing 10,000 values into the array
  for(int i = 0; i < 10000; i++)
  {
    V.push_back(i);
  }
  //for the user. useful info about the array
  //size, # of items, and percentage filled
  cout << "Size after push_back: " << V.size() << endl;
  cout << "Items: " << V.indexNum() << endl;
  cout << "percent: " << V.percentFull() << endl << endl;
  
  //Popping 9998 items
  for(int i = 0; i < 9998; i++)
  {
    V.pop_back();
  }
  //for the user. useful info about the array
  //size, # of items, and percentage filled
  cout << "Size after pop_back: " << V.size() << endl;
  cout << "Items: " << V.indexNum() << endl;
  cout << "percent: " << V.percentFull() << endl << endl;

  //prints the final product of the vector after the pushing and popping
  V.print();


  // //testing with slack example
  // myVector V(10);
  // V.print();      // should print nothing
  // cout<<V.size()<<endl; // output: 10
  // V.push_back(4);
  // V.print();      // output: 4
  // for(int i=1;i<=5;i++){
  //   V.push_back(i*3);
  // }
  // V.print();      //output: 4 3 6 9 12 15
  // cout<<V.size()<<endl;    //output: 10
  // V.pop_back();
  // V.print();      //output: 4 3 6 9 12
  // cout<<V.percentFull()<<endl; //output .5  
  // for(int i=1;i<=5;i++){
  //   V.push_back(i*4);
  // }
  // V.print();  //output: 4 3 6 9 12 4 8 12 16 20
  // cout<<V.size()<<endl;   //output: 15
}
