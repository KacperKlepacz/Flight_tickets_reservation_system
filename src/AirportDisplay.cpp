#include "AirportDisplay.h"
#include <iostream>
#include "fsm.h"

AirportDisplay::AirportDisplay(float width, float height, sf::Texture& button, sf::Font& font) :
    chooseAirport(width, height),
    flightno("", font)
{

    button1.setTexture(button);
    button2.setTexture(button);
    button3.setTexture(button);
    button4.setTexture(button);
    button1.scale(sf::Vector2f(0.7, 0.5));
    button2.scale(sf::Vector2f(0.7, 0.5));
    button3.scale(sf::Vector2f(0.7, 0.5));
    button4.scale(sf::Vector2f(0.7, 0.5));
    xmouseposition = 0;
    ymouseposition = 0;

}

void AirportDisplay::draw(sf::RenderWindow& window, FSM& fsm, int& airportsymbol, sf::Sprite& background, sf::Sprite& logo){

button1.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 1) + 70));
button2.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 2) - 20));
button3.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 3) - 110));
button4.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 3) + 70));

sf::Event event;

while (window.pollEvent(event)) {

    switch (event.type) {

    case sf::Event::KeyReleased:
        switch (event.key.code) {

        case sf::Keyboard::Up:
            chooseAirport.MoveUp();
            break;

        case sf::Keyboard::Down:
            chooseAirport.MoveDown();
            break;

        case sf::Keyboard::Return:
            switch (chooseAirport.GetPressedItem()) {
            case 0:
                std::cout << "Airport chosen" << std::endl;

                break;
            case 1:
                std::cout << "Airport chosen" << std::endl;
                flightno.setString("ZJ0203");
                airportsymbol = 2;
                fsm = Destination;
                break;
            case 2:
                std::cout << "Airport chosen" << std::endl;
                flightno.setString("JP2317");
                airportsymbol = 1;
                fsm = Destination;
                break;
            case 3:
                std::cout << "Airport chosen" << std::endl;
                flightno.setString("KK1103");
                airportsymbol = 3;
                fsm = Destination;
                break;
            case 4:
                fsm = MainMenu;
                break;
            }
        }
        break;
    case sf::Event::MouseButtonPressed:
        switch (event.key.code) {

        case sf::Mouse::Left:
            ymouseposition = sf::Mouse::getPosition(window).y;
            xmouseposition = sf::Mouse::getPosition(window).x;
            if (ymouseposition >= 342 && ymouseposition <= 420 && xmouseposition >= 247 && xmouseposition <= 600) {
                std::cout << "Airport chosen\n";
                flightno.setString("ZJ0203");
                airportsymbol = 2;
               // std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                fsm = Destination;
            }
            else if (ymouseposition >= 523 && ymouseposition <= 597 && xmouseposition >= 247 && xmouseposition <= 600) {
                std::cout << "Airport chosen\n";
                flightno.setString("JP2317");
                airportsymbol = 1;
               // std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                fsm = Destination;
            }
            else if (ymouseposition >= 704 && ymouseposition <= 778 && xmouseposition >= 247 && xmouseposition <= 600) {
                std::cout << "Airport chosen\n";
                flightno.setString("KK1103");
                airportsymbol = 3;
               // std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                fsm = Destination;

            }
            else if (ymouseposition >= 883 && ymouseposition <= 959 && xmouseposition >= 247 && xmouseposition <= 600) {
                std::cout << "Back\n";
               // std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                fsm = MainMenu;
            }

            else {
                std::cout << "Clicked LMB\n";
                std::cout << ymouseposition << ":" << xmouseposition << std::endl;
            }

            break;

        }
        break;

    case sf::Event::Closed:
        window.close();
        break;

    }

}


window.draw(background);
window.draw(logo);
window.draw(button1);
window.draw(button2);
window.draw(button3);
window.draw(button4);
chooseAirport.draw(window);
window.display();

}