//
// Created by stycks on 04/05/2021.
//

#ifndef EX4_A_FIELDDOCTOR_HPP
#define EX4_A_FIELDDOCTOR_HPP

#include "Player.hpp"

namespace pandemic {
/*This class represents a specific type of a player. FieldDoctor special ability: use "treat" not just in the current city, but also in it's neighbors (without throwing city's card).*/
    class FieldDoctor : public Player{
        Board board;
        City currentCity;
        string className;
    public:
        /*Constructor.*/
        FieldDoctor(Board board, City city): pandemic::Player(board, city), board(board), currentCity(city),
                className("FieldDoctor"){
        }
        /*Move from current city to one of it's neighbors.*/
        FieldDoctor &drive(City city){return *this;}
        /*Move from current city to city that player has a card of it. Cost this city's card*/
        FieldDoctor &fly_direct(City city){return *this;}
        /*Move from current city to any city. Cost current city's card*/
        void fly_shuttle(City city){}
        /*Move to any other city that has a research lab, if current city has one.*/
        FieldDoctor &fly_charter(City city){return *this;}
        /*Builds a research lab in current city.*/
        void build(){}
        /*Discovers a cure to a given color type(doesn't have to be the same as city's). Player must have a research lab in current city.
         * Cost 5 city card of the same color.
         * Note: in case cure was already found, nothing will happen.*/
        void discover_cure(Color color);
        /*Lowers current city's disease level by one.
         * Note: in case cure was already found, this action will lower current city's disease level to 0.
         * Note: this action is illegal in case current city's disease level is 0. */
        FieldDoctor &treat(City city){return *this;}
        string role(){return className;}
        /*Takes a given city's card to the player hand.
         * Note: each city has only one card.
         * Note: if player has this city's card, nothing will happen.*/
        FieldDoctor &take_card(City city){return *this;}
    };
}

#endif //EX4_A_FIELDDOCTOR_HPP
