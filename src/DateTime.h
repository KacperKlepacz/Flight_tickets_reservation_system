#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_DESTINATION_ITEMS 5
#define MAX_NUMBER_OF_ITEMS 3

class DateTime
{
public:
	DateTime(float width, float height);
	~DateTime();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }


private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text dateTime[MAX_NUMBER_OF_DESTINATION_ITEMS];
};


