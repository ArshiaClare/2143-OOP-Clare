/**
*  Course: CMPS 2143 - OOP
*
*  Purpose: Added frameRate and frameCount to the provided code
*
*  @author Arshia Clare
*  @version 1.1 10/05/2018
*  @github repo: https://github.com/ArshiaClare
*/
#include <SFML/Graphics.hpp>

using namespace sf;

struct golCell {
	bool isAlive;
	int neighborCount;
	RectangleShape Rect;
	int Width;
	int Height;

	golCell() {
		Width = 10;
		Height = 10;
		Rect.setSize(sf::Vector2f(Width, Height));
		Rect.setFillColor(Color::Green);
		Rect.setOutlineColor(Color::Black);
		Rect.setOutlineThickness(1);
	}

	void setCellPos(int x, int y) {
		Rect.setPosition(x*Width, y*Height);
	}

};

struct gameOfLife {
	int Width;
	int Height;
	RenderWindow Window;
	golCell** World;

	//Added by Arshia
	//two variables required to add
	int frameCount;
	int frameRate;

	gameOfLife(int width, int height) {
		Width = width;
		Height = height;

		//by the example from class
		frameCount = 0;
		frameRate = 5;

		Window.create(VideoMode(Width, Height), "Game of Life");

		World = new golCell*[height];

		for (int i = 0; i < height; i++) {
			World[i] = new golCell[width];
			for (int j = 0; j < width; j++) {
				World[i][j].setCellPos(i, j);
			}
		}
	}

	//constructor that takes in framerate with width and height
	gameOfLife(int width, int height, int rate) {
		Width = width;
		Height = height;
		
		//Added by Arshia
		//rate can be changed in main
		frameCount = 0;
		frameRate = rate;
		
		Window.create(VideoMode(Width, Height), "Game of Life");

		World = new golCell*[height];

		for (int i = 0; i < height; i++) {
			World[i] = new golCell[width];
			for (int j = 0; j < width; j++) {
				World[i][j].setCellPos(i, j);
			}
		}
	}


	void drawWorld() {
		Window.clear();
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < Width; j++) {
				Window.draw(World[i][j].Rect);
			}
		}
		Window.display();
	}
};



int main() {

	//original one
	//gameOfLife Gol(1000, 1000);

	//user can change this variable
	int FrameRate = 10;
	//gives the width, height, and frame-rate
	gameOfLife Gol(1000, 1000, FrameRate);
	
	while (Gol.Window.isOpen())
	{
		Event event;
		while (Gol.Window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				Gol.Window.close();
			}
		}

		//similar to code from GOL starter
		//sfml_game_of_life_starter.cpp

		if (Gol.frameCount % Gol.frameRate == 0) {
			Gol.drawWorld(); //called to display the game board
		}

		//got to increment frameCount somewhere
		Gol.frameCount++;

		//it printed the rectangles in under a minute or so...

	}
	return 0;
}
