//
// Created by stycks on 04/05/2021.
//

#include "Scientist.hpp"

namespace pandemic{
     void pandemic::Scientist::discover_cure(Color color){
          CityContainer currentCityInfo = getCityContainer(getCurrentCity());
          //if a cure already discovered - do nothing
          if(currentCityInfo.hasCure()){return;}
              //if a research lab doesn't exist in this city
        if(!currentCityInfo.hasResearchLab()){
            throw "Illegal action! must have a research lab for this action!";
        }//if a research lab doesn't exist in this city
          if(!currentCityInfo.hasResearchLab()){
            throw "Illegal action! must have a research lab for this action!";
          }
          int counter = 0;//counts the number of cards that have been discarded
          bool flag = hasNCards(color, ability);//boolean to know whether player has 5 card of the given color
          if(!flag){
              string message = "Illegal action! doesn't have " + to_string(ability) +" " + getBoard().colorToEnum(color) + "card!";
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
              if(counter == ability) break;
          }
          currentCityInfo.setCured();
      }
}
