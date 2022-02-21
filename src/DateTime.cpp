#include "DateTime.h"
#include "SFML/Graphics.hpp"


DateTime::DateTime(float width, float height) {

	font.loadFromFile("Minecraft-Regular.otf");

	dateTime[0].setFont(font);
	dateTime[0].setFillColor(sf::Color::White);
	dateTime[0].setString("Choose date and time:");
	dateTime[0].setPosition(sf::Vector2f((width / 4) - 145, height / ((MAX_NUMBER_OF_DESTINATION_ITEMS + 1) * 1) + 40));

	dateTime[1].setFont(font);
	dateTime[1].setFillColor(sf::Color::Magenta);
	dateTime[1].setString("Monday");
	dateTime[1].setPosition(sf::Vector2f((width / 4) - 180, height / (MAX_NUMBER_OF_DESTINATION_ITEMS + 1) * 2));

	dateTime[2].setFont(font);
	dateTime[2].setFillColor(sf::Color::White);
	dateTime[2].setString("Wednesday");
	dateTime[2].setPosition(sf::Vector2f((width / 4) - 180, height / (MAX_NUMBER_OF_DESTINATION_ITEMS + 1) * 3));

	dateTime[3].setFont(font);
	dateTime[3].setFillColor(sf::Color::White);
	dateTime[3].setString("Friday");
	dateTime[3].setPosition(sf::Vector2f((width / 4) - 180, height / (MAX_NUMBER_OF_DESTINATION_ITEMS + 1) * 4));

	dateTime[4].setFont(font);
	dateTime[4].setFillColor(sf::Color::White);
	dateTime[4].setString("Back");
	dateTime[4].setPosition(sf::Vector2f((width / 4) - 80, height / (MAX_NUMBER_OF_DESTINATION_ITEMS + 1) * 5));

	selectedItemIndex = 1;
}

DateTime::~DateTime() {}

void DateTime::draw(sf::RenderWindow& window) {

	for (int i = 0; i < MAX_NUMBER_OF_DESTINATION_ITEMS; i++) {

		window.draw(dateTime[i]);

	}

}

void DateTime::MoveUp() {

	if (selectedItemIndex - 1 >= 1) {

		dateTime[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		dateTime[selectedItemIndex].setFillColor(sf::Color::Magenta);

	}

}
void DateTime::MoveDown() {

	if (selectedItemIndex + 1 < MAX_NUMBER_OF_DESTINATION_ITEMS) {

		dateTime[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		dateTime[selectedItemIndex].setFillColor(sf::Color::Magenta);

	}

}