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
        Dispatcher(Board board, City city): pandemic::Player(board, city), className("Dispatcher"){}
        /*Move from current city to city that player has a card of it without the Cost of this city's card.*/
        Dispatcher &fly_direct(City city) override;
        /*Returns this player role.*/
        string role(){return className;}
    };
}


#endif //EX4_A_DISPATCHER_HPP
