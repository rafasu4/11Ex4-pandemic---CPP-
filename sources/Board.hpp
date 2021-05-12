//
// Created by stycks on 04/05/2021.
//

#ifndef EX4_A_BOARD_HPP
#define EX4_A_BOARD_HPP

#include <iostream>
#include "City.hpp"
#include "map"
#include <vector>
#include "CityContainer.hpp"


namespace pandemic{
    
    
    class Board {
    public:
        /*Holds all the cities in the game as a value, and all of the data of that city(like color, disease level,
        etc) as its value in a container.*/
        std::map<City,CityContainer> world;
        
        
        /*Constructor.*/
        Board();
        /*Returns true if all of the cities in the board are "clean" - disease level is 0.*/
        bool is_clean();
        /*Removes all of the cures that founded so far - used for QA.*/
        void remove_cures(){}
        /*Returns the data about the given city in a container.*/
        const CityContainer getCityContainer(City city);
        /*Updates city disease level.*/
        int &operator[](City c);
        /*Overloads outstream operator.*/
        friend ostream &operator<<(ostream &os, const Board &b);
        /*Returns City enum as a string.*/
        std::string cityToString(const City c) const;
        /*Returns Color enum as a string.*/
        std::string colorToEnum(const Color color) const;
    };
}



#endif //EX4_A_BOARD_HPP
