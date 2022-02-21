#include "ChooseDestination.h"
#include "SFML/Graphics.hpp"


ChooseDestination::ChooseDestination(float width, float height) {

	font.loadFromFile("Minecraft-Regular.otf");

	chooseDestination[0].setFont(font);
	chooseDestination[0].setFillColor(sf::Color::White);
	chooseDestination[0].setString("Choose your destination:");
	chooseDestination[0].setPosition(sf::Vector2f((width / 4) - 145, height / ((MAX_NUMBER_OF_DESTINATION_ITEMS + 1) * 1) + 40));
	
	chooseDestination[1].setFont(font);
	chooseDestination[1].setFillColor(sf::Color::Magenta);
	chooseDestination[1].setString("Maldives - Male");
	chooseDestination[1].setPosition(sf::Vector2f((width / 4) - 180, height / (MAX_NUMBER_OF_DESTINATION_ITEMS + 1) * 2));
	
	chooseDestination[2].setFont(font);
	chooseDestination[2].setFillColor(sf::Color::White);
	chooseDestination[2].setString("Italy - Mediolan");
	chooseDestination[2].setPosition(sf::Vector2f((width / 4) - 180, height / (MAX_NUMBER_OF_DESTINATION_ITEMS + 1) * 3));

	chooseDestination[3].setFont(font);
	chooseDestination[3].setFillColor(sf::Color::White);
	chooseDestination[3].setString("Germany - Berlin");
	chooseDestination[3].setPosition(sf::Vector2f((width / 4) - 180, height / (MAX_NUMBER_OF_DESTINATION_ITEMS + 1) * 4));

	chooseDestination[4].setFont(font);
	chooseDestination[4].setFillColor(sf::Color::White);
	chooseDestination[4].setString("Back");
	chooseDestination[4].setPosition(sf::Vector2f((width / 4) - 80, height / (MAX_NUMBER_OF_DESTINATION_ITEMS + 1) * 5));

	selectedItemIndex = 1;
}

ChooseDestination::~ChooseDestination() {}

void ChooseDestination::draw(sf::RenderWindow& window) {

	for (int i = 0; i < MAX_NUMBER_OF_DESTINATION_ITEMS; i++) {

		window.draw(chooseDestination[i]);

	}

}

void ChooseDestination::MoveUp() {

	if (selectedItemIndex - 1 >= 1) {

		chooseDestination[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		chooseDestination[selectedItemIndex].setFillColor(sf::Color::Magenta);

	}

}
void ChooseDestination::MoveDown() {

	if (selectedItemIndex + 1 < MAX_NUMBER_OF_DESTINATION_ITEMS) {

		chooseDestination[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		chooseDestination[selectedItemIndex].setFillColor(sf::Color::Magenta);

	}

}