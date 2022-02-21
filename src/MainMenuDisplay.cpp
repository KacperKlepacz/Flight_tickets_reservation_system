#include "MainMenuDisplay.h"
#include <iostream>
#include "fsm.h"


MainMenuDisplay::MainMenuDisplay(float width, float height, sf::Texture& button, sf::Font& font) :
    menu(width,height)
{

	button1.setTexture(button);
    button2.setTexture(button);
    button3.setTexture(button);
    button1.scale(sf::Vector2f(0.7, 0.5));
    button2.scale(sf::Vector2f(0.7, 0.5));
    button3.scale(sf::Vector2f(0.7, 0.5));
    infoprint=sf::Text("", font);
    xmouseposition = 0;
    ymouseposition = 0;

}

void MainMenuDisplay::draw(sf::RenderWindow& window, FSM& fsm,int isticketavailable,sf::Sprite& background, sf::Sprite& logo) {

    button1.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 1) - 20));
    button2.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 2) - 20));
    button3.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 3) - 20));

    infoprint.setFillColor(sf::Color::Red);
    infoprint.setCharacterSize(20U);
    infoprint.setPosition(sf::Vector2f((1920 / 4) - 230, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 2 + 70)));

    sf::Event event;

    while (window.pollEvent(event)) {

        switch (event.type) {

        case sf::Event::KeyReleased:
            switch (event.key.code) {

            case sf::Keyboard::Up:
                menu.MoveUp();
                break;

            case sf::Keyboard::Down:
                menu.MoveDown();
                break;

            case sf::Keyboard::Return:
                switch (menu.GetPressedItem()) {
                case 0:
                    std::cout << "Pressed booking ticket button" << std::endl;
                    fsm = Airport;
                    break;
                case 1:
                    std::cout << "Pressed show booked ticket button" << std::endl;
                    if (isticketavailable == 1) { fsm = PrintTicket; }
                    else { infoprint.setString("You haven't booked any ticket yet"); }
                    break;
                case 2:
                    window.close();
                    break;
                }
            }
            break;
        case sf::Event::MouseButtonPressed:
            switch (event.key.code) {

            case sf::Mouse::Left:
                ymouseposition = sf::Mouse::getPosition(window).y;
                xmouseposition = sf::Mouse::getPosition(window).x;
                if (ymouseposition >= 252 && ymouseposition <= 329 && xmouseposition >= 247 && xmouseposition <= 600) {
                    std::cout << "Clicked Book a ticket\n";
                  //  std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                    fsm = Airport;
                }
                else if (ymouseposition >= 522 && ymouseposition <= 601 && xmouseposition >= 247 && xmouseposition <= 600) {
                    std::cout << "Clicked show booked ticket\n";
                   // std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                    if (isticketavailable == 1) { fsm = PrintTicket; }
                    else { infoprint.setString("You haven't booked any ticket yet"); }


                }
                else if (ymouseposition >= 793 && ymouseposition <= 870 && xmouseposition >= 247 && xmouseposition <= 600) {
                    std::cout << "Clicked Exit\n";
                   // std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                    window.close();
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

    window.clear();

    window.draw(background);
    window.draw(logo);
    window.draw(button1);
    window.draw(button2);
    window.draw(button3);
    if (isticketavailable == 0) { window.draw(infoprint); }
    menu.draw(window);
    window.display();

}
