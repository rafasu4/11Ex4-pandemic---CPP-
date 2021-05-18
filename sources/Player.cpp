 #include "Player.hpp"
 #include "CityContainer.hpp"
 

 namespace pandemic{

     void pandemic::Player::removeCard(City city){
         if(hasCard(city)){
             for(auto& card : cityCards){
                 if(card == city){
                     cityCards.erase(card);
                     break;
                 }
             }
         }
     }


     bool pandemic::Player::hasCard(City city){
         if(find(cityCards.begin(), cityCards.end(),city ) != cityCards.end()){return true;}
         return false;
     }

     bool pandemic::Player::hasNCards(Color color, int n){
         int counter = 0;
         for(City card :cityCards){
             CityContainer& currentCardInfo = getCityContainer(card);
             if(currentCardInfo.getColor() == color){
                 counter++;
             }
             if(counter == n){
                 return true;
             }
         }
         return false;
     }

     int pandemic::Player::handSize(){return cityCards.size();}

     City pandemic::Player::getCurrentCity(){return currentCity;}

     CityContainer& pandemic::Player::getCityContainer(City city) {
         Board& board = getBoard();
         return board.getCityContainer(city);}

     void pandemic::Player::drive(City city){
        //    if(getCurrentCity() == city){
        //      string message = "Can't fly from city to itself!";
        //      throw message;
        //  }
          CityContainer& cityInfo = getCityContainer(currentCity);
          //if the given city isn't in current's neighbors list
          if(!cityInfo.hasConnection(city)){
              throw "Illegal action! can't fly to a non-neighbor city!";
              
          }
          this->currentCity = city;
      }

     Player& pandemic::Player::fly_direct(City city){
         if(currentCity == city){
             string message = "Can't fly from city to itself!";
             throw message;
         }
         if(!hasCard(city)){
             Board& board = getBoard();
             string message = "Doesn't have " + board.cityToString(city) + " card!";
             throw message;
         }
         removeCard(city);
         currentCity = city;
         return *this;
     }
      

      Player &pandemic::Player::fly_shuttle(City city){
           if(getCurrentCity() == city){
             string message = "Can't fly from city to itself!";
             throw message;
         }
         CityContainer src = getCityContainer(currentCity);
         CityContainer dest = getCityContainer(city);
         if(!src.hasResearchLab() || !dest.hasResearchLab()){
             string message = "One of the cities doesn't have research lab!";
             throw message;
         }
         currentCity = city;
         return *this;
         
     }

     Player& pandemic::Player::fly_charter(City city){
         if(getCurrentCity() == city){
             string message = "Can't fly from city to itself!";
             throw message;
         }
         if(!hasCard(currentCity)){
             Board& board = getBoard();
             string message = "Doesn't have " + board.cityToString(currentCity) + " card!";
             throw message;
         }
         removeCard(currentCity);
         currentCity = city;
         return *this;
         }

     Board& pandemic::Player::getBoard(){return board;}

     void pandemic::Player::build(){
         CityContainer& cityInfo = getCityContainer(currentCity);
         //if the player doesn't have current city's card
         if(!hasCard(getCurrentCity())){
             string message = "Illegal action! doesn't have" + getBoard().cityToString(getCurrentCity()) + " card!";
             throw invalid_argument(message);
         }
         //remove this city's card from player's hand
         removeCard(currentCity);
         cityInfo.buildResearchLab();
     }

      void pandemic::Player::discover_cure(Color color){
          CityContainer& currentCityInfo = getCityContainer(getCurrentCity());
            //if a research lab doesn't exist in this city
         if(!currentCityInfo.hasResearchLab()){
            throw "Illegal action! must have a research lab for this action!";
           }
          int counter = 0;//counts the number of cards that have been discarded
          bool flag = hasNCards(color, 5);//boolean to know whether player has 5 card of the given color
          if(!flag){
              string message = "Illegal action! doesn't have 5 " + getBoard().colorToEnum(color) + "card!";
              throw message;
          }
          set<City> cardsToDiscard;//will hold the 5 cards to remove
          for(City card: cityCards ){
              CityContainer& currentCard = getCityContainer(card);
              Color currentColor = currentCard.getColor();
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

     Player &pandemic::Player::treat(City city){
         if(city != currentCity){
             string message = "Illegal action!" + this->getBoard().cityToString(city) + "isn't your current city!";
             throw message;
         }
         CityContainer& cityInfo = getCityContainer(city);
         if(cityInfo.diseaseLevel == 0){
             throw "Current city is already cured!\n";
         }
         //if city has cure - use it to lower disease level to zero
         if(cityInfo.hasCure()){
             while(cityInfo.diseaseLevel > 0){
                 cityInfo.lowerDiseaseLevel();
             }
         }
         else{
             cityInfo.lowerDiseaseLevel();
         }
         return *this;
     }

     Player& pandemic::Player::take_card(City city){
             cityCards.insert(city);
         return *this;
     }

 }

