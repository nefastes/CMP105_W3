#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circle.setRadius(10);
	circle.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	circle.setFillColor(sf::Color::Yellow);
	circle.setOrigin(10,10);

	controlledCircle.setRadius(40);
	controlledCircle.setPosition(window->getSize().x / 4, window->getSize().y / 4);
	controlledCircle.setFillColor(sf::Color::Blue);
	controlledCircle.setOrigin(40, 40);

	bouncingCircle.setRadius(20);
	bouncingCircle.setPosition(window->getSize().x /3, window->getSize().y /3);
	bouncingCircle.setFillColor(sf::Color::Magenta);
	bouncingCircle.setOrigin(20, 20);

	circleSpeed = 200.0f;
	secondCircleSpeed = 300.0f;
	thirdCircleSpeed = 100.0f;

	if (!font.loadFromFile("font/arial.ttf")) std::cout << "Could not load font.\n";
	message.setFont(font);
	message.setCharacterSize(24);
	message.setFillColor(sf::Color::Red);
	message.setPosition(0, 0);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	if (circle.getPosition().x >= window->getSize().x - 10)
	{
		circleSpeed *= -1;
		circle.setPosition(window->getSize().x - 10, circle.getPosition().y);
	}
	if (circle.getPosition().x <= 0 + 10)
	{
		circleSpeed *= -1;
		circle.setPosition(0 + 10, circle.getPosition().y);
	}
	circle.setPosition(circle.getPosition().x, window->getSize().y / 2);
	circle.move(circleSpeed * dt, 0);

	if (input->isKeyDown(sf::Keyboard::Up) && controlledCircle.getPosition().y > 0 + 40) controlledCircle.move(0, -secondCircleSpeed * dt);
	else if (input->isKeyDown(sf::Keyboard::Down) && controlledCircle.getPosition().y < window->getSize().y - 40) controlledCircle.move(0, secondCircleSpeed * dt);
	else if (input->isKeyDown(sf::Keyboard::Right) && controlledCircle.getPosition().x < window->getSize().x - 40) controlledCircle.move(secondCircleSpeed * dt, 0);
	else if (input->isKeyDown(sf::Keyboard::Left) && controlledCircle.getPosition().x > 0 + 40) controlledCircle.move(-secondCircleSpeed * dt, 0);

	if (input->isKeyDown(sf::Keyboard::Add)) thirdCircleSpeed += 1.0f;
	else if (input->isKeyDown(sf::Keyboard::Subtract)) thirdCircleSpeed -= 1.0f;
	if (bouncingCircle.getPosition().x >= window->getSize().x - 20)
	{
		horizontalDirection *= -1;
		bouncingCircle.setPosition(window->getSize().x - 20, bouncingCircle.getPosition().y);
	}
	if(bouncingCircle.getPosition().x <= 0 + 20)
	{
		horizontalDirection *= -1;
		bouncingCircle.setPosition(0 + 20, bouncingCircle.getPosition().y);
	}
	if (bouncingCircle.getPosition().y >= window->getSize().y - 20)
	{
		verticalDirection *= -1;
		bouncingCircle.setPosition(bouncingCircle.getPosition().x, window->getSize().y - 20);
	}
	if (bouncingCircle.getPosition().y <= 0 + 20)
	{
		verticalDirection *= -1;
		bouncingCircle.setPosition(bouncingCircle.getPosition().x, 0 + 20);
	}
	bouncingCircle.move(horizontalDirection * thirdCircleSpeed * dt, verticalDirection * thirdCircleSpeed * dt);
	message.setString("The bouncing ball current speed is " + std::to_string((int)thirdCircleSpeed) + " pixels/second.");
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
	window->draw(controlledCircle);
	window->draw(bouncingCircle);
	window->draw(message);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}