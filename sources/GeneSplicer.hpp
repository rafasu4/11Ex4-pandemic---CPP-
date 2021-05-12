//
// Created by stycks on 04/05/2021.
//

#ifndef EX4_A_GENESPLICER_HPP
#define EX4_A_GENESPLICER_HPP
#include "Player.hpp"

namespace pandemic {
/*This class represents a specific type of a player. GeneSplicer special ability: use "discover_cure" with any cards colors combination - not just the current city's disease color.*/
    class GeneSplicer : public Player{
        Board board;
        City currentCity;
        string className;
    public:
        /*Constructor.*/
        GeneSplicer(Board board, City city): pandemic::Player(board, city), board(board), currentCity(city),
                className("GeneSplicer"){
        }
        /*Move from current city to one of it's neighbors.*/
        GeneSplicer &drive(City city);
        /*Move from current city to city that player has a card of it. Cost this city's card*/
        GeneSplicer &fly_direct(City city);
        /*Move from current city to any city. Cost current city's card*/
        void fly_shuttle(City city);
        /*Move to any other city that has a research lab, if current city has one.*/
        GeneSplicer &fly_charter(City city);
        /*Builds a research lab in current city. Cost current city's card.*/
        void build();
        /*Discovers a cure to a given color type(doesn't have to be the same as city's). Player must have a research lab in current city.
         GeneSplicer can use any cards colors combination - not just the current city's disease color.
         * Note: in case cure was already found, nothing will happen.*/
        void discover_cure(Color color);
        /*Lowers current city's disease level by one.
         * Note: in case cure was already found, this action will lower current city's disease level to 0.
         * Note: this action is illegal in case current city's disease level is 0. */
        GeneSplicer &treat(City city);

        /*Takes a given city's card to the player hand.
         * Note: each city has only one card.
         * Note: if player has this city's card, nothing will happen.*/
        GeneSplicer &take_card(City city);
    };
}
#endif //EX4_A_GENESPLICER_HPP
