#pragma once
#include "Ticket.h"
#include "SFML/Graphics.hpp"


Ticket::Ticket(float width, float height) {

	font.loadFromFile("Minecraft-Regular.otf");

	ticket[0].setFont(font);
	ticket[0].setFillColor(sf::Color::White);
	ticket[0].setString("Your ticket:");
	ticket[0].setPosition(sf::Vector2f((width / 4) - 145, height / ((MAX_NUMBER_OF_TICKET_ITEMS + 1) * 1)-150));

	ticket[1].setFont(font);
	ticket[1].setFillColor(sf::Color::Magenta);
	ticket[1].setString("Done");
	ticket[1].setPosition(sf::Vector2f((width / 2) + 50, height / ((MAX_NUMBER_OF_TICKET_ITEMS + 1) * 2)+680));

	selectedItemIndex = 0;
}

Ticket::~Ticket() {}

void Ticket::draw(sf::RenderWindow& window) {

	for (int i = 0; i < MAX_NUMBER_OF_TICKET_ITEMS; i++) {

		window.draw(ticket[i]);

	}

}

void Ticket::MoveUp() {

	if (selectedItemIndex - 1 >= 1) {

		ticket[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		ticket[selectedItemIndex].setFillColor(sf::Color::Magenta);

	}

}
void Ticket::MoveDown() {

	if (selectedItemIndex + 1 < MAX_NUMBER_OF_TICKET_ITEMS) {

		ticket[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		ticket[selectedItemIndex].setFillColor(sf::Color::Magenta);

	}

}