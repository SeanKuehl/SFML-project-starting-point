#include <iostream>
#include <SFML/Graphics.hpp>



int main(void) {
	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
	sf::CircleShape ball(10.f);
	ball.setFillColor(sf::Color::White);
	ball.setPosition(500, 400);

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

		window.clear();
		window.draw(leftPaddle);
		window.draw(rightPaddle);
		window.draw(ball);

		window.display();
		
	}

	return 0;
}