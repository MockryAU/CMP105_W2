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

	std::string output("X: ");
	output += std::to_string(input->getMouseX());

	mousePosX.setString(output);

	std::string outputY("Y: ");
	outputY += std::to_string(input->getMouseY());

	mousePosY.setString(outputY);
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