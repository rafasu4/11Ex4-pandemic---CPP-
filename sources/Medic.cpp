//
// Created by stycks on 04/05/2021.
//

#include "Medic.hpp"

namespace pandemic{

    void pandemic::Medic::drive(City city) {
        Player::drive(city);
        CityContainer& cityInfo = getCityContainer(city);
        while (cityInfo.getDiseaseLevel() > 0)
        {
            cityInfo.lowerDiseaseLevel();
        }   
    }

    Medic& pandemic::Medic::fly_direct(City city){
        Player::fly_direct(city);
        CityContainer& cityInfo = getCityContainer(city);
        while (cityInfo.getDiseaseLevel() > 0)
        {
            cityInfo.lowerDiseaseLevel();
        }   
        return *this;
    }

    Medic& pandemic::Medic::fly_shuttle(City city){
        Player::fly_shuttle(city);
        CityContainer& cityInfo = getCityContainer(city);
        while (cityInfo.getDiseaseLevel() > 0)
        {
            cityInfo.lowerDiseaseLevel();
        }   
        return *this;
    }

    Medic& pandemic::Medic::fly_charter(City city){
        Player::fly_charter(city);
        CityContainer& cityInfo = getCityContainer(city);
        while (cityInfo.getDiseaseLevel() > 0)
        {
            cityInfo.lowerDiseaseLevel();
        }   
        return *this;
    }

    Medic &pandemic::Medic::treat(City city){
       CityContainer& cityInfo = board.getCityContainer(city);
       if(cityInfo.getDiseaseLevel() == 0){
           throw "City is already cured!\n";
       }
       while (cityInfo.getDiseaseLevel() > 0)
       {
           cityInfo.lowerDiseaseLevel();
       }
       return *this;
    }

    void pandemic::Medic::medicAbility(City city){
        CityContainer& cityInfo = getCityContainer(city);
        
        if(cityInfo.hasCure()){
            while (cityInfo.getDiseaseLevel() > 0){
                cityInfo.lowerDiseaseLevel();
            }
        }
        cityInfo = getCityContainer(city);
    }
}
