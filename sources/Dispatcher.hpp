//
// Created by stycks on 04/05/2021.
//

#ifndef EX4_A_DISPATCHER_HPP
#define EX4_A_DISPATCHER_HPP
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {
/*This class represents a specific type of a player. Dispatcher special ability: if current city has research lab, use "fly_direct" with no cost.*/
    class Dispatcher : public Player {
        Board board;
        City currentCity;
        string className;
    public:
        /*Constructor.*/
        Dispatcher(Board board, City city): pandemic::Player(board, city), board(board), currentCity(city),
                className("Dispatcher"){
        }
        /*Move from current city to one of it's neighbors.*/
        Dispatcher &drive(City city){return *this;}
        /*Move from current city to city that player has a card of it. Cost this city's card. If current city has research lab, cost nothing.*/
        Dispatcher &fly_direct(City city){return *this;}
        /*Move from current city to any city. Cost current city's card*/
        void fly_shuttle(City city){}
        /*Move to any other city that has a research lab, if current city has one.*/
        Dispatcher &fly_charter(City city){return *this;}
        /*Builds a research lab in current city. Cost current city's card.*/
        void build(){}
        /*Discovers a cure to a given color type(doesn't have to be the same as city's). Player must have a research lab in current city.
         * Cost 5 city card of the same color.
         * Note: in case cure was already found, nothing will happen.*/
        void discover_cure(Color color){}
        /*Lowers current city's disease level by one.
         * Note: in case cure was already found, this action will lower current city's disease level to 0.
         * Note: this action is illegal in case current city's disease level is 0. */
        Dispatcher &treat(City city){return *this;}

        /*Takes a given city's card to the player hand.
         * Note: each city has only one card.
         * Note: if player has this city's card, nothing will happen.*/
        Dispatcher &take_card(City city){return *this;}
    };
}


#endif //EX4_A_DISPATCHER_HPP
