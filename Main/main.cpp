#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Point.h"



int main(void) {


	//to move the camera around the world/map I'll need to use
	//sf:view, this is kind of like the godot camera
	//this api resource is actually great, views can be used for a lot
	//https://www.sfml-dev.org/tutorials/2.5/graphics-view.php


	//now I just need the custom draw stuff from autocrat
	/*
	void Draw(sf::RenderWindow* passedWindow) {
		thisText.setFont(textFont);
		passedWindow->draw(thisText);
	}
	now make a small project using all of them, maybe maybe not
	*/

	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
	
	//y axis
	sf::RectangleShape line(sf::Vector2f(500, 5));
	line.setPosition(sf::Vector2f(200, 100));
	line.rotate(90);

	//x axis
	sf::RectangleShape xAxis(sf::Vector2f(550, 5));
	xAxis.setPosition(sf::Vector2f(195, 600));

	//test point trying to hit 0
	sf::RectangleShape redThing(sf::Vector2f(5, 5));
	redThing.setPosition(sf::Vector2f(195, 600));	//195, 600 is the new 0,0
	redThing.setFillColor(sf::Color(255, 0, 0));


	int playerOneScore = 0;	//this is the player on the left
	int playerTwoScore = 0;	//this is the player on the right

	std::string str;

	sf::Text playerOneText;
	sf::Text playerTwoText;
	sf::Font font;
	if (!font.loadFromFile("sans.ttf")) {
		std::cout << "failed\n";
		exit(EXIT_FAILURE);
	}
	playerOneText.setFont(font);
	playerOneText.setCharacterSize(24);
	playerOneText.setFillColor(sf::Color::White);
	playerOneText.setRotation(-90.0);
	playerOneText.setPosition(sf::Vector2f(50, 150));
	
	/*playerTwoText.setFont(font);
	playerTwoText.setCharacterSize(24);
	playerTwoText.setFillColor(sf::Color::White);
	playerTwoText.setPosition(sf::Vector2f(600, 10));*/


	
	float moneyValue = 150.25f;
	int hypotheticalDayOfMonth = 15 * 10;	//it's *50 to space out the days of the month

	Point testPoint = Point(moneyValue, sf::Vector2f(195+hypotheticalDayOfMonth, 600 - int(moneyValue)));	//195, 600 is the new 0,0 and int()ing a float value cuts off the decimal, the +50 is just to horizontally seperate the space between days of the month, the -1 is because the lower the y the higher, so I need to make the value negative to be accurate

	sf::Text dayText;
	dayText.setFont(font);
	dayText.setCharacterSize(15);
	dayText.setFillColor(sf::Color::White);
	//dayText.setRotation(-90.0);
	dayText.setString("15th");
	dayText.setPosition(sf::Vector2f(195+hypotheticalDayOfMonth, 625));

	sf::Text moneyText;
	moneyText.setFont(font);
	moneyText.setCharacterSize(15);
	moneyText.setFillColor(sf::Color::White);
	//dayText.setRotation(-90.0);
	moneyText.setString("150");
	moneyText.setPosition(sf::Vector2f(160, 600 - int(moneyValue)));

	//use move() which will shift it so much from it's current position
	//use primitives for the pong paddles
	//leftPaddle.getGlobalBounds();	//this gets a rect
	//there is a collision thing with rects
	//intersects (const Rect< T > &rectangle, Rect< T > &intersection) 
	//returns bool on whether or not the two rects are colliding

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			
		}

		

		str = std::to_string(playerOneScore);
		playerOneText.setString(str);
		str = std::to_string(playerTwoScore);
		playerTwoText.setString(str);

		//for higher prices, make the zero value 1000 and subtract 1000 or whatever from the values so plotting is normal
		//If I kept track of where the data points ended up being drawn, I could draw lines between them
		

		window.clear();
		window.draw(line);
		//window.draw(playerOneText);
		window.draw(playerTwoText);
		testPoint.Draw(&window);
		window.draw(xAxis);
		window.draw(redThing);
		window.draw(dayText);
		window.draw(moneyText);
		window.display();
		
	}

	return 0;
}