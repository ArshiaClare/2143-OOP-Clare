/**
*  Course: CMPS 2143 - OOP
*  Assignment 05
*
*  Purpose: Makes a counter.cpp that displays a clock that either
*			is incrementing or decrementing. The seconds are 
*			displayed with integer numbers.
*
*  @author Arshia Clare
*  @version 1.1 11/05/2018
*  @github repo: https://github.com/ArshiaClare
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

//useful links for sfml
//https://www.sfml-dev.org/tutorials/2.5/system-time.php
//https://www.sfml-dev.org/tutorials/2.5/graphics-text.php

using namespace sf;

class Counter {
private:
	Time start;
	Time end;
	Time elapsed;
	bool fin;
public:
	Font font;
	Text text;

	//constructor that gets clock, first term, last term
	//it checks whether the clock counts up or down
	Counter(Clock clock, int first, int last) {
		//sets start and end
		setLength(first, last);

		//if statement checks increments
		if (first < last) {
			//calls incrementing function
			incrClock(clock, last);
		}

		//otherwise, decrements
		else {
			//calls decrementing function
			decrClock(clock, first);
		}
	}

	//default constructor
	//programer decided best to increment from 0 to 10
	Counter() {
		Clock clock;
		//sets start and end
		setLength(0, 10);
		//calls incrementing
		incrClock(clock, 10);
	}

	//constructor that has clock, one number, and user decides
	//whether the clock goes up or down.
	Counter(Clock clock, int first, std::string direction) {
		//user passes "up" or "down"
		if (direction == "up") {
			start = seconds(first);
			incrInfinity(clock);
		}
		else if (direction == "down") {
			end = seconds(first);
			decrInfinity(clock);
		}
		//if the string doesn't match then error message
		else {
			std::cout << "error! you need to pass the clock, a number, and"
				<< " up or down\n";
		}
	}

	//sets the font and checks to see if the font exists.
	//https://www.sfml-dev.org/tutorials/2.5/graphics-text.php
	//@param none
	//@return void
	void FontSetter() {
		//error checking
		if (!font.loadFromFile("arial.ttf")) {
			std::cout << "error!";
		}
		//sets the font
		text.setFont(font);
	}

	//increments the clock to infinity
	//no end
	//@param clock
	//@return void
	void incrInfinity(Clock clock) {
		//sets font for the clock
		FontSetter();

		//given by Dr. G
		elapsed = clock.getElapsedTime();
		//turn float to int
		int secs = elapsed.asSeconds();
		std::cout << "Incrementing Clock: " << secs << std::endl;

		//since it near ends it is false
		fin = false;
	}

	//decrements to infinity
	//no end
	//@param clock
	//@return void
	void decrInfinity(Clock clock) {
		//sets font for clock
		FontSetter();

		//given by Dr.G
		elapsed = clock.getElapsedTime();
		//turn float to int
		int secs = elapsed.asSeconds();
		//turn starting second to int
		int intStart = start.asSeconds();
		//given
		std::cout << "Decrementing Clock: " << intStart - secs 
			<< std::endl;

		//since it near ends it is false
		fin = false;
	}

	//decrements from big number to smaller
	//@param clock, int
	//@return void
	void decrClock(Clock clock, int first) {
		//sets font
		FontSetter();

		//given
		elapsed = clock.getElapsedTime();
		//turning float val of seconds to int seconds
		//program requirement
		int secs = elapsed.asSeconds();
		int intStart = start.asSeconds();
		//given
		std::cout << "Decrementing Clock: " << intStart - secs 
			<< std::endl;

		//sfml text
		//int to string <-- given to the sfml text to 
		//show seconds in sfml window, and sets color to Magenta
		text.setString(std::to_string(intStart - secs));
		text.setFillColor(Color::Magenta);

		//there is an endpoint
		if (secs == first) {
			fin = true;
		}
	}

	//increments from one number to the last one
	//@param clock, int
	//@return void
	void incrClock(Clock clock, int last) {
		//set font
		FontSetter();

		//given
		elapsed = clock.getElapsedTime();
		//turning float seconds to int
		int secs = elapsed.asSeconds();
		//given
		std::cout << "Incrementing Clock: " << secs << std::endl;
		//sfml text
		//int to string <-- given to the sfml text to 
		//show seconds in sfml window, and sets color to Magenta
		text.setString(std::to_string(secs));
		text.setFillColor(Color::Magenta);

		//there is an endpoint
		if (secs == last) {
			fin = true;
		}
	}

	//assigning start and end with the param
	//@param int, int
	//@return void
	void setLength(int firstTime, int secTime) {
		start = seconds(firstTime);
		end = seconds(secTime);
	}

	//restarts the clock
	//@param clock
	//@return void
	void restartClock(Clock clock) {
		clock.restart();
	}

	//the counter done
	//returns true or false
	//@param none
	//@return bool
	bool isFinished() {
		return fin;
	}
};

//int main() provided. modified to run the program
int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Clock");

	//had to assign Clock here
	Clock clock;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//uncomment the clock you desire

		// start at 5 and decrement to 0
		/*Counter myClock1(clock, 5, 0); 
		window.clear();
		window.draw(myClock1.text);
		window.display();
		
		//closes the sfml window when the counter finishes
		if (myClock1.isFinished() == true) {
			window.close();
		}*/
		
		//--------------------------------------------------------
		
		// start at 0 and increment to 5
		Counter myClock2(clock, 0, 5); 
		window.clear();
		window.draw(myClock2.text);
		window.display();

		//closes the sfml window when the counter finishes
		if (myClock2.isFinished() == true) {
			window.close();
		}
	}

	system("pause");
	return 0;
}
