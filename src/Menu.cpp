#pragma once
#include "Menu.h"
#include "SFML/Graphics.hpp"


Menu::Menu(float width, float height) {

	font.loadFromFile("Minecraft-Regular.otf");

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Magenta);
	menu[0].setString("Book a ticket");
	menu[0].setPosition(sf::Vector2f((width / 4)-145,height/(MAX_NUMBER_OF_ITEMS+1)*1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Show booked ticket");
	menu[1].setPosition(sf::Vector2f((width / 4)-200, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f((width / 4)-80, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

Menu::~Menu() {}

void Menu::draw(sf::RenderWindow& window) {

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {

		window.draw(menu[i]);

	}

}

void Menu::MoveUp() {

	if (selectedItemIndex - 1 >= 0) {

		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Magenta);

	}

}
void Menu::MoveDown() {

	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {

		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Magenta);

	}

}