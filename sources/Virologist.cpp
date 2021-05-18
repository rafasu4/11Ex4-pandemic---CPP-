//
// Created by stycks on 04/05/2021.
//

#include "Virologist.hpp"

namespace pandemic{
    Virologist &pandemic::Virologist::treat(City city){
        //if the given city is the current city - same as player class
        if(currentCity == city){
            Player::treat(city);
        }
        else{
            //this action cost the given city card
            if(hasCard(city)){
                City src = currentCity;
                currentCity = city;
                Player::treat(city);
                currentCity = src;
                removeCard(city);
            }
            else{
                throw "Illegal action! doesn't have " + getBoard().cityToString(city) + " card!\n";
            }
            return *this;
        }
         
         
         return *this;
    }
}