#include "DateOfFlightDisplay.h"
#include <iostream>
#include "fsm.h"

DateOfFlightDisplay::DateOfFlightDisplay(float width, float height, sf::Texture& button, sf::Font& font) :
    dateTime(width, height),
    dayprint("", font),
    timetprint("",font)
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

void DateOfFlightDisplay::draw(sf::RenderWindow& window,  FSM& fsm, int checkdest, sf::Sprite& background, sf::Sprite& logo) {

    button1.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 1) + 70));
    button2.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 2) - 20));
    button3.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 3) - 110));
    button4.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 3) + 70));

    montime->setFillColor(sf::Color::White);
    montime->setCharacterSize(30U);
    montime->setPosition(sf::Vector2f((1920 / 4), (1080 / (MAX_NUMBER_OF_ITEMS + 1) + 90)));

    wedtime->setFillColor(sf::Color::White);
    wedtime->setCharacterSize(30U);
    wedtime->setPosition(sf::Vector2f((1920 / 4), (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 2)));

    fritime->setFillColor(sf::Color::White);
    fritime->setCharacterSize(30U);
    fritime->setPosition(sf::Vector2f((1920 / 4), (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 3) - 90));

    sf::Event event;

    while (window.pollEvent(event)) {

        switch (event.type) {

        case sf::Event::KeyReleased:
            switch (event.key.code) {

            case sf::Keyboard::Up:
                dateTime.MoveUp();
                break;

            case sf::Keyboard::Down:
                dateTime.MoveDown();
                break;

            case sf::Keyboard::Return:
                switch (dateTime.GetPressedItem()) {
                case 1:
                    std::cout << "Day and time chosen" << std::endl;
                    dayprint.setString("Monday");
                    if (checkdest == 1) { timetprint.setString("10:00"); }
                    else if (checkdest == 2) { timetprint.setString("11:00"); }
                    else if (checkdest == 3) { timetprint.setString("11:54"); }
                    fsm = EnterData;
                    break;
                case 2:
                    std::cout << "Day and time chosen" << std::endl;
                    dayprint.setString("Tuesday");
                    if (checkdest == 1) { timetprint.setString("14:00"); }
                    else if (checkdest == 2) { timetprint.setString("16:00"); }
                    else if (checkdest == 3) { timetprint.setString("23:00"); }
                    fsm = EnterData;
                    break;
                case 3:
                    std::cout << "Day and time chosen" << std::endl;
                    dayprint.setString("Friday");
                    if (checkdest == 1) { timetprint.setString("17:00"); }
                    else if (checkdest == 2) { timetprint.setString("21:00"); }
                    else if (checkdest == 3) { timetprint.setString("23:50"); }
                    fsm = EnterData;
                    break;
                case 4:
                    fsm = Destination;
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
                    std::cout << "Day and time chosen\n";
                   // std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                    dayprint.setString("Monday");
                    if (checkdest == 1) { timetprint.setString("10:00"); }
                    else if (checkdest == 2) { timetprint.setString("11:00"); }
                    else if (checkdest == 3) { timetprint.setString("11:54"); }
                    fsm = EnterData;
                }
                else if (ymouseposition >= 523 && ymouseposition <= 597 && xmouseposition >= 247 && xmouseposition <= 600) {
                    std::cout << "Day and time chosen\n";
                   // std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                    dayprint.setString("Tuesday");
                    if (checkdest == 1) { timetprint.setString("14:00"); }
                    else if (checkdest == 2) { timetprint.setString("16:00"); }
                    else if (checkdest == 3) { timetprint.setString("23:00"); }
                    fsm = EnterData;
                }
                else if (ymouseposition >= 704 && ymouseposition <= 778 && xmouseposition >= 247 && xmouseposition <= 600) {
                    std::cout << "Day and time chosen\n";
                   // std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                    dayprint.setString("Friday");
                    if (checkdest == 1) { timetprint.setString("17:00"); }
                    else if (checkdest == 2) { timetprint.setString("21:00"); }
                    else if (checkdest == 3) { timetprint.setString("23:50"); }
                    fsm = EnterData;

                }
                else if (ymouseposition >= 883 && ymouseposition <= 959 && xmouseposition >= 247 && xmouseposition <= 600) {
                    std::cout << "Back\n";
                    //std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                    fsm = Destination;
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
    window.draw(*montime);
    window.draw(*wedtime);
    window.draw(*fritime);
    dateTime.draw(window);
    window.display();

}
