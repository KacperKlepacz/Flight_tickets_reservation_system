#include "EnterDataDisplay.h"
#include <iostream>
#include <random>
#include "fsm.h"

EnterDataDisplay::EnterDataDisplay(float width, float height, sf::Texture& button, sf::Font& font) :
    dataWindow(width, height),
    name("", font),
    surname("", font),
    email("", font)
{

    button1.setTexture(button);
    button2.setTexture(button);
    button3.setTexture(button);
    button4.setTexture(button);
    button5.setTexture(button);
    button6.setTexture(button);
    button7.setTexture(button);
    button8.setTexture(button);
    button1.scale(sf::Vector2f(0.7, 0.5));
    button2.scale(sf::Vector2f(0.7, 0.5));
    button3.scale(sf::Vector2f(0.7, 0.5));
    button4.scale(sf::Vector2f(0.7, 0.5));
    button5.scale(sf::Vector2f(1, 0.5));
    button6.scale(sf::Vector2f(1, 0.5));
    button7.scale(sf::Vector2f(1, 0.5));
    button8.scale(sf::Vector2f(0.7, 0.5));
    xmouseposition = 0;
    ymouseposition = 0;

}

void EnterDataDisplay::draw(sf::RenderWindow& window, FSM& fsm,int& randseat, sf::Sprite& background, sf::Sprite& logo) {

    button1.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 1) + 70));
    button2.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 2) - 20));
    button3.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 3) - 110));
    button4.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 3) + 70));
    button5.setPosition(sf::Vector2f((1920 / 4) + 120, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 1) + 70));
    button6.setPosition(sf::Vector2f((1920 / 4) + 120, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 2) - 20));
    button7.setPosition(sf::Vector2f((1920 / 4) + 120, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 3) - 110));
    button8.setPosition(sf::Vector2f((1920 / 4) + 120, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 3) + 70));

    name.setFillColor(sf::Color::White);
    name.setCharacterSize(30U);
    name.setPosition(sf::Vector2f((1920 / 4) + 150, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 1) + 90));
    surname.setFillColor(sf::Color::White);
    surname.setCharacterSize(30U);
    surname.setPosition(sf::Vector2f((1920 / 4) + 150, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 2)));
    email.setFillColor(sf::Color::White);
    email.setCharacterSize(30U);
    email.setPosition(sf::Vector2f((1920 / 4) + 150, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 3) - 90));

    sf::Event event;

    while (window.pollEvent(event)) {

        switch (event.type) {

        case sf::Event::KeyReleased:
            switch (event.key.code) {

            case sf::Keyboard::Up:
                dataWindow.MoveUp();
                break;
            case sf::Keyboard::Left:
                dataWindow.MoveUp();
                break;

            case sf::Keyboard::Down:
                dataWindow.MoveDown();
                break;
            case sf::Keyboard::Right:
                dataWindow.MoveDown();
                break;

            case sf::Keyboard::Return:
                switch (dataWindow.GetPressedItem()) {
                case 0:
                    std::cout << "Data chosen" << std::endl;

                    fsm = EnterData;
                    break;
                case 1:
                    std::cout << "Name chosen" << std::endl;

                    fsm = EnterData;
                    break;
                case 2:
                    std::cout << "Surame chosen" << std::endl;

                    fsm = EnterData;
                    break;
                case 3:
                    std::cout << "Email chosen" << std::endl;

                    fsm = EnterData;
                    break;
                case 4:
                    std::cout << "BACK" << std::endl;
                    fsm = Dateofflight;
                    break;
                case 5:
                    std::cout << "Print ticket" << std::endl;
                    std::random_device dev;
                    std::mt19937 rng(dev());
                    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 230);
                    randseat = dist6(rng);
                    fsm = PrintTicket;
                    break;
                }
            }
            break;
        case sf::Event::MouseButtonPressed:
            switch (event.key.code) {

            case sf::Mouse::Left:
                ymouseposition = sf::Mouse::getPosition(window).y;
                xmouseposition = sf::Mouse::getPosition(window).x;
                if (ymouseposition >= 883 && ymouseposition <= 959 && xmouseposition >= 247 && xmouseposition <= 600) {
                    std::cout << "Back\n";
                   // std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                    fsm = Dateofflight;
                }
                else if (ymouseposition >= 883 && ymouseposition <= 958 && xmouseposition >= 602 && xmouseposition <= 955) {
                    std::cout << "Print Ticket\n";
                   // std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                    std::random_device dev;
                    std::mt19937 rng(dev());
                    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 230);
                    randseat = dist6(rng);
                    fsm = PrintTicket;
                }
                else {
                    std::cout << "Clicked LMB\n";
                    std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                }
                break;
            }
            break;

        case sf::Event::TextEntered:
            if (event.text.unicode < 128) {
                switch (dataWindow.GetPressedItem()) {
                case 1:
                    if (event.text.unicode == '\b' && nameInput.getSize() != 0) { nameInput.erase(nameInput.getSize() - 1, 1); }
                    else if (event.text.unicode != '\b') { nameInput += event.text.unicode; }
                    name.setString(nameInput);
                    break;
                case 2:
                    if (event.text.unicode == '\b' && surnameInput.getSize() != 0) { surnameInput.erase(surnameInput.getSize() - 1, 1); }
                    else if (event.text.unicode != '\b') { surnameInput += event.text.unicode; }
                    surname.setString(surnameInput);
                    break;
                case 3:
                    if (event.text.unicode == '\b' && emailInput.getSize() != 0) { emailInput.erase(emailInput.getSize() - 1, 1); }
                    else if (event.text.unicode != '\b') { emailInput += event.text.unicode; }
                    email.setString(emailInput);
                    break;
                }
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
    window.draw(button5);
    window.draw(button6);
    window.draw(button7);
    window.draw(button8);
    window.draw(name);
    window.draw(surname);
    window.draw(email);
    dataWindow.draw(window);
    window.display();

}