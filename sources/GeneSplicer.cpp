//
// Created by stycks on 04/05/2021.
//

#include "GeneSplicer.hpp"

namespace pandemic{
    void pandemic::GeneSplicer::discover_cure(Color color){
          CityContainer currentCityInfo = getCityContainer(getCurrentCity());
          //if a cure already discovered - do nothing
          if(currentCityInfo.hasCure()){return;}
         //if a research lab doesn't exist in this city
         if(!currentCityInfo.hasResearchLab()){
            throw "Illegal action! must have a research lab for this action!";
           }
          int counter = 0;//counts the number of cards that have been discarded 
          //if player doesn't have 5 card in his hand(of any color)
          if(handSize() < 5){
              string message = "Illegal action! doesn't have 5 card!";
              throw message;
          }
          for(set<City>::iterator it = cityCards.begin(); it != cityCards.end(); ++it){
              CityContainer temp = getCityContainer(*it);
              Color currentColor = currentCityInfo.getColor();
              //if there is a match
              if(currentColor == color){
                  discard(*it);
                  counter++;
              }
              if(counter == 5) break;
          }
          currentCityInfo.setCured();
    }
}
