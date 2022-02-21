#pragma once
#include "Ticket.h"
enum FSM;
class TicketDisplay
{
public:

	void draw(sf::RenderWindow& window, FSM& fsm, int airportsymbol, int& isticketavailable, int randseat, sf::Sprite& background, sf::Sprite& logo);
	TicketDisplay(float width, float height, sf::Texture& button, sf::Texture& texture_ticket, sf::Texture& kremowkatext, sf::Texture& hutatexture, sf::Texture& balicetexture, sf::Font& font);
	Ticket ticket;
	sf::Sprite button2;
	sf::Sprite tickett;
	sf::Sprite kremowka;
    sf::Sprite hutasymbol;
    sf::Sprite balicesymbol;
    sf::Text *name;
    sf::Text *surname;
    sf::Text *email;
    sf::Text *destinationprint;
    sf::Text seatprint;
    sf::Text seattext;
    sf::Text classtext;
    sf::Text *flightno;
    sf::Text *timetprint;
    sf::Text *dayprint;
	int ymouseposition;
	int xmouseposition;
    int randseat;
};

