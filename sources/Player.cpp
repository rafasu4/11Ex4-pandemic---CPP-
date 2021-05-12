// #include "Player.hpp"
// #include "CityContainer.hpp"

// namespace pandemic{

//     void pandemic::Player::removeCard(City city){
//         if(hasCard(city)){
//             vector<City>::iterator it = cityCards.begin();
//             //going over the cards
//             for (; it != cityCards.end(); ++it)
//                 if(*it == city){
//                     cityCards.erase(it);
//                 }
//         }
//     }


//     bool pandemic::Player::hasCard(City city){
//         if(find(cityCards.begin(), cityCards.end(),city ) != cityCards.end()){return true;}
//         return false;
//     }

//     void pandemic::Player::discard(City city){
//         if(hasCard(city)){
//             for(vector<City>::iterator it = cityCards.begin(); it != cityCards.end(); ++it){
//                 if(*it == city){
//                     cityCards.erase(it);
//                 }
//             }
//         }
//     }

//     bool pandemic::Player::hasFiveCards(Color color){
//         bool flag = false;
//         int counter = 0;
//         for(City card :cityCards){
//             CityContainer currentCardInfo = getCityContainer(card);
//             if(currentCardInfo.getColor() == color){
//                 counter++;
//             }
//             if(counter == 5){
//                 flag = true;
//                 break;}
//         }
//         return flag;
//     }

//     City pandemic::Player::getCurrentCity(){return currentCity;}

//     CityContainer pandemic::Player::getCityContainer(City city) {return this->getBoard().getCityContainer(city);}

//     //void pandemic::Player::drive(City city){
//         // CityContainer current = this->getCityContainer(city);
//         // //if the given city isn't in current's neighbors list
//         // if(!current.hasConnection(city)){
//         //     throw "Illegal action! can't fly to a non-neighbor city!";
//         // }
//         // this->currentCity = city;

//     // }

//     Player& pandemic::Player::fly_direct(City city){
//         CityContainer current = pandemic::Player::getCityContainer(city);
//         //if the player doesn't have the given city's card
//         if(!hasCard(city)){
//             string message = "Illegal action! doesn't have" + this->getBoard().cityToString(city) + "card!";
//             throw message;
//         }
//         //remove the given city's card from player's hand
//         removeCard(city);
//         this->currentCity = city;
//         return *this;
//     }

//     Player& pandemic::Player::fly_shuttle(City city){
//         CityContainer current = this->pandemic::Player::getCityContainer(city);
//         //if the player doesn't have current city's card
//         if(!hasCard(getCurrentCity())){
//             string message = "Illegal action! doesn't have" + getBoard().cityToString(getCurrentCity()) + "card!";
//             throw message;
//         }
//         //remove this city's card from player's hand
//         removeCard(getCurrentCity());
//         this->currentCity = city;
//         return *this;
//     }

//     Player &pandemic::Player::fly_charter(City city){
//         CityContainer other = this->getCityContainer(city);
//         CityContainer current = this->getCityContainer(getCurrentCity());
//         //if there isn't research lab in current city or in the given city
//         if(!current.hasResearchLab() || other.hasResearchLab()){
//             string message = "Illegal action! doesn't have research lab in";
//             if(!current.hasResearchLab()) message + getBoard().cityToString(getCurrentCity());
//             else{message + getBoard().cityToString(city);}
//             throw message;
//         }
//         this->currentCity = city;
//         return *this;
//     }

//     Board pandemic::Player::getBoard(){return board;}

//     void pandemic::Player::build(){
//         CityContainer cityData = this->getCityContainer(currentCity);
//         //if current city already has research lab - do nothing
//         if(cityData.hasResearchLab()){ return; }
//         //if the player doesn't have current city's card
//         if(!hasCard(getCurrentCity())){
//             string message = "Illegal action! doesn't have" + getBoard().cityToString(getCurrentCity()) + "card!";
//             throw message;
//         }
//         //remove this city's card from player's hand
//         removeCard(currentCity);
//         cityData.buildResearchLab();
//     }

//     // void pandemic::Player::discover_cure(Color color){
//     //     CityContainer currentCityInfo = getCityContainer(getCurrentCity());
//     //     //if a cure already discovered - do nothing
//     //     if(currentCityInfo.isCured()){return;}
//     //     int counter = 0;//counts the number of cards that have been discarded
//     //     bool flag = hasFiveCards(color);//boolean to know whether player has 5 card of the given color
//     //     if(!flag){
//     //         string message = "Illegal action! doesn't have 5 " + getBoard().colorToEnum(color) + "card!";
//     //         throw message;
//     //     }
//     //     for(vector<City>::iterator it = cityCards.begin(); it != cityCards.end(); ++it){
//     //         CityContainer temp = getCityContainer(*it);
//     //         Color currentColor = currentCityInfo.getColor();
//     //         //if there is a match
//     //         if(currentColor == color){
//     //             discard(*it);
//     //             counter++;
//     //         }
//     //         if(counter == 5) break;
//     //     }
//     //     currentCityInfo.setCured();
//     // }

//     Player &pandemic::Player::treat(City city){
//         City current = getCurrentCity();
//         if(city != current){
//             string message = "Illegal action!" + this->getBoard().cityToString(city) + "isn't your current city!";
//             throw message;
//         }
//         CityContainer currentContainer = getCityContainer(city);
//         //if city is cured and it's disease level is more that 0 - set to zero
//         if(currentContainer.isCured() && currentContainer.diseaseLevel > 0){
//             currentContainer.setDiseaseLevel(0);
//         }
//         //if city is cured and it's disease level is already 0 - an error
//         else if(currentContainer.isCured() && currentContainer.diseaseLevel == 0){
//             string message = "Illegal action!" + this->getBoard().cityToString(city) + "is already cured!";
//             throw message;
//         }
//         else{
//             currentContainer.lowerDiseaseLevel();
//         }
//         return *this;
//     }

//     Player& pandemic::Player::take_card(City city){
//         if(!hasCard(city)){
//             cityCards.push_back(city);
//         }
//         return *this;
//     }

// }

