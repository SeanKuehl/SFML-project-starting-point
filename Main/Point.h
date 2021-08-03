#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Point
{
public:
	Point(float monetaryValue, sf::Vector2f position) {
		if (!font.loadFromFile("sans.ttf")) {
			std::cout << "failed\n";
			exit(EXIT_FAILURE);
		}

		sf::Vector2f textPosition = sf::Vector2f(position.x - 10, position.y -20);	//the text should be just a little bit above the point
		//every ten points shifted on the x is a character of the text at size 24

		pointText.setFont(font);
		pointText.setCharacterSize(15);
		pointText.setFillColor(sf::Color::White);
		//pointText.setRotation(-90.0);
		pointText.setPosition(textPosition);

		
		

		std::string stringVersionOfMonetaryValue = std::to_string(monetaryValue);
		std::string temp;
		for (int i = 0; i < stringVersionOfMonetaryValue.size()-4; i++) {
			//it's -4 because I'm cutting 4 zeros off the back 
			temp += stringVersionOfMonetaryValue.at(i);

		}
		
		pointText.setString("$"+temp);

		

		dataPoint.setSize(sf::Vector2f(5, 5));	//it's meant to be a dot on the graph
		dataPoint.setPosition(position);

	}

	void Draw(sf::RenderWindow* passedWindow) {
		
		passedWindow->draw(dataPoint);
		pointText.setFont(font);	//I have to do this in order for the text to draw
		passedWindow->draw(pointText);

	}

private:
	sf::Text pointText;
	sf::Font font;
	sf::RectangleShape dataPoint;
	
	
	

};

