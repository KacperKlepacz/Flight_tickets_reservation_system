#include "DataWindow.h"
#include "SFML/Graphics.hpp"


DataWindow::DataWindow(float width, float height) {

	font.loadFromFile("Minecraft-Regular.otf");

	dataWindow[0].setFont(font);
	dataWindow[0].setFillColor(sf::Color::White);
	dataWindow[0].setString("Enter your data:");
	dataWindow[0].setPosition(sf::Vector2f((width / 4) - 145, height / ((MAX_NUMBER_OF_DATA_ITEMS ) * 1) + 40));

	dataWindow[1].setFont(font);
	dataWindow[1].setFillColor(sf::Color::Magenta);
	dataWindow[1].setString("Name:");
	dataWindow[1].setPosition(sf::Vector2f((width / 4) - 180, height / (MAX_NUMBER_OF_DATA_ITEMS ) * 2));

	dataWindow[2].setFont(font);
	dataWindow[2].setFillColor(sf::Color::White);
	dataWindow[2].setString("Surname:");
	dataWindow[2].setPosition(sf::Vector2f((width / 4) - 180, height / (MAX_NUMBER_OF_DATA_ITEMS ) * 3));

	dataWindow[3].setFont(font);
	dataWindow[3].setFillColor(sf::Color::White);
	dataWindow[3].setString("Email:");
	dataWindow[3].setPosition(sf::Vector2f((width / 4) - 180, height / (MAX_NUMBER_OF_DATA_ITEMS ) * 4));

	dataWindow[4].setFont(font);
	dataWindow[4].setFillColor(sf::Color::White);
	dataWindow[4].setString("Back");
	dataWindow[4].setPosition(sf::Vector2f((width / 4) - 80, height / (MAX_NUMBER_OF_DATA_ITEMS ) * 5));
	
	dataWindow[5].setFont(font);
	dataWindow[5].setFillColor(sf::Color::White);
	dataWindow[5].setString("Print ticket");
	dataWindow[5].setPosition(sf::Vector2f((width / 4) + 220, height / (MAX_NUMBER_OF_DATA_ITEMS ) * 5));

	selectedItemIndex = 1;
}

DataWindow::~DataWindow() {}

void DataWindow::draw(sf::RenderWindow& window) {

	for (int i = 0; i < MAX_NUMBER_OF_DATA_ITEMS; i++) {

		window.draw(dataWindow[i]);

	}

}

void DataWindow::MoveUp() {

	if (selectedItemIndex - 1 >= 1) {

		dataWindow[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		dataWindow[selectedItemIndex].setFillColor(sf::Color::Magenta);

	}

}
void DataWindow::MoveDown() {

	if (selectedItemIndex + 1 < MAX_NUMBER_OF_DATA_ITEMS) {

		dataWindow[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		dataWindow[selectedItemIndex].setFillColor(sf::Color::Magenta);

	}

}