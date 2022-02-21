#pragma once
#include "DataWindow.h"
enum FSM;
class EnterDataDisplay
{
public:

	void draw(sf::RenderWindow& window, FSM& fsm, int& randseat, sf::Sprite& background, sf::Sprite& logo);
	EnterDataDisplay(float width, float height, sf::Texture& button, sf::Font& font);
	DataWindow dataWindow;
	sf::Sprite button1;
	sf::Sprite button2;
	sf::Sprite button3;
	sf::Sprite button4;
	sf::Sprite button5;
	sf::Sprite button6;
	sf::Sprite button7;
	sf::Sprite button8;
	sf::Text name;
	sf::Text surname;
	sf::Text email;
	sf::String nameInput;
	sf::String surnameInput;
	sf::String emailInput;
	int ymouseposition;
	int xmouseposition;

};

