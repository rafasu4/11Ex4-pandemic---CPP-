//
// Created by stycks on 03/05/2021.
//

#ifndef EX4_A_PLAYER_HPP
#define EX4_A_PLAYER_HPP

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <set>

namespace pandemic {

    /*This class represents a player in the board of pandemic. This class consists of several actions move,
    like taking a card, moving from city to city, etc.*/
    
    class Player {
    protected:
        /*The current position in which the player is at.*/
        City currentCity;
        /*The current board in which the player is playing.*/
        Board& board;
        /*The collection of card in the player's hand.*/
        set<City> cityCards;
      

    public:
        /*Constructor.*/
        Player(Board& board, City city): board(board), currentCity(city){}
        /*Move from current city to one of it's neighbors.*/
        virtual void drive(City city);
        /*Move from current city to city that player has a card of it. Cost that city's card*/
        virtual Player &fly_direct(City city);
        /*Move from current city to any city. Cost current city's card*/
        virtual Player &fly_charter(City city);
        /*Move to any other city that has a research lab, if current city has one.*/
        virtual Player &fly_shuttle(City city);
        /*Builds a research lab in current city. Cost current city's card.*/
        virtual void build();
        /*Discovers a cure to a given color type(doesn't have to be the same as city's). Player must have a research lab in current city.
         * Cost 5 city card of the same color.
         * Note: in case cure was already found, nothing will happen.*/
        virtual void discover_cure(Color color);
        /*Lowers current city's disease level by one.
         * Note: in case cure was already found, this action will lower current city's disease level to 0.
         * Note: this action is illegal in case current city's disease level is 0. */
        virtual Player &treat(City city);
        /*Takes a given city's card to the player hand.
         * Note: each city has only one card.
         * Note: if player has this city's card, nothing will happen.*/
        Player &take_card(City city);
        /*Returns the city currently the player is at.*/
        City getCurrentCity();
        /*Returns data about the given city in a container.*/
        CityContainer& getCityContainer(City city);
        /*Return the board currently is played.*/
        Board& getBoard();
        /*Returns this player role.*/
        virtual string role() = 0;
        /*Returns player's hand size.*/
        int handSize();

    protected:
        /*Set player's current city to the given one.*/
        void setCurrentCity(City city);
        /*Removes a card from player's hand.*/
        void removeCard(City city);
        /*Returns whether the player has the given city card.*/
        bool hasCard(City city);
        /*Return whether the player has 5 card of the same given colors.*/
        bool hasNCards(Color color, int n);
    };
}


#endif //EX4_A_PLAYER_HPP
