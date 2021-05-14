//
// Created by stycks on 04/05/2021.
//

#include "Dispatcher.hpp"

namespace pandemic{
    Dispatcher &pandemic::Dispatcher::fly_direct(City city){
        City src = currentCity;
        //if has this current city's card - return it to the player's hand after fly_direct action
        if(hasCard(src)){
            Player::fly_direct(city);
            take_card(src);
            return *this;
        }
        take_card(src);//take a card for build action
        Player::fly_direct(city);
        return *this;
    }
}
