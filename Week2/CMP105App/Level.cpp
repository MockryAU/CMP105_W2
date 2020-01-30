#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	mousePosX.setFont(font);
	mousePosX.setCharacterSize(24);
	mousePosX.setFillColor(sf::Color::Yellow);

	mousePosY.setFont(font);
	mousePosY.setCharacterSize(24);
	mousePosY.setFillColor(sf::Color::Yellow);
	mousePosY.setPosition(0, 30);

	circle.setRadius(20);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(-50, -50); //so it starts off the screen

}

Level::~Level()
{
	input = nullptr;
}

void Level::leftClick()
{
	if (pressed == false)
	{
		if (input->isMouseLDown() == true)
		{
			mouseX1 = input->getMouseX();
			mouseY1 = input->getMouseY();
			pressed = true;
			cout << "X1: " << mouseX1 << " Y1: " << mouseY1 << endl;
		}
	}
	if (pressed == true)
	{
		if (input->isMouseLDown() == false)
		{
			mouseX2 = input->getMouseX();
			mouseY2 = input->getMouseY();
			cout << "X2: " << mouseX2 << " Y2: " << mouseY2 << endl;
			pressed = false;
			//outputs the distance between where the mouse was clicked and released to the console window
			cout << pythagoras(mouseX1, mouseY1, mouseX2, mouseY2);
		}
	}
}

void Level::rightClick(sf::CircleShape& circle)
{
	if (pressedR == false)
	{
		if (input->isMouseRDown() == true)
		{
			circle.setPosition(input->getMouseX(), input->getMouseY());
			pressedR = true;
		}
	}
	if (pressedR == true)
	{
		if (input->isMouseRDown() == false)
		{
			pressedR = false;
		}
	}
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "Pressed a Button";
	}
	if (input->isKeyDown(sf::Keyboard::J) &&
		input->isKeyDown(sf::Keyboard::K) &&
		input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "Look at all these buttons I can press!\n";
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
		window->close();

	//displays mouse postion
	std::string output("X: ");
	output += std::to_string(input->getMouseX());
	mousePosX.setString(output); // turns mouse position into a std string before converting it to a sf string that can be rendered

	std::string outputY("Y: ");
	outputY += std::to_string(input->getMouseY());
	mousePosY.setString(outputY);

	//only checks for the left mouse being down while it hasn't been pressed and vice versa
	leftClick();
	//put in a seperate function to de-clutter input function
	rightClick(circle);
}

// Update game objects
void Level::update()
{

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(mousePosX);
	window->draw(mousePosY);
	window->draw(circle);

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

//uses pythagoras to calculate the distance between the two points
double Level::pythagoras(int X1, int Y1, int X2, int Y2)
{
	double X3 = pow((X1 - X2), 2);
	double Y3 = pow((Y1 - Y2), 2);
	double distance = sqrt(Y3 + X3);
	return distance;
}
