//
// Created by stycks on 04/05/2021.
//

#ifndef EX4_A_CITYCONTAINER_HPP
#define EX4_A_CITYCONTAINER_HPP
#include "Color.hpp"
#include "Board.hpp"
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

namespace pandemic{
    /*This class collects info on a specific city in the board.*/

    class CityContainer {
        /*This city color.*/
        Color color;
        /*Holds all of this city's neighbors.*/
        vector<City> connections;
        /*This city disease Level.*/
        int diseaseLevel;
        /*This city research Lab.*/
        bool researchLab;
        /*Has a cured been found.*/
        bool cureFounded;

    public:
        /*Default constructor.*/
        CityContainer(){}

        /*Constructor.*/
        CityContainer(Color color, int diseaseLevel, City nei1, City nei2, City nei3, City nei4,
                      City nei5, City nei6) : color(color), diseaseLevel(0), researchLab(false), cureFounded(false){
            if (nei1 != City::emptyCity) addConnection(nei1);
            if (nei2 != City::emptyCity) addConnection(nei2);
            if (nei3 != City::emptyCity) addConnection(nei3);
            if (nei4 != City::emptyCity) addConnection(nei4);
            if (nei5 != City::emptyCity) addConnection(nei5);
            if (nei6 != City::emptyCity) addConnection(nei6);
        }

        /*Returns whether this city is a neighbor or not.*/
        bool hasConnection(City city){
            for(auto neighbor: connections){
                if(neighbor == city){
                    return true;
                }
            }
            return false;
         }
         /*Returns this city color.*/
         Color getColor(){return color;}
         /*Returns whether the given city has a research lab or not.*/
         bool& hasResearchLab(){
             return researchLab;}
        /*Builds research lab.*/
        void buildResearchLab(){researchLab = true;}
        /*Returns this city disease level.*/
        int getDiseaseLevel(){return diseaseLevel;}
        /*Lowers disease level by one. If is already zero, exception will be thrown.*/
        void lowerDiseaseLevel(){
            if(diseaseLevel == 0) { throw "Can't be below zero!";}
            diseaseLevel--;
        }
        /*Returns whether the city is cured or not.*/
        bool hasCure(){return cureFounded;}


    private:
        /*Set this city disease level at the start of the game.*/
        void setDiseaseLevel(int level){diseaseLevel = level;}
        /*Connects between two neighbors.*/
        void addConnection(City& neighbor){connections.push_back(neighbor);}
        /*Set this city as cured.*/
        void setCured(){ cureFounded = true;}
        /*Removes research lab from the city - used for QA.*/
        void removeResearchLab(){researchLab = false;}
    
    friend class Board;
    friend class Player;
    friend class Scientist;
    friend class Researcher;
    friend class GeneSplicer;
    };
}
#endif //EX4_A_CITYCONTAINER_HPP
