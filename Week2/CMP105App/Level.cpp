#include "Level.h"
#include <iostream>  
#include<string>  

using namespace std;

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	input->setMouseLDown(false);
	input->setMouseRDown(false);
	// initialise game objects
	mousePosition.setFillColor(sf::Color::Blue);
	mousePosition.setCharacterSize(50);
	font.loadFromFile("font/arial.ttf");
	mousePosition.setFont(font);

	circle.setFillColor(sf::Color::Red);
	circle.setRadius(30);
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{

	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W is pressed\n";
	}

	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);

		std::cout << "JKL is pressed. IT WOOORKS\n";
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		exit(0);
	}

	
	

	if (input->isMouseLDown())
	{
		if (!pressed)
		{
			calcX = input->getMouseX();
			calcY = input->getMouseY();
			pressed = true;
		}
		
	}

	if (calcX != 0)
	{
		if (!(input->isMouseLDown()))
		{
			calcX2 = input->getMouseX();
			calcY2 = input->getMouseY();
		}
		if (calcX2 != 0)
		{
			distance = ((calcX2 - calcX) * (calcX2 - calcX)) + ((calcY2 - calcY) * (calcY2 - calcY));
			distance = sqrt(distance);
			std::cout << "Distance is: " << distance <<"\n";
			calcX = 0;
			calcX2 = 0;
			calcY2 = 0;
			calcY = 0;
			pressed = false;
		}
	}

	if (input->isMouseRDown())
	{
		circle.setPosition((input->getMouseX())-30,(input->getMouseY())-30);
	}
}


// Update game objects
void Level::update()
{
	int mouseX = input->getMouseX();
	int mouseY = input->getMouseY();
	std::string output ("X: " + to_string(mouseX) + "   Y: " + to_string(mouseY));
	mousePosition.setString(output);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(mousePosition);
	if (input->isMouseRDown())
	{
		window->draw(circle);
	}
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
	
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}