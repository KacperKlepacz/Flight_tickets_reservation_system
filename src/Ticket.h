#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_TICKET_ITEMS 2
#define MAX_NUMBER_OF_ITEMS 3

class Ticket
{
public:
	Ticket(float width, float height);
	~Ticket();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }


private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text ticket[MAX_NUMBER_OF_TICKET_ITEMS];
};
