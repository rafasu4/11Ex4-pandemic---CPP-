//
// Created by stycks on 04/05/2021.
//

#include "OperationsExpert.hpp"

namespace pandemic{
    void pandemic::OperationsExpert::build(){
        //if has this city's card - return it to the player's hand after build action
        if(hasCard(currentCity)){
            Player::build();
            take_card(currentCity);
            return;
        }
        take_card(currentCity);//take a card for build action
        Player::build();
    }
}
