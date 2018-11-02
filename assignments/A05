
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

// https://www.sfml-dev.org/tutorials/2.5/system-time.php
using namespace sf;

class Counter {
private:
	//Clock clock;
	Time start;
	Time end;
	Time elapsed;
	bool fin;



public:
	Font font;
	Text text;
	//constructor we are using
	Counter(Clock clock, int first, int last) {
		setLength(first, last);
		//inc
		if (first < last) {
			incrClock(clock,first, last);
		}

		//dec
		else {
			decrClock(clock,first, last);
		}
	}

	//default
	Counter() {
		Clock clock;
		setLength(0, 10);
		incrClock(clock, 0, 10);
	}

	//constructor that has one number that either goes up or down.
	Counter(Clock clock, int first, std::string direction) {
		if (direction == "up") {
			incrInfinity(clock);
		}
		else if (direction == "down") {
			decrInfinity(clock);
		}
	}

	void FontSetter() {
		std::string name = "arial.ttf";
		if (!font.loadFromFile(name)) {
			std::cout << "error!";
		}
		text.setFont(font);
	}

	//increments to infinity
	//no end
	void incrInfinity(Clock clock) {
		FontSetter();
		elapsed = clock.getElapsedTime();
		int secs = elapsed.asSeconds();
		std::cout << "Incrementing Clock: " << secs << std::endl;
		fin = false;
	}

	//decrements to infinity
	//no end
	void decrInfinity(Clock clock) {
		FontSetter();
		elapsed = clock.getElapsedTime();
		int secs = elapsed.asSeconds();
		int intStart = start.asSeconds();
		std::cout << "Decrementing Clock: " << intStart - secs << std::endl;
		fin = false;
	}

	//decrements from big number to smaller
	void decrClock(Clock clock, int first, int last) {
		FontSetter();
		elapsed = clock.getElapsedTime();
		int secs = elapsed.asSeconds();
		int intStart = start.asSeconds();
		std::cout << "Decrementing Clock: " << intStart - secs << std::endl;
		text.setString(std::to_string(intStart - secs));
		if (secs == first) {
			fin = true;
		}
	}

	//increments from one number to the last one
	void incrClock(Clock clock, int first, int last) {
		FontSetter();
		elapsed = clock.getElapsedTime();
		int secs = elapsed.asSeconds();
		std::cout << "Incrementing Clock: " << secs << std::endl;
		text.setString(std::to_string(secs));
		if (secs == last) {
			fin = true;
		}
	}

	//assigning start and end
	void setLength(int firstTime, int secTime) {
		start = seconds(firstTime);
		end = seconds(secTime);
	}

	//restarts the clock
	void restartClock(Clock clock) {
		clock.restart();
	}

	//the counter done
	bool isFinished() {
		return fin;
	}
};


int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML counter");

	Clock clock;

	//Counter myClock1(clock, 5, 0); // start at 5 and decrement to 0
	//Counter myClock2(clock, 0, 5); // start at 0 and increment to 5

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//had to move it here 
		Counter myClock1(clock, 5, 0); // start at 5 and decrement to 0
		//Counter myClock2(clock, 0, 5); // start at 0 and increment to 5

		window.clear();
		window.draw(myClock1.text);
		window.display();

		if (myClock1.isFinished() == true) {
			window.close();
		}
	}

	system("pause");
	return 0;
}
