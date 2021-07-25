#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
//#include "AttributeDefinitionMenu.h"
//#include "BasicText.h"
#include <SFML/Graphics.hpp>

class ButtonWithText
{

public:
	ButtonWithText(std::string textToDisplay, int textSize, sf::Vector2f coordinates) {
		//don't deal with color for now, deal with those parameters later
		if (!buttonFont.loadFromFile("fonts/sans.ttf")) {
			std::cout << "failed to load button text font\n";
			exit(EXIT_FAILURE);
		}
		buttonText.setFont(buttonFont);
		buttonText.setCharacterSize(textSize);
		buttonText.setFillColor(sf::Color::Green);
		buttonText.setString(textToDisplay);

		sf::FloatRect buttonRect = buttonText.getGlobalBounds();

		int xOffset = 10;
		int yOffset = 10;

		int textHieght = buttonRect.height;
		int textWidth = buttonRect.width;
		
		int newRectWidth = textWidth + (2* xOffset);
		int newRectHieght = textHieght + (2* yOffset);

		button.setPosition(coordinates);
		button.setSize(sf::Vector2f(newRectWidth, newRectHieght));
		button.setFillColor(sf::Color::Blue);

		sf::Vector2f textPosition = sf::Vector2f(coordinates.x + xOffset, coordinates.y);	//in practice the text needs the xoffset but not the yoffset visually
		buttonText.setPosition(textPosition);

	}

	void Draw(sf::RenderWindow *passedWindow) {
		passedWindow->draw(button);
		passedWindow->draw(buttonText);
		
	}

	void CheckClickedOn(sf::Vector2i mousePosition) {
		sf::Vector2f floatMousePosition = sf::Vector2f((float)mousePosition.x, (float)mousePosition.y);
		if (button.getGlobalBounds().contains(floatMousePosition) && clickedOn == false) {
			button.setFillColor(sf::Color::Red);
			clickedOn = true;
		}
		else if (button.getGlobalBounds().contains(floatMousePosition) && clickedOn == true) {
			button.setFillColor(sf::Color::Blue);
			clickedOn = false;
		}
		
	}

	//void CheckMouseOver(sf::Vector2i mousePosition) {
	//	//2i is 2 integers, must be converted to vector2f for contains function
	//	sf::Vector2f floatMousePosition = sf::Vector2f((float)mousePosition.x, (float)mousePosition.y);
	//	if (button.getGlobalBounds().contains(floatMousePosition) && clickedOn == false) {
	//		button.setFillColor(sf::Color::Red);
	//	}
	//	if (button.getGlobalBounds().contains(floatMousePosition) && clickedOn == true) {
	//		button.setFillColor(sf::Color::Blue);
	//	}
	//	
	//	//optimize this by checking if the color needs to be changed
	//}

	//make a single function for a button that will be called each
	//clock tick which will handle mouse over and drawing

	//mouse over color stays the same but the color when clicked on is different!
	//what happens when you click a button? How can I make this so that it works
	//for all uses?



private:
	sf::Text buttonText;
	sf::Font buttonFont;
	sf::RectangleShape button;
	bool clickedOn = false;

};

