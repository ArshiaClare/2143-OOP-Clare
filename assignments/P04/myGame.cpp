/*Arshia Clare
*myGame.ccp
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "myGame.h"

using namespace sf;

/*Class implements for Game of LIfe*/
//constructor that initialize FrameCount, FrameRate,
//the window's width and height
//no return
GameOfLife::GameOfLife(int r, int c) {
	FrameCount = 0;
	FrameRate = 5;
	BoardRow = r;
	BoardCol = c;

	Window.create(VideoMode(BoardRow, BoardCol), "Game of Life");

	//creating a world
	World = new golCell*[BoardRow];

	for (int i = 0; i < BoardRow; i++) {
		World[i] = new golCell[BoardCol];
		for (int j = 0; j < BoardRow; j++) {
			World[i][j].setCellPos(i, j);
		}
	}

}

//@param nothing
//returns integer representation of true (1)
int GameOfLife::Frame() {
	FrameCount++;		//gotta increment
	if (FrameCount % FrameRate == 0)
		return 0;
}


//using SFML to make a visual representation of the gameOfLife
//@param none
//@return void
void GameOfLife::drawWorld() {
	Window.clear();
	//creates the entire general board
	for (int i = 0; i < BoardCol; i++) {
		for (int j = 0; j < BoardRow; j++) {
			Window.draw(World[i][j].Rect);
		}
	}

	//colors (white) the rectangles that have a alive cell
	//what the user is looking for
	for (int i = 0; i < Cols; i++) {
		for (int j = 0; j < Rows; j++) {
			//it's alive
			if (gameBoard[j][i].isAlive == true) {
				World[i][j].Rect.setFillColor(Color::White);
				World[i][j].Rect.setOutlineColor(Color::Magenta);
			}
		}
	}
	Window.display();
}

//@param string, which is the name of the input file
//Reads in row #, col #, and values of 0 and 1 from an input file
//@returns void
void GameOfLife::initBoard(std::string infilename) {
	//opening the input file
	std::ifstream infile;
	infile.open(infilename);

	std::string Fname;
	std::string Lname;

	//reads in my Name
	infile >> Fname >> Lname;

	// Reads in first two numbers from first line
	infile >> Rows >> Cols;
	std::string line;


	// Dynamically allocate proper number of rows
	gameBoard = new golCell*[Rows];
	
	// Dynamically allocate proper numeber of cols
	for (int i = 0; i < Rows; i++) {
		gameBoard[i] = new golCell[Cols];
	}

	// Now Let's read rest of file (0's and 1's)
	for (int i = 0; i < Rows; i++) {
		// Read an entire line in from file
		infile >> line;

		// Loop through the line and insert a 
		// char at a time into the array
		for (int j = 0; j < Cols; j++) {
			gameBoard[i][j].isAlive = line[j] - 48;
			gameBoard[i][j].neighborCount = 0;
		}
	}
	infile.close();
}

//@param integer
//@return void
//does the game the amount of times it is given
void GameOfLife::playGod(std::string loopNum) {
	int num = getNumLoop(loopNum);
	//loops through the Game multiple times 
	//final result is the final board
	for (int i = 0; i < num; i++) {
		//draws each time!!!
		//Dr. G told me to comment this out due to computer's speed!
		//drawWorld();
		NewCommunity();
	}
	//draws the last game
	drawWorld();
}

//@param two integers
//checks to make sure the values being checked is in the
//matrix or board
//@return bool
bool GameOfLife::onWorld(int r, int c) {
	//should return true
	return ((r >= 0 && r < Rows) && (c >= 0 && c < Cols));
}

//traverse through the board to count the neighbors for 
//the current position.
//@param two integers
//@return integer
int GameOfLife::CountNeighbor(int r, int c) {
	int neighbor = 0;
	//the if statements checks the 8 neighbors, can be less for 
	//the border and corner rectangles.
	//checks if its onWorld and Aliveness
	if (onWorld(r - 1, c - 1) == true && Alive(r - 1, c - 1) == true)
	{
		neighbor++;
	}
	if (onWorld(r - 1, c) == true && Alive(r - 1, c) == true)
	{
		neighbor++;
	}
	if (onWorld(r - 1, c + 1) == true && Alive(r - 1, c + 1) == true)
	{
		neighbor++;
	}
	if (onWorld(r, c - 1) == true && Alive(r, c - 1) == true)
	{
		neighbor++;
	}
	if (onWorld(r, c + 1) == true && Alive(r, c + 1) == true)
	{
		neighbor++;
	}
	if (onWorld(r + 1, c - 1) == true && Alive(r + 1, c - 1) == true)
	{
		neighbor++;
	}
	if (onWorld(r + 1, c) == true && Alive(r + 1, c) == true)
	{
		neighbor++;
	}
	if (onWorld(r + 1, c + 1) == true && Alive(r + 1, c + 1) == true)
	{
		neighbor++;
	}
	return neighbor;
}

//@param two integers
//@return bool
//checks if the position given is alive or dead
bool GameOfLife::Alive(int r, int c) {
	return (gameBoard[r][c].isAlive);
}

//@param none
//@return none
//updates the neighbor count in the gameBoard
//useful for checking rules (or judgement)
void GameOfLife::updatingNeighbor() {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			gameBoard[i][j].neighborCount = CountNeighbor(i, j);
		}
	}
}

//@param none
//@return void
//uses updated neighbor count to access the judgement
//(rules), udates the alive and dead cells, 
//makes the neighborCount back to 0
void GameOfLife::NewCommunity() {
	updatingNeighbor();
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			Judgement(i, j);
			gameBoard[i][j].neighborCount = 0;
		}
	}
}

//@param two integers
//@return nothing
//checks through the rules of the game and updates the 
//gameBoard's alive and dead cells
void GameOfLife::Judgement(int r, int c) {
	//the rules that apply to alive cells
	if (Alive(r, c) == true) {
		//dies from underpop or overpop
		if (gameBoard[r][c].neighborCount < 2 ||
			gameBoard[r][c].neighborCount > 3)
		{
			gameBoard[r][c].isAlive = false;
		}
			//second chance at this thing called Life
		else if (gameBoard[r][c].neighborCount == 2 ||
			gameBoard[r][c].neighborCount == 3) {
			gameBoard[r][c].isAlive = true;
		}
	}
	//checks the dead ones
	else {
		//it's a miracle... "He's alive. Alive"... very 
		//Frankenstein's monster
		if (gameBoard[r][c].neighborCount == 3) {
			gameBoard[r][c].isAlive = true;
		}
	}
}

//@param string
//@return int
//converts the string value of loop to integer for looping
//purposes.
int GameOfLife::getNumLoop(std::string loopTurns) {
	int num = stoi(loopTurns);
	return num;
}

void GameOfLife::header(std::ofstream& outfile) {
	outfile << "Arshia Clare\n";
	outfile << "This is the output of the infile\n";
	outfile << "Program 04 - Game of Life\n";
	outfile << "Oct 15, 2018\n";
	outfile << "---------------------------------------\n";

}

//@param string, which is the output file's name
//@return void
//prints my name, plus other info, and [alive, neighborCount]
void GameOfLife::printWorld(std::string outfilename) {
	std::ofstream outfile;
	outfile.open(outfilename);

	//Heading
	header(outfile);
	
	//printing vals of isAlive and neighborCount
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			outfile << gameBoard[i][j].isAlive;
		}
		outfile << std::endl;
	}
	outfile.close();
}

//@param nothing
//@return nothing
//it draws world to window
void GameOfLife::SFMLCall() {
	//calling SFML
	while (Window.isOpen()) {
		Event event;
		while (Window.pollEvent(event)) {
			
			if (event.type == Event::Closed)
				Window.close();
		}
		drawWorld();
		if (Frame() == 0) {
			drawWorld(); //called to display the game board
		}
	}
}
