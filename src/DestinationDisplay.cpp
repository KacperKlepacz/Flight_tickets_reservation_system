#include "DestinationDisplay.h"
#include <iostream>
#include "fsm.h"

DestinationDisplay::DestinationDisplay(float width, float height, sf::Texture& button, sf::Texture& italyflagtexture, sf::Texture& germanyflagtexture, sf::Texture& maldivesflagtexture, sf::Font& font) :
    chooseDestination(width, height),
    destinationprint("", font),
    montime("", font),
    wedtime("", font),
    fritime("", font)
{

    button1.setTexture(button);
    button2.setTexture(button);
    button3.setTexture(button);
    button4.setTexture(button);
    italyflag.setTexture(italyflagtexture);
    germanyflag.setTexture(germanyflagtexture);
    maldivesflag.setTexture(maldivesflagtexture);
    italyflag.scale(sf::Vector2f(0.25,0.25));
    germanyflag.scale(sf::Vector2f(0.4,0.4));
    maldivesflag.scale(sf::Vector2f(0.22,0.22));
    button1.scale(sf::Vector2f(0.7, 0.5));
    button2.scale(sf::Vector2f(0.7, 0.5));
    button3.scale(sf::Vector2f(0.7, 0.5));
    button4.scale(sf::Vector2f(0.7, 0.5));
    xmouseposition = 0;
    ymouseposition = 0;

}

void DestinationDisplay::draw(sf::RenderWindow& window, FSM& fsm, int& checkdest, sf::Sprite& background, sf::Sprite& logo) {

    button1.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 1) + 70));
    button2.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 2) - 20));
    button3.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 3) - 110));
    button4.setPosition(sf::Vector2f((1920 / 4) - 200 - 35, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 3) + 70));
    maldivesflag.setPosition(sf::Vector2f((1920 / 4) - 350, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 1) + 78));
    italyflag.setPosition(sf::Vector2f((1920 / 4) - 350, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 2) - 15));
    germanyflag.setPosition(sf::Vector2f((1920 / 4) - 350, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 3) - 100));

    sf::Event event;

    while (window.pollEvent(event)) {

        switch (event.type) {

        case sf::Event::KeyReleased:
            switch (event.key.code) {

            case sf::Keyboard::Up:
                chooseDestination.MoveUp();
                break;

            case sf::Keyboard::Down:
                chooseDestination.MoveDown();
                break;

            case sf::Keyboard::Return:
                switch (chooseDestination.GetPressedItem()) {
                case 0:
                    std::cout << "Destination Male chosen" << std::endl;
                    fsm = Dateofflight;
                    break;
                case 1:
                    std::cout << "Destination chosen" << std::endl;
                    destinationprint.setString("MLE"); checkdest = 1;
                    montime.setString("10:00");
                    wedtime.setString("14:00");
                    fritime.setString("17:00");
                    fsm = Dateofflight;
                    break;
                case 2:
                    std::cout << "Destination Mediolan chosen" << std::endl;
                    destinationprint.setString("MXP"); checkdest = 2;
                    montime.setString("11:00");
                    wedtime.setString("16:00");
                    fritime.setString("21:00");
                    fsm = Dateofflight;
                    break;
                case 3:
                    std::cout << "Destination Berlin chosen" << std::endl;
                    destinationprint.setString("SXF"); checkdest = 3;
                    montime.setString("11:54");
                    wedtime.setString("23:00");
                    fritime.setString("23:50");

                    fsm = Dateofflight;
                    break;
                case 4:
                    fsm = Airport;
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
                    std::cout << "Destination Male chosen\n";
                   // std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                    destinationprint.setString("MLE"); checkdest = 1;
                    montime.setString("10:00");
                    wedtime.setString("14:00");
                    fritime.setString("17:00");
                    fsm = Dateofflight;
                }
                else if (ymouseposition >= 523 && ymouseposition <= 597 && xmouseposition >= 247 && xmouseposition <= 600) {
                    std::cout << "Destination Mediolan chosen\n";
                   // std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                    destinationprint.setString("MXP"); checkdest = 2;
                    montime.setString("11:00");
                    wedtime.setString("16:00");
                    fritime.setString("21:00");
                    fsm = Dateofflight;
                }
                else if (ymouseposition >= 704 && ymouseposition <= 778 && xmouseposition >= 247 && xmouseposition <= 600) {
                    std::cout << "Destination Berlin chosen\n";
                   // std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                    destinationprint.setString("SXF"); checkdest = 3;
                    montime.setString("11:54");
                    wedtime.setString("23:00");
                    fritime.setString("23:50");
                    fsm = Dateofflight;
                }
                else if (ymouseposition >= 883 && ymouseposition <= 959 && xmouseposition >= 247 && xmouseposition <= 600) {
                    std::cout << "Back\n";
                   // std::cout << ymouseposition << ":" << xmouseposition << std::endl;
                    fsm = Airport;
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
    window.draw(maldivesflag);
    window.draw(italyflag);
    window.draw(germanyflag);
    chooseDestination.draw(window);
    window.display();


}