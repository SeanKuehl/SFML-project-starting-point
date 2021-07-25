#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

class BasicText
{
public:
	BasicText(std::string textToDisplay, sf::Vector2f textPosition) {
		if (!textFont.loadFromFile("fonts/sans.ttf")) {
			std::cout << "failed to load basic text text font\n";
			exit(EXIT_FAILURE);
		}
		int defaultTextSize = 24;

		thisText.setFont(textFont);
		thisText.setCharacterSize(defaultTextSize);
		thisText.setFillColor(sf::Color::Green);
		thisText.setString(textToDisplay);
		thisText.setPosition(textPosition);
	}

	BasicText() {

	}

	void Draw(sf::RenderWindow* passedWindow) {
		thisText.setFont(textFont);
		passedWindow->draw(thisText);
	}

	void ScrollUp() {
		int movementAmount = -100;
		sf::Vector2f newPos = thisText.getPosition();
		newPos.y += movementAmount;
		thisText.setPosition(newPos);
	}

	void ScrollDown() {
		int movementAmount = 100;
		sf::Vector2f newPos = thisText.getPosition();
		newPos.y += movementAmount;
		thisText.setPosition(newPos);
	}

private:
	sf::Font textFont;
	sf::Text thisText;
	
};

