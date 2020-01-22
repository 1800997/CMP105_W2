#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();
	double calcX = 0;
	double calcY = 0;
	double calcX2 = 0;
	double calcY2 = 0;
	double distance = 0;
	bool pressed = false;
	void handleInput();
	void update();
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// Add your object here
	sf::Text mousePosition;
	sf::Font font;
	sf::CircleShape circle;
	
};