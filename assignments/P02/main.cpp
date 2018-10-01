/**
*  Course: CMPS 2143 - OOP    
*  Purpose: The program pushes and pops from an array. It 
*     can print the array. The modifications to the program  
*     are that the program adds to the previous one by 
*     including overloading methods of a few operations such 
*     as +,-,*,/,==,=,push_back,<<,and []. 
*      
*
*  @author Arshia Clare
*  @version 1.1 10/01/18 
*  @filename main.cpp
*  @github name: ArshiaClare
*  @github: https://github.com/ArshiaClare/2143-OOP-Clare
*  @repl.it: https://repl.it/@ArshiaClare/P02-ver-2
*/

#include <iostream>
#include <string>
#include "myVector.h"

using namespace std;

int main()
{
  //github test
  
  myVector v1;
  myVector v2;

  v1.push_back(8);
  // v1 contains: [8]
  v1.print();

  v2.push_back(10);
  v2.push_back(20);
  v2.push_back(30);
  // v2 contains: [10,20,30]
  v2.print();
  // Declare some int array
  int A[] = {1,2,3,4,5};


  v1.push_back(A,5);
  v1.print();
  // v1 contains: [8,1,2,3,4,5]

  v1 = v1 + v2;
  // v1 contains: [18,21,32,3,4,5]
  v1.print();
  cout<<v1<<endl;
  // would print: [18,21,32,3,4,5] to standard out.

  cout<<v1[2]<<endl;
  // would print: 32 to standard out.


  v2 = v2 * 3;
  // v2 contains: [30,60,90]
  v2.print();
  v2 = v2 * v1;
  // v2 contains: [540,1260,2880]
  v2.print();
  v2[2] = 100;
  // v2 contains: [540,1260,100]
  v2.print();

  // //my test

  // //creating V to have the size of 10
  // myVector V(10);
  // myVector V2(10);
  // myVector V3(10);
  // myVector V4(10);

  
  // //pushes 5 values provided into array V
  // V.push_back(27); 
  // V.push_back(33); 
  // V.push_back(24);
  // V.push_back(18);
  // V.push_back(9);

  // //pushes 4 values provided into array V2
  // V2.push_back(9);
  // V2.push_back(3);
  // V2.push_back(4);
  // V2.push_back(3);

  // //pushes 4 values provided into array V3
  // V3.push_back(2);
  // V3.push_back(7);
  // V3.push_back(7);
  // V3.push_back(4);

  // //pushes 4 values provided into array V4
  // V4.push_back(2);
  // V4.push_back(7);
  // V4.push_back(7);
  // V4.push_back(4);

  // cout << "printing the original:\n";
  // V.print();
  // V2.print();
  // cout << endl;

  // //testing << operation overload
  // cout<<"testing [] overload:";
  // cout<<V<<endl;

  // //assigning val to certain place in the array
  // V[1] = 10;
  // V2[2] = 10;

  // //printing to see new arrays
  // cout << "printing to see new arrays with 10s\n";
  // V.print();
  // V2.print();
  // cout << endl;

  // //testing [] overload 
  // cout<<"what's in V[2]?\n";
  // cout<<V[2]<<endl;
  // cout<<"what's in V[8]?\n";
  // cout<<V[8]<<endl<<endl;

  // //testing - overload
  // V = V - V2;
  // V.print();
  // cout << endl;

  // // testing == overload
  // cout << "is there equality between V and V2?\n";
  // cout << (V == V2) << endl;
  // cout << "is there equality between V3 and V4?\n";
  // cout << (V3 == V4) << endl <<endl;

  // //testing push_back overload
  // cout <<"testing push_back(array, size)\n";
  // int A[] = {1,2,3,4,5};
  // V.push_back(A,5);
  // V.print();
  // cout << endl;

  // //testing / overload
  // V = V/V2;
  // V.print();

  // //testing + overload
  // V = V + V2;
  // V.print();

  // //testing + overload
  // V2 = V2 + V;
  // V2.print();

  // cout <<endl;
  // //testing equality again
  // cout << "is there equality between V and V2?\n";
  // cout << (V == V2) << endl;

}
