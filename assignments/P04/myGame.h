/*Arshia Clare
*myGame.h
*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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

/*Class definitions for Game of LIfe*/
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

	GameOfLife(int r, int c);	//constructor for the game
	int Frame();				//frameCount and frameRate
	void drawWorld();			//makes rect and alive gets new color
	void initBoard(std::string infilename);	//reading the file
	//does the game certain times and draws the board
	void playGod(std::string loopNum);
	//checks if the row and col exists
	bool onWorld(int r, int c);
	//count the alive neighbors
	int CountNeighbor(int r, int c);
	//checks if the cell is alive
	bool Alive(int r, int c);
	//updates the neighbor count in the certain cell
	void updatingNeighbor();
	//applies the rules and reset neighbor to 0
	void NewCommunity();
	//the rules of the game
	void Judgement(int r, int c);
	//changing the string to integer
	int getNumLoop(std::string loopTurns);
	//prints my info
	void header(std::ofstream&);
	//prints the dead and alive
	void printWorld(std::string outfilename); 
	//SFML code
	void SFMLCall();
};
