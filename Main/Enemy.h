#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Enemy
{
public:
	std::string nameOfTexture = "libraries/pics/SampleEnemy.png";
	//std::string nameOfShieldTexture = "libraries/pics/shield.png";
	//sf::Texture shieldTexture;
	//sf::Sprite shieldSprite;
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	float ySpeed = 0.05;
	float xSpeed = 0.05;

	Enemy(sf::Vector2f positionVector) {

		if (!enemyTexture.loadFromFile(nameOfTexture))
		{
			// there was a problem loading the texture
			std::cout << "couldn't load enemy texture" << std::endl;
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


		enemySprite.setTexture(enemyTexture);
		enemySprite.setPosition(positionVector);
	}

	void Move(Player playerOne) {
		enemySprite.move(sf::Vector2f(xSpeed, ySpeed));

		sf::FloatRect shieldCollisionRect = playerOne.playerSprite.getGlobalBounds();
		shieldCollisionRect.top = (shieldCollisionRect.top + shieldCollisionRect.height) - 20;
		shieldCollisionRect.height = shieldCollisionRect.top + 20;
		//maybe use corelation to mouse location

		//boundary checks
		if (enemySprite.getGlobalBounds().top < 0) {
			ySpeed = ySpeed * -1;
		}
		if ((enemySprite.getGlobalBounds().top + enemySprite.getGlobalBounds().height) > 790) {
			ySpeed = ySpeed * -1;
		}
		if (enemySprite.getGlobalBounds().left < 0) {
			

			
			xSpeed = xSpeed * -1;
			ySpeed = ySpeed * -1;
		}
		if ((enemySprite.getGlobalBounds().left + enemySprite.getGlobalBounds().width) > 1000) {
			
			
			xSpeed = xSpeed * -1;
			ySpeed = ySpeed * -1;
		}
		if (enemySprite.getGlobalBounds().intersects(playerOne.playerSprite.getGlobalBounds())) {
			std::cout << "hit the player" << "\n";
			//if (enemySprite.getGlobalBounds().intersects(shieldCollisionRect)) {
			//	//it hit the shield
			//	std::cout << "hit the shield" << "\n";
			//}
			//else {
			//	std::cout << "hit the player" << "\n";
			//}
		}
	}

};


