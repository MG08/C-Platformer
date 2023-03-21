#include<iostream>
using namespace std;
#include "SFML/Graphics.hpp"



int main() {
cout << "Platformer game!" << endl;

//game set up-------------------------------------------------------------------------
sf::RenderWindow screen(sf::VideoMode(800, 800), "Platformer");//set up screen
sf::Event event; //set up event queue (holds keyboard input and other stuff)
sf::Clock clock;//set up the clock (needed for game timing)
const float FPS = 60.0f; //FPS
screen.setFramerateLimit(FPS); //set FPS

//player setup----------------------------------------------------------------------
sf::RectangleShape player(sf::Vector2f(30, 30));
player.setFillColor(sf::Color::White);
float xpos = 25;
float ypos = 25;
player.setPosition(xpos, ypos);
//player velocity
float vx = .0;
float vy = .0;
bool isOnGround = false;
bool keys[] = { false, false, false, false };

//GAME LOOP##############################################################################
while (screen.isOpen()) {

	
	//input section-------------------------------------------------------------
	while (screen.pollEvent(event)) {

		if (event.type == sf::Event::EventType::Closed)
			screen.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) keys[2] = true;
		else keys[2] = false;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) keys[0] = true;
		else keys[0] = false;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) keys[3] = true;
		else keys[3] = false;

		
	}

	if (keys[2] == true)
		if (isOnGround == true) {
			vy = -15;
			isOnGround = false;
		}

	if (keys[0] == true)
		vx = 8;
	else
		vx = 0;

	if (keys[3] == true)
		vx = -8;
	else
		vx = 0;
	// physics section-------------------------------------------------------
	//GRAVITY
	if (ypos + 30 > 800) {
		isOnGround = true;
		ypos = 800 - 30;
	}
	else
		isOnGround = false;

	//apply gravity if not on ground
	if (isOnGround == false) {
		vy += 1;
		if (vy > 5)
			vy = 5;
	}

	//move the player
	xpos += vx;
	ypos += vy;
	player.setPosition(xpos, ypos);
	//render section-------------------------------------------------------
	screen.clear();

	screen.draw(player);

	screen.display();
}
//END GAME LOOP#########################################################################
