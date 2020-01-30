#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	//Game objects
	sf::CircleShape circle;
	float circleSpeed;

	sf::CircleShape controlledCircle;
	float secondCircleSpeed;

	sf::CircleShape bouncingCircle;
	float thirdCircleSpeed;
	float horizontalDirection = 1.0f;
	float verticalDirection = -1.0f;

	sf::Text message;
	sf::Font font;
};