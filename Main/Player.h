#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


class Player
{
public:
	//libraries/pics/playerImage.png
	std::string nameOfTexture = "libraries/pics/playerImage.png";
	//std::string nameOfShieldTexture = "libraries/pics/shield.png";
	sf::Texture shieldTexture;
	sf::Sprite shieldSprite;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	Player(sf::Vector2f positionVector) {
		
		if (!playerTexture.loadFromFile(nameOfTexture))
		{
			// there was a problem loading the texture
			std::cout << "couldn't load player texture" << std::endl;
			exit(EXIT_FAILURE);
		}
		/*if (!shieldTexture.loadFromFile(nameOfShieldTexture)) {
			std::cout << "couldn't load shield texture" << std::endl;
			exit(EXIT_FAILURE);
		}

		shieldSprite.setTexture(shieldTexture);
		shieldSprite.setPosition(positionVector);*/	//it's relative to where player is
		//I'll need to give player a rotate func that rotates both player and shield
		//also it's own draw to do the shield as well
		

		playerSprite.setTexture(playerTexture);
		playerSprite.setPosition(positionVector);
		//I want below to be the center
		//left, top, width, hieght
		float originX = (playerSprite.getGlobalBounds().width) /2;
		float originY = (playerSprite.getGlobalBounds().height)/2;
		playerSprite.setOrigin(sf::Vector2f(originX, originY));
		//this changes what it's rotated etc around

		//maybe I don't need a seperate shield object

		
		//shieldSprite.setOrigin(sf::Vector2f(originX, originY));
		//shieldSprite.move(50, 50);

	}

	sf::Vector2f GetSpecialPoint() {
		float specialPointX = (playerSprite.getGlobalBounds().width) / 2;
		float specialPointY = playerSprite.getGlobalBounds().top + playerSprite.getGlobalBounds().height;
		return sf::Vector2f(specialPointX, specialPointY);
	}

	sf::Vector2f GetCenter() {
		float originX = (playerSprite.getGlobalBounds().width) / 2;
		float originY = (playerSprite.getGlobalBounds().height) / 2;
		return sf::Vector2f(originX, originY);
	}

	/*void SetRotationOfAll(float numberToRoatateBy) {
		playerSprite.setRotation(numberToRoatateBy);
		shieldSprite.setRotation(numberToRoatateBy);
	}*/

	

private:


};

//// position
//sprite.setPosition(sf::Vector2f(10.f, 50.f)); // absolute position
//sprite.move(sf::Vector2f(5.f, 10.f)); // offset relative to the current position
//
//// rotation
//sprite.setRotation(90.f); // absolute angle
//sprite.rotate(15.f); // offset relative to the current angle
//
//// scale
//sprite.setScale(sf::Vector2f(0.5f, 2.f)); // absolute scale factor
//sprite.scale(sf::Vector2f(1.5f, 3.f)); // factor relative to the current scale


//// 'entity' can be a sf::Sprite, a sf::Text, a sf::Shape or any other transformable class
//
//// set the absolute rotation of the entity
//entity.setRotation(45.f);
//
//// rotate the entity relatively to its current orientation
//entity.rotate(10.f);
//
//// retrieve the absolute rotation of the entity
//float rotation = entity.getRotation(); // = 55


//// get the global mouse position (relative to the desktop)
//sf::Vector2i globalPosition = sf::Mouse::getPosition();
//
//// get the local mouse position (relative to a window)
//sf::Vector2i localPosition = sf::Mouse::getPosition(window);