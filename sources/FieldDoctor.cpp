//
// Created by stycks on 04/05/2021.
//

#include "FieldDoctor.hpp"

namespace pandemic{
    FieldDoctor &pandemic::FieldDoctor::treat(City city){
        //if the given city is current city - same action as player
        if(currentCity == city){
            Player::treat(city);
        }
        else{
            CityContainer& cityInfo = getCityContainer(currentCity);
            //if the given city isn't one of current city's neighbors - illegal action
            if (!cityInfo.hasConnection(city)){
                string message = "Illegal action! " + getBoard().cityToString(city) + " isn't current city or one of its neighbors!\n";
                throw message;
            }
            if(hasCard(currentCity)){
                City src = currentCity;
                fly_charter(city);//fly to the given city
                Player::treat(city);
                take_card(src);
                fly_direct(src);//fly to the original src city
                take_card(src);//return the card to player's hand
            }
            else{
                City src = currentCity;
                take_card(src);
                fly_charter(city);//fly to the given city
                Player::treat(city);
                take_card(src);
                fly_direct(src);//fly to the original src city
            }
        }
        return *this;
    }
}