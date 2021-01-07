#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>



int main(void) {
	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
	sf::CircleShape ball(10.f);
	ball.setFillColor(sf::Color::White);
	ball.setPosition(500, 400);
	
	float ballXSpeed = 0.05;
	float ballYSpeed = 0.05;
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
	playerOneText.setPosition(sf::Vector2f(400, 10));

	playerTwoText.setFont(font);
	playerTwoText.setCharacterSize(24);
	playerTwoText.setFillColor(sf::Color::White);
	playerTwoText.setPosition(sf::Vector2f(600, 10));

	sf::RectangleShape rightPaddle(sf::Vector2f(950, 10));	//this might be size, it seems useless
	rightPaddle.setSize(sf::Vector2f(20, 100));
	rightPaddle.setFillColor(sf::Color::White);
	rightPaddle.setPosition(sf::Vector2f(950, 10));

	sf::RectangleShape leftPaddle(sf::Vector2f(50,10));
	leftPaddle.setSize(sf::Vector2f(20, 100));
	leftPaddle.setFillColor(sf::Color::White);
	leftPaddle.setPosition(sf::Vector2f(50, 10));
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				leftPaddle.move(sf::Vector2f(0, -10));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				leftPaddle.move(sf::Vector2f(0, 10));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				rightPaddle.move(sf::Vector2f(0,10));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				rightPaddle.move(sf::Vector2f(0, -10));
			}
		}

		//check for variouse things
		if (leftPaddle.getGlobalBounds().top < 0) {
			leftPaddle.setPosition(sf::Vector2f(50, 10));
		}
		if ((leftPaddle.getGlobalBounds().top + leftPaddle.getGlobalBounds().height) > 790) {
			leftPaddle.setPosition(sf::Vector2f(50, 680));
		}
		if (rightPaddle.getGlobalBounds().top < 0) {
			rightPaddle.setPosition(sf::Vector2f(950, 10));
		}
		if ((rightPaddle.getGlobalBounds().top + rightPaddle.getGlobalBounds().height) > 790) {
			rightPaddle.setPosition(sf::Vector2f(950, 680));
		}

		ball.move(sf::Vector2f(ballXSpeed, ballYSpeed));

		//when the ball goes out of screen in the different directions
		if (ball.getGlobalBounds().top < 0) {
			ballYSpeed = ballYSpeed * -1;
		}
		if ((ball.getGlobalBounds().top + ball.getGlobalBounds().height) > 790) {
			ballYSpeed = ballYSpeed * -1;
		}
		if (ball.getGlobalBounds().left < 0) {
			//it went out the left side
			playerTwoScore += 1;
			
			ball.setPosition(500, 400);
			ballXSpeed = ballXSpeed * -1;
			ballYSpeed = ballYSpeed * -1;
		}
		if ((ball.getGlobalBounds().left + ball.getGlobalBounds().width) > 1000) {
			playerOneScore += 1;
			ball.setPosition(500, 400);
			ballXSpeed = ballXSpeed * -1;
			ballYSpeed = ballYSpeed * -1;
		}

		//when ball collides
		if (ball.getGlobalBounds().intersects(leftPaddle.getGlobalBounds())) {
			
			ballXSpeed = ballXSpeed * -1;
		}
		if (ball.getGlobalBounds().intersects(rightPaddle.getGlobalBounds())) {
			
			ballXSpeed = ballXSpeed * -1;
		}

		str = std::to_string(playerOneScore);
		playerOneText.setString(str);
		str = std::to_string(playerTwoScore);
		playerTwoText.setString(str);

		
		

		window.clear();
		window.draw(leftPaddle);
		window.draw(rightPaddle);
		window.draw(ball);
		window.draw(playerOneText);
		window.draw(playerTwoText);

		window.display();
		
	}

	return 0;
}