/**
*  Course: CMPS 2143 - OOP
*  @author Arshia Clare
*  @version 1.1 10/01/18 
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
  void push_back(int*, int); 
  int pop_back(); //pops the item from the back of the array
  int size(); //the current size of the array
  int indexNum(); //tells how many items are currently in the array
  int AnythingIn(); //is it empty or not, false or true
  double percentFull(); //shows the amount of space used in the array

  // Implementation of [] operator.  This function must return a 
  // refernce as array element can be put on left side 
  int& operator[](int i)
  { 
      if (i >= vSize) 
      { 
          cout << "Array index out of bound, exiting\n"; 
          exit(0); 
      }else if(i >= index){
          cout << "Warning: vector["<<i<<"] is undefined ...\n";
      }
      return theVector[i]; 
  }

  //overloads the << operator
  //it prints the vector when main calls cout<<array
  friend ostream& operator<<(ostream& os, myVector V )
  {
    //checks for empty
    if(V.index == 0){
      os << "empty\n";
    }else{
      os<<"[";  //[ placed before the numbers
      for(int i=0;i<V.index;i++)
      {
        //puts comma between number without extra
        if(i > 0 && i < V.index){
          cout << ",";
        }
        os<<V.theVector[i];
      }
      os<<"]";
    }
    return os;
  }

  //overloading '+' 
  //@param: reference of two array
  //adds the values of two vectors together and places in LHS
  //@returns LHS
  friend myVector operator+(myVector& a, myVector& b)
  {
    //index of a because we need to return the same amount
    //of values passed in
    for(int i = 0; i < a.index; i++)
    {
      a.theVector[i] = a.theVector[i] + b.theVector[i];
    }
    return a;
  }

  //overloading '-' 
  //@param: reference of two array
  //subtracts the values of two vectors together and places in LHS
  //@returns LHS
  friend myVector operator-(myVector& a, myVector& b)
  {
    for(int i = 0; i < a.index; i++)
    {
      a.theVector[i] = a.theVector[i] - b.theVector[i];     
    }
    return a;
  }

  //overloading '/' 
  //@param: reference of two array
  //divides the values of two vectors together and places in LHS
  //@returns LHS
  friend myVector operator/(myVector& a, myVector& b)
  {
    for(int i = 0; i < a.index; i++)
    {
      //if it tries to divide by 0 then its undefined
      //just going to return 0 if case
      if(b.theVector[i] == 0)
      {
        a.theVector[i] = 0;
      }else{
        //good numbers for dividing
        a.theVector[i] = a.theVector[i]/b.theVector[i];
      }
    }
    return a;
  }

  //overloading '*' 
  //@param: reference of two array
  //multiples the values of two vectors together and places in LHS
  //@returns LHS
  friend myVector operator*(myVector& a, myVector& b)
  {
    for(int i = 0; i < a.index; i++)
    {
      a.theVector[i] = a.theVector[i] * b.theVector[i];
    }
    return a;
  }

  //overloading '*' 
  //@param: reference of an array
  //multiples the values of vector a with number provided
  //@returns LHS
  friend myVector operator*(myVector& a, int num)
  {
    for(int i = 0; i < a.index; i++)
    {
      a.theVector[i] = a.theVector[i] * num;
    }
    return a;
  }
  
  //overloading '==' 
  //@param: reference of two array
  //checks if the values of two arrays are equal
  //@returns bool
  friend bool operator==(myVector& a, myVector& b)
  {
    for(int i = 0; i < b.index; i++)
    {
      if(a.theVector[i] == b.theVector[i])
      {
        return true;
      }
    }
    return false;
  }
  
};


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
*  the user or input tries to pass array and size, the program
*  adds the values in the array to the existing array.
*  @param {int *, int}
*  @return void
*/
void myVector::push_back(int * arr, int size)
{
  for(int i = 0; i < size; i++){
    //calls the existing push_back(int)
    //that adds the passed value to the back of the
    //existing array
    push_back(arr[i]);
  }
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
    cout << "[" ;
    for(int i=0;i<index;i++){
      //puts comma between number without extra
      if(i > 0 && i < index){
        cout << ",";
      }
      cout <<theVector[i];
    } //end of for-loop
    cout << "]\n";
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
