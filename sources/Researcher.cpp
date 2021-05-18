//
// Created by stycks on 04/05/2021.
//

#include "Researcher.hpp"

namespace pandemic{
    void pandemic::Researcher::discover_cure(Color color){
          CityContainer& currentCityInfo = getCityContainer(getCurrentCity());
          int counter = 0;//counts the number of cards that have been discarded
          bool flag = hasNCards(color, 5);//boolean to know whether player has 5 card of the given color
          if(!flag){
              string message = "Illegal action! doesn't have 5 " + getBoard().colorToEnum(color) + "card!";
              throw message;
          }
          set<City> cardsToDiscard;//will hold the 5 cards to remove
          for(City card: cityCards){
              CityContainer& temp = getCityContainer(card);
              Color currentColor = currentCityInfo.getColor();
              //if there is a match
              if(currentColor == color){
                  cardsToDiscard.insert(card);
                  counter++;
              }
              if(counter == 5) break;
          }
          for(City card : cardsToDiscard){
              removeCard(card);
          }
          currentCityInfo.setCured();
      }
}
