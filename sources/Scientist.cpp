//
// Created by stycks on 04/05/2021.
//

#include "Scientist.hpp"

namespace pandemic{
     void pandemic::Scientist::discover_cure(Color color){
        CityContainer cityInfo = getCityContainer(currentCity);
        if(!cityInfo.hasResearchLab()){
            throw "No research lab in current city!\n";
        }
        //if hand size is lower than the special abillity number - illegal action
        if(cityCards.size() < ability){
            throw "Not enough cards!";     
        }
       int counter = 0;
       set<City> cardsToRemove;//will hold all the cards to remove
       //collecting all cards to remove
       for(City card : cityCards){
           CityContainer currentCardInfo = getCityContainer(card);
           if(currentCardInfo.getColor() == color){
               cardsToRemove.insert(card);
               if(++counter == ability){
                   break;
               }
           }
       }
       if(counter != ability){
           throw "Not enough cards!";
       }
       //remove the cards
       for(City card : cardsToRemove){
           removeCard(card);
       }
      }
}
