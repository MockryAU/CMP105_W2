#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>
#include <cmath>

using namespace std;

class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput();
	void update();
	void render();
	double pythagoras(int X1, int Y1, int X2, int Y2);
	void leftClick();
	void rightClick(sf::CircleShape&);

	//holds values for calulating distance between two points
	int mouseX1 = 0;
	int mouseX2 = 0;
	int mouseY1 = 0;
	int mouseY2 = 0;
	int distance = 0;
	//leaving these as public since 4 getters/setters is too annoying atm. might improve it later

	bool pressed = false;
	bool pressedR = false;

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
	
	sf::Font font;
	sf::Text mousePosX;
	sf::Text mousePosY;
	sf::Text travel; //for displaying the distance the mouse travels

	
	// Add your object here
	sf::CircleShape circle;
};