/**
*  Course: CMPS 2143 - OOP
*  Program: P04
*
*  Purpose: The program is a game of life playthrough. 
*	It applies the rules of the game, and it does
* 	the game the amount the user or command line 
*	suggests. It is displayed using SFML. The
* 	white rectangles represent the alive cells,
* 	rest are dead. The rules apply to 
*	overpopulation, underpopulation, and resurrections.
*	
* 
*  @author Arshia Clare
*  @version 1.1 10/15/2018
*  @github repo: https://github.com/ArshiaClare
*/
#include <iostream>
#include <fstream>
#include <string>
//#include <cstring>
#include <SFML/Graphics.hpp>

using namespace sf;

//golCell holds two variables important for 
//Game of Life, is it alive? and how many neighbors?
struct golCell {
	bool isAlive;       //keeps track of alive and dead
	int neighborCount;  //number of neighbor

	//SFML 
	//example from sfml_game_of_life_2.cpp
	RectangleShape Rect;
	int Width;
	int Height;

	//initializing struct
	golCell() {
		isAlive = 0;
		neighborCount = 0;
		Width = 10;
		Height = 10;
		Rect.setSize(Vector2f(Width, Height));
		Rect.setFillColor(Color::Red);
		Rect.setOutlineColor(Color::Yellow);
		Rect.setOutlineThickness(.5);
	}

	//position placement
	void setCellPos(int x, int y) {
		Rect.setPosition(x*Width, y*Height);
	}
};

/*Class definitions and implements for Game of LIfe*/
class GameOfLife {
private:
	int FrameCount; //total times game loop did loop
	int FrameRate;  //allow user to slow down animation
	int Rows;       //rows read in
	int Cols;       //columns read in
	int BoardRow;	//row num of the window
	int BoardCol;	//col num of the window

	golCell** gameBoard;  //creates a 2D array with two variables
public:
	RenderWindow Window;	//SFML
	golCell **World;		//SFML 
	//@param two integers
	//constructor that initialize FrameCount, FrameRate,
	//the window's width and height
	//no return
	GameOfLife(int r, int c) {
		FrameCount = 0;		
		FrameRate = 10;
		BoardRow = r;
		BoardCol = c;
		Window.create(VideoMode(BoardRow, BoardCol), "Game of Life");

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
	int Frame() {
		FrameCount++;		//gotta increment
		if (FrameCount % FrameRate == 0)
			return 0;
	}


	//using SFML to make a visual representation of the gameOfLife
	//@param none
	//@return void
	void drawWorld() {
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
	void initBoard(std::ifstream& infile){	//(std::string infilename) {
		//opening the input file
		/*std::ifstream infile;
		infile.open(infilename);*/

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
	}

	//@param integer
	//@return void
	//does the game the amount of times it is given
	void playGod(int loopNum){
		//loops through the Game multiple times 
		//final result is the final board
		for (int i = 0; i < loopNum; i++) {
			NewCommunity();
		}
	}	

	//@param two integers
	//checks to make sure the values being checked is in the
	//matrix or board
	//@return bool
	bool onWorld(int r, int c) {
		//should return true
		return ((r >= 0 && r < Rows) && (c >= 0 && c < Cols));
	}

	//traverse through the board to count the neighbors for 
	//the current position.
	//@param two integers
	//@return integer
	int CountNeighbor(int r, int c) {
		int neighbor = 0;
		//the if statements checks the 8 neighbors, can be less for 
		//the border and corner rectangles.
		//checks if its onWorld and Aliveness
		if (onWorld(r - 1, c - 1) == true && Alive(r - 1, c - 1) == true) {
			neighbor++;
		}
		if (onWorld(r - 1, c) == true && Alive(r - 1, c) == true) {
			neighbor++;
		}
		if (onWorld(r - 1, c + 1) == true && Alive(r - 1, c + 1) == true) {
			neighbor++;
		}
		if (onWorld(r, c - 1) == true && Alive(r, c - 1) == true) {
			neighbor++;
		}
		if (onWorld(r, c + 1) == true && Alive(r, c + 1) == true) {
			neighbor++;
		}
		if (onWorld(r + 1, c - 1) == true && Alive(r + 1, c - 1) == true) {
			neighbor++;
		}
		if (onWorld(r + 1, c) == true && Alive(r + 1, c) == true) {
			neighbor++;
		}
		if (onWorld(r + 1, c + 1) == true && Alive(r + 1, c + 1) == true) {
			neighbor++;
		}
		return neighbor;
		// cout << neighbor;
	}

	//@param two integers
	//@return bool
	//checks if the position given is alive or dead
	bool Alive(int r, int c) {
		return (gameBoard[r][c].isAlive);
	}

	//@param none
	//@return none
	//updates the neighbor count in the gameBoard
	//useful for checking rules (or judgement)
	void updatingNeighbor() {
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
	void NewCommunity() {
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
	void Judgement(int r, int c) {
		//the rules that apply to alive cells
		if (Alive(r, c) == true) {
			//dies from underpop or overpop
			if (gameBoard[r][c].neighborCount < 2 || gameBoard[r][c].neighborCount > 3)
			{
				gameBoard[r][c].isAlive = false;
			}
			//second chance at this thing called Life
			else if (gameBoard[r][c].neighborCount == 2 || gameBoard[r][c].neighborCount == 3) {
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
	int getNumLoop(std::string loopTurns) {
		int num = stoi(loopTurns);
		return num;
	}

	//@param string, which is the output file's name
	//@return void
	//prints my name, plus other info, and [alive, neighborCount]
	void printWorld(std::string outfilename) {
		std::ofstream outfile;
		outfile.open(outfilename);
		//Heading
		outfile << "Arshia Clare\n";
		outfile << "This is the output of the infile\n";
		outfile << "Program 04 - Game of Life\n";
		outfile << "Oct 15, 2018\n";
		outfile << "---------------------------------------\n";

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				outfile << "[" << gameBoard[i][j].isAlive << "," << gameBoard[i][j].neighborCount << "]";
			}
			outfile << std::endl;
		}
		//drawWorld();
	}

};

int main(int argc, char** argv) {

	GameOfLife G(600, 600);
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << std::endl;
	}
	//given in command line
	std::string infilename = argv[1];
	std::string numTimes= argv[2];
	std::string outfilename = argv[3];

	//int numLoop = G.getNumLoop(numTimes);

	//G.initBoard(infilename);
	//// Run this file for 338 generations
	//G.playGod(338);
	//G.printWorld(outfilename);
	//calling SFML

	std::ifstream infile;
	infile.open("gen_zero.txt");

	G.initBoard(infile);
	G.playGod(338);
	G.printWorld("output.txt");


	while (G.Window.isOpen()) {
		Event event;
		while (G.Window.pollEvent(event)) {
			G.drawWorld();
			if (event.type == Event::Closed)
				G.Window.close();
		}
		if (G.Frame() == 0) {
			G.drawWorld(); //called to display the game board
		}
	}
}
