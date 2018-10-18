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
*  @version 2 10/18/2018
*  @github repo: https://github.com/ArshiaClare
*  main.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "myGame.h"

using namespace std;

int main(int argc, char** argv) {
	//prints to console the command line arguments
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << endl;
	}

	//given in command line
	string infilename = argv[1];
	string numTimes = argv[2];
	string outfilename = argv[3];

	GameOfLife G(600, 600);

	G.initBoard(infilename);
	G.playGod(numTimes);
	G.printWorld(outfilename);
	
	//calls SFML to print in window
	G.SFMLCall();
}
