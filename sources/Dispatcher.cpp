//
// Created by stycks on 04/05/2021.
//

#include "Dispatcher.hpp"

namespace pandemic{
    Dispatcher &pandemic::Dispatcher::fly_direct(City city){
        //if the destination same as current city - an error
           if(currentCity == city){
             string message = "Can't fly from city to itself!";
             throw message;
         }
        CityContainer& cityInfo = getCityContainer(currentCity);
        //if has a research lab - fly for free
        if(cityInfo.hasResearchLab()){
            currentCity = city;
        }
        else{
            Player::fly_direct(city);
        }
        return *this;
    }
}
