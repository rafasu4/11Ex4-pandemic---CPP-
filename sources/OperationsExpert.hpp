//
// Created by stycks on 04/05/2021.
//

#ifndef EX4_A_OPERATIONSEXPERT_HPP
#define EX4_A_OPERATIONSEXPERT_HPP

#include "Player.hpp"
#include "Board.hpp"

namespace pandemic {

/*This class represents a specific type of a player. OperationsExpert special ability: use "Build" without card cost.*/
    class OperationsExpert : public Player {
        Board board;
        City currentCity;
        string className;
    public:
        /*Constructor.*/
        OperationsExpert(Board board, City city): pandemic::Player(board, city), board(board), currentCity(city),
        className("OperationsExpert"){}
        /*Move from current city to one of it's neighbors.*/
        OperationsExpert &drive(City city) noexcept(false){
            CityContainer current = this->getCityContainer(city);
//            //if the given city isn't in current's neighbors list
//            if(!current.hasConnection(city)){
//                throw "Illegal action! can't fly to a non-neighbor city!";
//            }
//            this->currentCity = city;
            return *this;}
        CityContainer getCityContainer(City city) {return board.world[city];}

        /*Move from current city to city that player has a card of it. Cost this city's card*/
        OperationsExpert &fly_direct(City city){return *this;}
        /*Move from current city to any city. Cost current city's card*/
        void fly_shuttle(City city){}
        /*Move to any other city that has a research lab, if current city has one.*/
        OperationsExpert &fly_charter(City city){return *this;}
        /*Builds a research lab in current city.*/
        void build(){}
        /*Discovers a cure to a given color type(doesn't have to be the same as city's). Player must have a research lab in current city.
         * Cost 5 city card of the same color.
         * Note: in case cure was already found, nothing will happen.*/
        void discover_cure(Color color){}
        /*Lowers current city's disease level by one.
         * Note: in case cure was already found, this action will lower current city's disease level to 0.
         * Note: this action is illegal in case current city's disease level is 0. */
        OperationsExpert &treat(City city){return *this;}
        /*Returns this player role.*/
        string role(){
            return className;
        }

        /*Takes a given city's card to the player hand.
         * Note: each city has only one card.
         * Note: if player has this city's card, nothing will happen.*/
        OperationsExpert &take_card(City city){return *this;}
    };
}

#endif //EX4_A_OPERATIONSEXPERT_HPP
