#pragma once
#include "ChooseAirport.h"
enum FSM;
class AirportDisplay
{
public:

	void draw(sf::RenderWindow& window, FSM& fsm, int& airportsymbol, sf::Sprite& background, sf::Sprite& logo);
	AirportDisplay(float width, float height, sf::Texture& button, sf::Font& font);
	ChooseAirport chooseAirport;
	sf::Sprite button1;
	sf::Sprite button2;
	sf::Sprite button3;
	sf::Sprite button4;
	sf::Text flightno;
	int ymouseposition;
	int xmouseposition;

};

