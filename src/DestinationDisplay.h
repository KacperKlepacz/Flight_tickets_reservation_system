#pragma once
#include "ChooseDestination.h"
enum FSM;
class DestinationDisplay
{
public:

	void draw(sf::RenderWindow& window, FSM& fsm, int& checkdest, sf::Sprite& background, sf::Sprite& logo);
	DestinationDisplay(float width, float height, sf::Texture& button, sf::Texture& italyflagtexture, sf::Texture& germanyflagtexture, sf::Texture& maldivesflagtexture, sf::Font& font);
	ChooseDestination chooseDestination;
	sf::Sprite button1;
	sf::Sprite button2;
	sf::Sprite button3;
	sf::Sprite button4;
	sf::Sprite italyflag;
	sf::Sprite germanyflag;
	sf::Sprite maldivesflag;
	sf::Text destinationprint;
	sf::Text montime;
	sf::Text wedtime;
	sf::Text fritime;
	int ymouseposition;
	int xmouseposition;

};

