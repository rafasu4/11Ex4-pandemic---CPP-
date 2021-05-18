//
// Created by stycks on 04/05/2021.
//

#ifndef EX4_A_MEDIC_HPP
#define EX4_A_MEDIC_HPP
#include "Player.hpp"

namespace pandemic {

    class Medic: public Player {
        string className;
    public:
        /*Constructor.*/
        Medic(Board& board, City city): pandemic::Player(board, city),className("Medic"){}
        /*Move from current city to one of it's neighbors.
         * Note: if cure has founded in the city, disease level will automatic lower to zero.*/
        void drive(City city) override;
        /*Move from current city to city that player has a card of it. Cost this city's card.
         * Note: if cure has founded in the city, disease level will automatic lower to zero.*/
        Medic &fly_direct(City city) override;
        /*Move from current city to any city. Cost current city's card.
         * Note: if cure has founded in the city, disease level will automatic lower to zero.*/
        Medic &fly_shuttle(City city) override;
        /*Move to any other city that has a research lab, if current city has one.
         * Note: if cure has founded in the city, disease level will automatic lower to zero.*/
        Medic &fly_charter(City city) override;
        /*Lowers current city's disease level to zero.
         * Note: in case cure was already found, this action will lower current city's disease level to 0.
         * Note: this action is illegal in case current city's disease level is 0. */
        Medic &treat(City city) override;
        /*Returns this player role.*/
        string role() override{return className;}
        
    private:
        /*If cure has found int the destination city - lower disease level to zero.*/
        void medicAbility(City city);
    };
}

#endif //EX4_A_MEDIC_HPP
