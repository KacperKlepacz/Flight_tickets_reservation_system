#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_DATA_ITEMS 6
#define MAX_NUMBER_OF_ITEMS 3

class DataWindow
{
public:
	DataWindow(float width, float height);
	~DataWindow();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void PrintData();
	int GetPressedItem() { return selectedItemIndex; }


private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text dataWindow[MAX_NUMBER_OF_DATA_ITEMS];
};

