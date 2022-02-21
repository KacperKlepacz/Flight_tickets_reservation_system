#pragma once
#include "DateTime.h"
enum FSM;
class DateOfFlightDisplay
{
public:

	void draw(sf::RenderWindow& window, FSM& fsm, int checkdest, sf::Sprite& background, sf::Sprite& logo);
	DateOfFlightDisplay(float width, float height, sf::Texture& button, sf::Font& font);
	DateTime dateTime;
	sf::Sprite button1;
	sf::Sprite button2;
	sf::Sprite button3;
	sf::Sprite button4;
	sf::Text *montime;
	sf::Text *wedtime;
	sf::Text *fritime;
	sf::Text dayprint;
	sf::Text timetprint;
	int ymouseposition;
	int xmouseposition;

};

