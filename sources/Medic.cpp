//
// Created by stycks on 04/05/2021.
//

#include "Medic.hpp"

namespace pandemic{

    void pandemic::Medic::drive(City city) {
        Player::drive(city);
        CityContainer current = getCityContainer(city);
        medicAbility(current);
    }

    Medic& pandemic::Medic::fly_direct(City city){
        Player::fly_direct(city);
        CityContainer current = getCityContainer(city);
        medicAbility(current);
        return *this;
    }

    Medic& pandemic::Medic::fly_shuttle(City city){
        Player::fly_shuttle(city);
        CityContainer current = getCityContainer(city);
        medicAbility(current);
        return *this;
    }

    Medic& pandemic::Medic::fly_charter(City city){
        Player::fly_charter(city);
        CityContainer current = getCityContainer(city);
        medicAbility(current);
        return *this;
    }

    Medic &pandemic::Medic::treat(City city){
        CityContainer current = getCityContainer(city);
       medicAbility(current);
       return *this;
    }

    void pandemic::Medic::medicAbility(CityContainer current){
        if(current.hasCure()){
            while (current.getDiseaseLevel() > 0){
                current.lowerDiseaseLevel();
            }
        }
    }
}
