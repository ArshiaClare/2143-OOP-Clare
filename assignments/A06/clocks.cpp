/*
*  Course: CMPS 2143 - OOP
*  A06
*
*  Purpose: Bouncing clocks (incrementing, decrementing, or done). The user 
*			can manipulate the font color, font size, background color of 
*			the rectangle, the rectangle's border. SFML window will be display
*			multiple instances of these clocks. 
*
*  @author Arshia Clare
*  @version 1 11/16/2018
*  @github repo: https://github.com/ArshiaClare
*  used clock starter from Dr.G's clock_starter
*/
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Group.h"

using namespace std;

// https://d2trtkcohkrm90.cloudfront.net/images/emoji/apple/ios-11/128/slightly-smiling-face.png

class GameClock : public Group {
private:
	sf::Text text;          // var to hold clock digits
	sf::Clock gameClock;    // SFML clock type		
	sf::Font font;		// SFML	Font
	sf::Color textColor;	// color of the font
	sf::RectangleShape rectangle;	//SFML rectangle
	int fontSize;		// stores the size
	int begin;		// first value of the clock
	int end;		// last value of the clock
	bool fin;		// clock finished? T/F
	float dx;		// displacement x value
	float dy;		// displacement y value

public:
	//constructor
	//@param {int,int}
	//@purpose assign text and rectangle details
	//sample code given in Dr.G's github
	GameClock(int first, int last) {
		//starts clock
		gameClock.restart();

		//checks font exists
		if (!font.loadFromFile("arial.ttf")) {
			cout << "Error loading font 'Segment7Standard.otf'...";
			exit(0);
		}

		begin = first;	//first value of the clock
		end = last;	//last value of the clock

		fontSize = 30;	

		textColor = sf::Color(0, 255, 0); // green

		text.setFont(font); // font is a sf::Font

		// set the string to display
		text.setString("0");

		text.setCharacterSize(fontSize); // in pixels, not points!

		//green
		text.setFillColor(textColor);

		text.setStyle(sf::Text::Bold);

		text.setOrigin(100, 100);

		text.setPosition(120, 120);
		
		//how much the object is moving
		//displacement
		dx = .1;
		dy = .1;

		//default rectangle
		rectangle.setSize(sf::Vector2f(100, 100));
		rectangle.setFillColor(sf::Color::Black);
		rectangle.setOutlineColor(sf::Color::Green);
		rectangle.setOutlineThickness(1);
		rectangle.setOrigin(100, 100);
		rectangle.setPosition(100, 100);

		//using Group.h
		this->push_back(rectangle);
		this->push_back(text);
	}

	//@param {int, int, int}
	//@return void
	//@purpose to assign font color for the clock
	void setFontColor(int r, int g, int b) {
		textColor = sf::Color(r, g, b);
		text.setFillColor(textColor);
	}

	//@param {sf::Color}
	//@return void
	//@purpose to assign font color for the clock with sfml Color
	void setFontColor(sf::Color color) {
		textColor = color;
		text.setFillColor(textColor);
	}

	//@param {int}
	//@return void
	//@purpose to assign a size for the text
	void setFontSize(int size) {
		fontSize = size;
		text.setCharacterSize(fontSize);
	}

	//@param {int, int, int}
	//@return void
	//@purpose to assign background color for the rectangle
	//	with rgb values
	void setBackgroundColor(int r, int g, int b) {
		rectangle.setFillColor(sf::Color(r,g,b));
	}

	//@param {sf::Color}
	//@return void
	//@purpose to assign background color for the rectangle
	//	with sfml color
	void setBackgroundColor(sf::Color color) {
		rectangle.setFillColor(color);
	}

	//@param {int, int, int}
	//@return void
	//@purpose to assign Border color for the rectangle
	//	with rgb values
	void setBorderColor(int r, int g, int b) {
		rectangle.setOutlineColor(sf::Color(r,g,b));
	}

	//@param {sf::Color}
	//@return void
	//@purpose to assign Border color for the rectangle
	//	with color in sfml
	void setBorderColor(sf::Color color) {
		rectangle.setOutlineColor(color);
	}

	//@param {int, int}
	//@return void
	//@purpose prints the incrementing, decrementing, or still clock
	//	and when it is done the message is "Done". sample code posted
	//	on Dr. G's github
	void printClock(int gameWidth, int gameHeight) {
		//the seconds
		int itime;
		//seconds as string for sfml text
		string stime;

		//incrementing
		if (begin < end) {
			//given
			itime = gameClock.getElapsedTime().asSeconds();
			stime = to_string(itime);
			//when it reaches the desired second
			//it prints Done and assigns fin as true
			if (itime >= end) {
				fin = true;
				stime = "Done";
			}
		}

		//decrementing
		else if (begin > end) {
			//given
			itime = begin - gameClock.getElapsedTime().asSeconds();
			stime = to_string(itime);
			//when it reaches the desired second
			//it prints Done and assigns fin as true
			if (itime <= end) {
				fin = true;
				stime = "Done";
			}
		}

		//still, so it can be begin == end, or there is no differences between
		//given values
		else{
			fin = true;
			stime = "Done";
		}
		text.setString(stime);
	}

	//@param {int, int}
	//@return void
	//@purpose to give a new position of the clock with the parameter
	//assigns origin and position to the text and rectangle
	void setClockPos(int RX, int RY) {
		//rectangle drawn to users desire
		rectangle.setPosition(RX , RY);

		//user desired pos with some value added to place the text to center
		//(close enough) of the rectangle 
		text.setPosition(RX + 18, RY + 35);
	}

	//@param {int, int}
	//@return void
	//@purpose Bounce lets the object (rectangle and clock) to bounce 
	//	off the walls, adjust the wall axis to make sure the object
	//	stays inside. Code sample given
	void Bounce(int WindowX, int WindowY) {
		sf::Vector2f pos = text.getPosition();

		//bottom x-val needs to be 105 to stop going outside window
		//MAX x- val needs Window + some
		if (pos.x < 105 || pos.x > WindowX + 30) {
			dx *= -1;
		}

		//left y-val needs to be 110 to stop going outside window
		//max y-val needs window + some
		if (pos.y < 110 || pos.y > WindowY + 40) {
			dy *= -1;
		}

		//moves the text and rectangle in 45 degree angle
		text.move(dx, dy);
		rectangle.move(dx, dy);
	}

	//the counter done
	//returns true or false
	//@param none
	//@return bool
	bool isFinished() {
		return fin;
	}
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 600), "Arshia Clare A06");

	GameClock S(0, 10);  //incrementing from 0 - 10
	GameClock G(7, 0);   //decrementing from 7 -0
	GameClock Z(0, 0);   //still it is a finished clock

	//G clock setup
	G.setBackgroundColor(34, 89, 55);	//green
	G.setBorderColor(sf::Color::Red);	//red
	G.setClockPos(100, 100);
	
	//S clock setup
	S.setBackgroundColor(54, 35, 89);	//purple
	S.setFontColor(sf::Color::White);	//White
	S.setBorderColor(233, 89, 100);		//red/pink
	S.setClockPos(250, 250);
		
	//Z clock setup
	Z.setBackgroundColor(89, 56, 36);	//brown
	Z.setFontColor(sf::Color::Yellow);	//yellow
	Z.setClockPos(400, 400);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		
		//G clock
		G.printClock(500, 600);
		G.Bounce(500, 600);
		window.draw(G);
		
		//S Clock
		S.printClock(500, 600);
		S.Bounce(500, 600);
		window.draw(S);
		
		//Z Clock
		Z.printClock(500, 600);
		Z.Bounce(500, 600);
		window.draw(Z);

		window.display();

		//checks when the sfml window should close
		//only closes if all clocks are finished
		if (S.isFinished() == true && G.isFinished() == true && Z.isFinished() == true) {
			window.close();
		}
	}

	return 0;
}
