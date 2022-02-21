#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ALERT_ITEMS 2

class AlertWindow
{
public:
	AlertWindow(float width, float height);
	~AlertWindow();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }


private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text alertWindow[MAX_NUMBER_OF_ALERT_ITEMS];
};


