//
// Created by stycks on 04/05/2021.
// 0,
#include "Board.hpp"

namespace pandemic{
    pandemic::Board::Board(){
        world[Atlanta] =CityContainer (Blue, 0, false,Chicago,Miami,Washington);
        world[Chicago]=CityContainer(Blue, 0, SanFrancisco,LosAngeles,MexicoCity,Atlanta,Montreal);
        world[Essen]=CityContainer(Blue ,0, London,Paris,Milan,StPetersburg);
        world[London]=CityContainer(Blue, 0, NewYork,Madrid,Essen,Paris);
        world[Madrid]=CityContainer(Blue,0, London,NewYork,Paris,SaoPaulo,Algiers);
        world[Milan]=CityContainer(Blue,0, Essen,Paris,Istanbul);
        world[Montreal]=CityContainer(Blue,0, Chicago,Washington,NewYork);
        world[NewYork]=CityContainer(Blue, 0, Montreal,Washington,London,Madrid);
        world[Paris]=CityContainer(Blue,0, Algiers,Essen,Madrid,Milan,London);
        world[SanFrancisco]=CityContainer(Blue,0, LosAngeles,Chicago,Tokyo,Manila);
        world[StPetersburg]=CityContainer(Blue,0, Essen,Istanbul,Moscow);
        world[Washington]=CityContainer(Blue,0, Atlanta,NewYork,Montreal,Miami);
        //yellow cities
        world[Bogota]=CityContainer(Yellow,0, MexicoCity,Lima,Miami,SaoPaulo,BuenosAires);
        world[BuenosAires]=CityContainer(Yellow,0, Bogota,SaoPaulo);
        world[Johannesburg]=CityContainer(Yellow,0, Kinshasa,Khartoum);
        world[Khartoum]=CityContainer(Yellow,0, Lagos,Kinshasa,Johannesburg);
        world[Kinshasa]=CityContainer(Yellow,0, Lagos,Khartoum,Johannesburg);
        world[Lagos]=CityContainer(Yellow,0, SaoPaulo,Khartoum,Kinshasa);
        world[Lima]=CityContainer(Yellow,0, MexicoCity,Bogota,Santiago);
        world[LosAngeles]=CityContainer(Yellow,0, SanFrancisco,Chicago,MexicoCity,Sydney);
        world[MexicoCity]=CityContainer(Yellow,0, LosAngeles,Chicago,Miami,Lima,Bogota);
        world[Miami]=CityContainer(Yellow,0, Atlanta,MexicoCity,Washington,Bogota);
        world[Santiago]=CityContainer(Yellow,0, Lima);
        world[SaoPaulo]=CityContainer(Yellow,0, Bogota,BuenosAires,Lagos,Madrid);
        //black cities
        world[Algiers]=CityContainer(Black,0, Madrid,Paris,Istanbul,Cairo);
        world[Baghdad]=CityContainer(Black,0, Tehran,Istanbul,Cairo,Riyadh,Karachi);
        world[Cairo]=CityContainer(Black,0, Algiers,Istanbul,Baghdad,Khartoum,Riyadh);
        world[Chennai]=CityContainer(Black,0, Mumbai,Delhi,Kolkata,Bangkok,Jakarta);
        world[Delhi]=CityContainer(Black,0, Tehran,Karachi,Mumbai,Chennai,Kolkata);
        world[Istanbul]=CityContainer(Black,0, Milan,Algiers,StPetersburg,Cairo,Baghdad,Moscow);
        world[Karachi]=CityContainer(Black,0, Tehran,Baghdad,Riyadh,Mumbai,Delhi);
        world[Kolkata]=CityContainer(Black,0, Delhi,Chennai,Bangkok,HongKong);
        world[Moscow]=CityContainer(Black,0, StPetersburg,Istanbul,Tehran);
        world[Mumbai]=CityContainer(Black,0, Karachi,Delhi,Chennai);
        world[Riyadh]=CityContainer(Black,0, Baghdad,Cairo,Karachi);
        world[Tehran]=CityContainer(Black,0, Baghdad,Moscow,Karachi,Delhi);
        //red cities
        world[Bangkok]=CityContainer(Red,0, Kolkata,Chennai,Jakarta,HoChiMinhCity,HongKong);
        world[Beijing]=CityContainer(Red,0, Shanghai,Seoul);
        world[HoChiMinhCity]=CityContainer(Red,0, Jakarta,Bangkok,HongKong,Manila);
        world[HongKong]=CityContainer(Red,0, Bangkok,Kolkata,HoChiMinhCity,Shanghai,Manila,Taipei);
        world[Jakarta]=CityContainer(Red,0, Chennai,Bangkok,HoChiMinhCity,Sydney);
        world[Manila]=CityContainer(Red,0, Taipei,SanFrancisco,HoChiMinhCity,Sydney);
        world[Osaka]=CityContainer(Red,0, Taipei,Tokyo);
        world[Seoul]=CityContainer(Red,0, Beijing,Shanghai,Tokyo);
        world[Shanghai]=CityContainer(Red,0, Beijing,HongKong,Taipei,Seoul,Tokyo);
        world[Sydney]=CityContainer(Red,0, Jakarta,Manila,LosAngeles);
        world[Taipei]=CityContainer(Red,0, Shanghai,HongKong,Osaka,Manila);
        world[Tokyo]=CityContainer(Red,0, Seoul,Shanghai,Osaka,SanFrancisco);
    }

    int& pandemic::Board::operator[](City c) {
        return world[c].diseaseLevel;
    }

    const CityContainer pandemic::Board::getCityContainer(City city){
        return this->world.at(city);
    }

    bool pandemic::Board::is_clean(){
        for(auto  &pair: world){
            CityContainer cc = pair.second;
            if(cc.getDiseaseLevel() != 0){
               return false;
            }
        }
        return true;
    }

    ostream &operator<<(ostream &os, const Board &b){
        for(auto& pair: b.world){
            os << b.cityToString(pair.first) << endl;
        }
        return os;
    }

    std::string pandemic::Board::cityToString(const City c) const{
        if(c == Atlanta) return "Atlanta";
        if(c == Chicago) return "Chicago";
        if(c == Essen) return "Essen";
        if(c == London) return "London";
        if(c == Madrid) return "Madrid";
        if(c == Milan) return "Milan";
        if(c == Montreal) return "Montreal";
        if(c == NewYork) return "NewYork";
        if(c == Paris) return "Paris";
        if(c == SanFrancisco) return "SanFrancisco";
        if(c == StPetersburg) return "StPetersburg";
        if(c == Washington) return "Washington";
        if(c == Bangkok) return "Bangkok";
        if(c == Beijing) return "Beijing";
        if(c == HoChiMinhCity) return "HoChiMinhCity";
        if(c == HongKong) return "HongKong";
        if(c == Jakarta) return "Jakarta";
        if(c == Manila) return "Manila";
        if(c == Osaka) return "Osaka";
        if(c == Seoul) return "Seoul";
        if(c == Shanghai) return "Shanghai";
        if(c == Sydney) return "Sydney";
        if(c == Taipei) return "Taipei";
        if(c == Tokyo) return "Tokyo";
        if(c == Algiers) return "Algiers";
        if(c == Baghdad) return "Baghdad";
        if(c == Cairo) return "Cairo";
        if(c == Chennai) return "Chennai";
        if(c == Delhi) return "Delhi";
        if(c == Istanbul) return "Istanbul";
        if(c == Karachi) return "Karachi";
        if(c == Kolkata) return "Kolkata";
        if(c == Moscow) return "Moscow";
        if(c == Mumbai) return "Mumbai";
        if(c == Riyadh) return "Riyadh";
        if(c == Tehran) return "Tehran";
        if(c == Bogota) return "Bogota";
        if(c == BuenosAires) return "BuenosAires";
        if(c == Johannesburg) return "Johannesburg";
        if(c == Khartoum) return "Khartoum";
        if(c == Kinshasa) return "Kinshasa";
        if(c == Lagos) return "Lagos";
        if(c == Lima) return "Lima";
        if(c == LosAngeles) return "LosAngeles";
        if(c == MexicoCity) return "MexicoCity";
        if(c == Miami) return "Miami";
        if(c == Santiago) return "Santiago";
        if(c == SaoPaulo) return "SaoPaulo";
        return "Fail";
    }

    std::string pandemic::Board::colorToEnum(const Color color) const{
        if(color == Blue) return "Blue";
        if(color == Red) return "Red";
        if(color == Black) return "Black";
        if(color == Yellow) return "Yellow";
        return "Fail";
    }


}