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

	circleSpeed = 200.0f;
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
	if (circle.getPosition().x >= window->getSize().x - 10	|| circle.getPosition().x <= 0 + 10) circleSpeed *= -1;
	circle.setPosition(circle.getPosition().x, window->getSize().y / 2);
	circle.move(circleSpeed * dt, 0);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
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