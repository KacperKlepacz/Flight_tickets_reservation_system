#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_AIRPORT_ITEMS 5
#define MAX_NUMBER_OF_ITEMS 3

class ChooseAirport
{
public:
	ChooseAirport(float width, float height);
	~ChooseAirport();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }


private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text chooseAirport[MAX_NUMBER_OF_AIRPORT_ITEMS];
};

