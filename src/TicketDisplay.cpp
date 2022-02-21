#include "TicketDisplay.h"
#include <iostream>
#include <random>
#include "fsm.h"

TicketDisplay::TicketDisplay(float width, float height, sf::Texture& button, sf::Texture& texture_ticket, sf::Texture& kremowkatext, sf::Texture& hutatexture, sf::Texture& balicetexture, sf::Font& font) :
    ticket(width, height),
    seattext("Seat number:", font),
    classtext("Premium", font),
    seatprint("",font)
{
    button2.setTexture(button);
    tickett.setTexture(texture_ticket);
    kremowka.setTexture(kremowkatext);
    hutasymbol.setTexture(hutatexture);
    balicesymbol.setTexture(balicetexture);

    button2.scale(sf::Vector2f(0.7, 0.5));
    kremowka.scale(sf::Vector2f(0.5, 0.5));
    hutasymbol.scale(sf::Vector2f(0.13,0.13));
    balicesymbol.scale(sf::Vector2f(0.3, 0.3));
    xmouseposition = 0;
    ymouseposition = 0;
}
void TicketDisplay::draw(sf::RenderWindow& window, FSM& fsm, int airportsymbol, int& isticketavailable, int randseat, sf::Sprite& background, sf::Sprite& logo) {

    button2.setPosition(sf::Vector2f((1920 / 2) - 100, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 2) + 300));
    tickett.setPosition(sf::Vector2f((1920 / 2) - 800, (1080 / (MAX_NUMBER_OF_ITEMS + 1))));
    if (airportsymbol == 1) { kremowka.setPosition(sf::Vector2f((1920 / 2) + 400, (1080 / (MAX_NUMBER_OF_ITEMS + 1) + 350))); }
    else if (airportsymbol == 2) { hutasymbol.setPosition(sf::Vector2f((1920 / 2) + 400, (1080 / (MAX_NUMBER_OF_ITEMS + 1) + 350))); }
    if (airportsymbol == 3) { balicesymbol.setPosition(sf::Vector2f((1920 / 2) + 400, (1080 / (MAX_NUMBER_OF_ITEMS + 1) + 350))); }
    name->setFillColor(sf::Color::Black);
    name->setCharacterSize(30U);
    name->setPosition(sf::Vector2f((1920 / 4) - 230, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 1) + 165));

    surname->setFillColor(sf::Color::Black);
    surname->setCharacterSize(30U);
    surname->setPosition(sf::Vector2f((1920 / 4) - 30, (1080 / (MAX_NUMBER_OF_ITEMS + 1) + 165)));

    destinationprint->setFillColor(sf::Color::Black);
    destinationprint->setCharacterSize(160);
    destinationprint->setPosition(sf::Vector2f((1920 / 4) + 310, (1080 / (MAX_NUMBER_OF_ITEMS + 1) * 1) + 150));

    seatprint.setFillColor(sf::Color::Black);
    seatprint.setCharacterSize(30U);
    seatprint.setPosition(sf::Vector2f((1920 / 4) + 125, (1080 / (MAX_NUMBER_OF_ITEMS + 1) + 425)));
    seatprint.setString(std::to_string(randseat));

    seattext.setFillColor(sf::Color::Black);
    seattext.setCharacterSize(30U);
    seattext.setPosition(sf::Vector2f((1920 / 4) - 75, (1080 / (MAX_NUMBER_OF_ITEMS + 1) + 425)));

    classtext.setFillColor(sf::Color::Black);
    classtext.setCharacterSize(30U);
    classtext.setPosition(sf::Vector2f((1920 / 4) - 230, (1080 / (MAX_NUMBER_OF_ITEMS + 1) + 425)));

    flightno->setFillColor(sf::Color::Black);
    flightno->setCharacterSize(30U);
    flightno->setPosition(sf::Vector2f((1920 / 4) + 900, (1080 / (MAX_NUMBER_OF_ITEMS + 1) + 135)));

    timetprint->setFillColor(sf::Color::Black);
    timetprint->setCharacterSize(30U);
    timetprint->setPosition(sf::Vector2f((1920 / 4) - 30, (1080 / (MAX_NUMBER_OF_ITEMS + 1) + 295)));

    dayprint->setFillColor(sf::Color::Black);
    dayprint->setCharacterSize(30U);
    dayprint->setPosition(sf::Vector2f((1920 / 4) - 230, (1080 / (MAX_NUMBER_OF_ITEMS + 1) + 295)));

    sf::Event event;

    while (window.pollEvent(event)) {

        switch (event.type) {

        case sf::Event::KeyReleased:
            switch (event.key.code) {

            case sf::Keyboard::Up:
                ticket.MoveUp();
                break;

            case sf::Keyboard::Down:
                ticket.MoveDown();
                break;

            case sf::Keyboard::Return:
                switch (ticket.GetPressedItem()) {
                case 1:
                    std::cout << "exit" << std::endl;
                    isticketavailable = 1;
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
                if (ymouseposition >= 844 && ymouseposition <= 919 && xmouseposition >= 863 && xmouseposition <= 1215) {
                    std::cout << "exit" << std::endl;
                    isticketavailable = 1;
                    fsm = MainMenu;
                    //std::cout << ymouseposition << ":" << xmouseposition << std::endl;
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
    window.draw(button2);
    window.draw(tickett);
    window.draw(seatprint);
    window.draw(seattext);
    window.draw(*name);
    window.draw(*surname);
    window.draw(classtext);
    window.draw(*flightno);
    window.draw(*destinationprint);
    window.draw(*dayprint);
    window.draw(*timetprint);
    if (airportsymbol == 1) { window.draw(kremowka); }
    if (airportsymbol == 2) { window.draw(hutasymbol); }
    if (airportsymbol == 3) { window.draw(balicesymbol); }
    ticket.draw(window);
    window.display();

}