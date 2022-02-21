#pragma once
#include "Menu.h"
enum FSM;
class MainMenuDisplay
{
public:

	void draw(sf::RenderWindow& window, FSM& fsm, int isticketavailable, sf::Sprite& background, sf::Sprite& logo);
	MainMenuDisplay(float width, float height, sf::Texture& button,sf::Font& font);
	Menu menu;
	sf::Sprite button1;
	sf::Sprite button2;
	sf::Sprite button3;
	sf::Text infoprint;
	int ymouseposition;
	int xmouseposition;

};

