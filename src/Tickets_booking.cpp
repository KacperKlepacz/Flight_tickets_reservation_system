#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "ChooseDestination.h"
#include "ChooseAirport.h"
#include "DataWindow.h"
#include "Ticket.h"
#include "DateTime.h"
#include <cstdlib>
#include <string>
#include "fsm.h"
#include "MainMenuDisplay.h"
#include "DestinationDisplay.h"
#include "AirportDisplay.h"
#include "EnterDataDisplay.h"
#include "ticketDisplay.h"
#include "DateOfFlightDisplay.h"

int main()
{
    FSM fsm = MainMenu;
    
    int checkdest = 0;
    int airportsymbol = 0;
    int isticketavailable = 0;
    int randseat;
    
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Tickets booking");
    sf::Texture texture_bcg;
    sf::Texture texture_logo;
    sf::Texture texture_button;
    sf::Texture texture_ticket;
    sf::Texture kremowkatext;
    sf::Texture italyflagtexture;
    sf::Texture germanyflagtexture;
    sf::Texture maldivesflagtexture;
    sf::Texture hutatexture;
    sf::Texture balicetexture;

    hutatexture.loadFromFile("hutnictwosymbol.png");
    balicetexture.loadFromFile("balicelotnisko.png");
    italyflagtexture.loadFromFile("italyflag.jpg");
    germanyflagtexture.loadFromFile("germanyflag.png");
    maldivesflagtexture.loadFromFile("maldivesflag.jpg");
    texture_ticket.loadFromFile("ticket.jpg");
    texture_bcg.loadFromFile("backgroundplane.jpg");
    texture_logo.loadFromFile("airlineslogo.PNG");
    texture_button.loadFromFile("button.png");
    kremowkatext.loadFromFile("kremowka.png");

    sf::Sprite background;
    sf::Sprite logo;
       
    background.setTexture(texture_bcg);
    logo.setTexture(texture_logo);
    logo.setPosition(sf::Vector2f(1920 / 4, 1080 / 16));
        
    sf::Font font;
    font.loadFromFile("Minecraft-Regular.otf");

    MainMenuDisplay mainMenuDisplay(window.getSize().x, window.getSize().y,texture_button,font);
    DestinationDisplay destinationDisplay(window.getSize().x, window.getSize().y, texture_button, italyflagtexture, germanyflagtexture, maldivesflagtexture , font);
    AirportDisplay airportDisplay(window.getSize().x, window.getSize().y, texture_button, font);
    EnterDataDisplay enterDataDisplay(window.getSize().x, window.getSize().y, texture_button, font);
    TicketDisplay ticketDisplay(window.getSize().x, window.getSize().y, texture_button, texture_ticket, kremowkatext, hutatexture, balicetexture, font);
    DateOfFlightDisplay dateOfFlightDisplay(window.getSize().x, window.getSize().y, texture_button, font);

    ticketDisplay.name = &enterDataDisplay.name;
    ticketDisplay.surname = &enterDataDisplay.surname;
    ticketDisplay.dayprint = &dateOfFlightDisplay.dayprint;
    ticketDisplay.destinationprint = &destinationDisplay.destinationprint;
    ticketDisplay.flightno = &airportDisplay.flightno;
    ticketDisplay.timetprint = &dateOfFlightDisplay.timetprint;
    dateOfFlightDisplay.montime = &destinationDisplay.montime;
    dateOfFlightDisplay.wedtime = &destinationDisplay.wedtime;
    dateOfFlightDisplay.fritime = &destinationDisplay.fritime;
        
    while (window.isOpen()) {
        if (fsm == MainMenu) { mainMenuDisplay.draw(window,fsm,isticketavailable,background,logo); }
        else if (fsm == Destination) { destinationDisplay.draw(window, fsm, checkdest, background, logo); }
        else if (fsm == Airport)  { airportDisplay.draw(window, fsm, airportsymbol, background, logo); }
        else if (fsm == EnterData)  { enterDataDisplay.draw(window, fsm,randseat, background, logo); }
        else if (fsm == PrintTicket) { ticketDisplay.draw(window,fsm,airportsymbol,isticketavailable,randseat,background,logo); }
        else if (fsm == Dateofflight) { dateOfFlightDisplay.draw(window, fsm, checkdest, background, logo); }
    }
}
