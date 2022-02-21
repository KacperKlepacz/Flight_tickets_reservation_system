#include "ChooseAirport.h"
#include "SFML/Graphics.hpp"


ChooseAirport::ChooseAirport(float width, float height) {

	font.loadFromFile("Minecraft-Regular.otf");

	chooseAirport[0].setFont(font);
	chooseAirport[0].setFillColor(sf::Color::White);
	chooseAirport[0].setString("Choose your airport:");
	chooseAirport[0].setPosition(sf::Vector2f((width / 4) - 145, height / ((MAX_NUMBER_OF_AIRPORT_ITEMS + 1) * 1) + 40));

	chooseAirport[1].setFont(font);
	chooseAirport[1].setFillColor(sf::Color::Magenta);
	chooseAirport[1].setString("Cracow - Nowa Huta");
	chooseAirport[1].setPosition(sf::Vector2f((width / 4) - 200, height / (MAX_NUMBER_OF_AIRPORT_ITEMS + 1) * 2));

	chooseAirport[2].setFont(font);
	chooseAirport[2].setFillColor(sf::Color::White);
	chooseAirport[2].setString("Cracow - Wadowice");
	chooseAirport[2].setPosition(sf::Vector2f((width / 4) - 190, height / (MAX_NUMBER_OF_AIRPORT_ITEMS + 1) * 3));

	chooseAirport[3].setFont(font);
	chooseAirport[3].setFillColor(sf::Color::White);
	chooseAirport[3].setString("Cracow - Balice");
	chooseAirport[3].setPosition(sf::Vector2f((width / 4) - 180, height / (MAX_NUMBER_OF_AIRPORT_ITEMS + 1) * 4));

	chooseAirport[4].setFont(font);
	chooseAirport[4].setFillColor(sf::Color::White);
	chooseAirport[4].setString("Back");
	chooseAirport[4].setPosition(sf::Vector2f((width / 4) - 80, height / (MAX_NUMBER_OF_AIRPORT_ITEMS + 1) * 5));

	selectedItemIndex = 0;
}

ChooseAirport::~ChooseAirport() {}

void ChooseAirport::draw(sf::RenderWindow& window) {

	for (int i = 0; i < MAX_NUMBER_OF_AIRPORT_ITEMS; i++) {

		window.draw(chooseAirport[i]);

	}

}

void ChooseAirport::MoveUp() {

	if (selectedItemIndex - 1 >= 1) {

		chooseAirport[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		chooseAirport[selectedItemIndex].setFillColor(sf::Color::Magenta);

	}

}
void ChooseAirport::MoveDown() {

	if (selectedItemIndex + 1 < MAX_NUMBER_OF_AIRPORT_ITEMS) {

		chooseAirport[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		chooseAirport[selectedItemIndex].setFillColor(sf::Color::Magenta);

	}

}