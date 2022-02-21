#pragma once
#include "AlertWindow.h"
#include "SFML/Graphics.hpp"


#include "SFML/Graphics.hpp"


AlertWindow::AlertWindow(float width, float height) {

	font.loadFromFile("Minecraft-Regular.otf");

	alertWindow[0].setFont(font);
	alertWindow[0].setFillColor(sf::Color::White);
	alertWindow[0].setString("Yes");
	alertWindow[0].setPosition(sf::Vector2f((width / 4)-145,height/(MAX_NUMBER_OF_ALERT_ITEMS + 1)));

	alertWindow[1].setFont(font);
	alertWindow[1].setFillColor(sf::Color::White);
	alertWindow[1].setString("No");
	alertWindow[1].setPosition(sf::Vector2f((width / 4)-200, height / (MAX_NUMBER_OF_ALERT_ITEMS + 1)));


	selectedItemIndex = 0;
}

AlertWindow::~AlertWindow() {}

void AlertWindow::draw(sf::RenderWindow& window) {

	for (int i = 0; i < MAX_NUMBER_OF_ALERT_ITEMS; i++) {

		window.draw(alertWindow[i]);

	}

}

void AlertWindow::MoveUp() {

	if (selectedItemIndex - 1 >= 0) {

		alertWindow[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		alertWindow[selectedItemIndex].setFillColor(sf::Color::Magenta);

	}

}
void AlertWindow::MoveDown() {

	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ALERT_ITEMS) {

		alertWindow[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		alertWindow[selectedItemIndex].setFillColor(sf::Color::Magenta);

	}
}
