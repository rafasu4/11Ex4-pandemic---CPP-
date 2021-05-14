//
// Created by stycks on 04/05/2021.
//

#include "Researcher.hpp"

namespace pandemic{
    void pandemic::Researcher::discover_cure(Color color){
          CityContainer currentCityInfo = getCityContainer(getCurrentCity());
          //if a cure already discovered - do nothing
          if(currentCityInfo.hasCure()){return;}
          int counter = 0;//counts the number of cards that have been discarded
          bool flag = hasNCards(color, 5);//boolean to know whether player has 5 card of the given color
          if(!flag){
              string message = "Illegal action! doesn't have 5 " + getBoard().colorToEnum(color) + "card!";
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
