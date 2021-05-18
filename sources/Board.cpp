//
// Created by stycks on 04/05/2021.
// 0,
#include "Board.hpp"

namespace pandemic{
    pandemic::Board::Board(){
        //setting map
        world[City::Atlanta] =CityContainer (Color::Blue, 0,City::Chicago,City::Miami,City::Washington, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::Chicago]=CityContainer(Color::Blue, 0, City::SanFrancisco,City::LosAngeles,City::MexicoCity,City::Atlanta,City::Montreal, City::emptyCity);
        world[City::Essen]=CityContainer(Color::Blue ,0, City::London, City::Paris, City::Milan, City::StPetersburg, City::emptyCity, City::emptyCity);
        world[City::London]=CityContainer(Color::Blue, 0, City::NewYork,City::Madrid,City::Essen,City::Paris, City::emptyCity, City::emptyCity);
        world[City::Madrid]=CityContainer(Color::Blue,0, City::London,City::NewYork,City::Paris,City::SaoPaulo,City::Algiers, City::emptyCity);
        world[City::Milan]=CityContainer(Color::Blue,0, City::Essen,City::Paris,City::Istanbul, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::Montreal]=CityContainer(Color::Blue,0, City::Chicago,City::Washington,City::NewYork, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::NewYork]=CityContainer(Color::Blue, 0, City::Montreal,City::Washington,City::London,City::Madrid, City::emptyCity, City::emptyCity);
        world[City::Paris]=CityContainer(Color::Blue,0, City::Algiers,City::Essen,City::Madrid,City::Milan,City::London, City::emptyCity);
        world[City::SanFrancisco]=CityContainer(Color::Blue,0, City::LosAngeles,City::Chicago,City::Tokyo,City::Manila, City::emptyCity, City::emptyCity);
        world[City::StPetersburg]=CityContainer(Color::Blue,0, City::Essen,City::Istanbul,City::Moscow, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::Washington]=CityContainer(Color::Blue,0, City::Atlanta,City::NewYork,City::Montreal,City::Miami, City::emptyCity, City::emptyCity);
        //Color::yellow cities
        world[City::Bogota]=CityContainer(Color::Yellow,0, City::MexicoCity,City::Lima,City::Miami,City::SaoPaulo,City::BuenosAires, City::emptyCity);
        world[City::BuenosAires]=CityContainer(Color::Yellow,0, City::Bogota,City::SaoPaulo, City::emptyCity, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::Johannesburg]=CityContainer(Color::Yellow,0, City::Kinshasa,City::Khartoum, City::emptyCity, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::Khartoum]=CityContainer(Color::Yellow,0, City::Lagos,City::Kinshasa,City::Johannesburg, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::Kinshasa]=CityContainer(Color::Yellow,0, City::Lagos,City::Khartoum,City::Johannesburg, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::Lagos]=CityContainer(Color::Yellow,0, City::SaoPaulo,City::Khartoum,City::Kinshasa, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::Lima]=CityContainer(Color::Yellow,0, City::MexicoCity,City::Bogota,City::Santiago, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::LosAngeles]=CityContainer(Color::Yellow,0, City::SanFrancisco,City::Chicago,City::MexicoCity,City::Sydney, City::emptyCity, City::emptyCity);
        world[City::MexicoCity]=CityContainer(Color::Yellow,0, City::LosAngeles,City::Chicago,City::Miami,City::Lima,City::Bogota, City::emptyCity);
        world[City::Miami]=CityContainer(Color::Yellow,0, City::Atlanta,City::MexicoCity,City::Washington,City::Bogota, City::emptyCity, City::emptyCity);
        world[City::Santiago]=CityContainer(Color::Yellow,0, City::Lima, City::emptyCity, City::emptyCity, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::SaoPaulo]=CityContainer(Color::Yellow,0, City::Bogota,City::BuenosAires,City::Lagos,City::Madrid, City::emptyCity, City::emptyCity);
        //Color::black cities
        world[City::Algiers]=CityContainer(Color::Black,0, City::Madrid,City::Paris,City::Istanbul,City::Cairo, City::emptyCity, City::emptyCity);
        world[City::Baghdad]=CityContainer(Color::Black,0, City::Tehran,City::Istanbul,City::Cairo,City::Riyadh,City::Karachi, City::emptyCity);
        world[City::Cairo]=CityContainer(Color::Black,0, City::Algiers,City::Istanbul,City::Baghdad,City::Khartoum,City::Riyadh, City::emptyCity);
        world[City::Chennai]=CityContainer(Color::Black,0, City::Mumbai,City::Delhi,City::Kolkata,City::Bangkok,City::Jakarta, City::emptyCity);
        world[City::Delhi]=CityContainer(Color::Black,0, City::Tehran,City::Karachi,City::Mumbai,City::Chennai,City::Kolkata, City::emptyCity);
        world[City::Istanbul]=CityContainer(Color::Black,0, City::Milan,City::Algiers,City::StPetersburg,City::Cairo,City::Baghdad,City::Moscow);
        world[City::Karachi]=CityContainer(Color::Black,0, City::Tehran,City::Baghdad,City::Riyadh,City::Mumbai,City::Delhi, City::emptyCity);
        world[City::Kolkata]=CityContainer(Color::Black,0, City::Delhi,City::Chennai,City::Bangkok,City::HongKong, City::emptyCity, City::emptyCity);
        world[City::Moscow]=CityContainer(Color::Black,0, City::StPetersburg,City::Istanbul,City::Tehran, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::Mumbai]=CityContainer(Color::Black,0, City::Karachi,City::Delhi,City::Chennai, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::Riyadh]=CityContainer(Color::Black,0, City::Baghdad,City::Cairo,City::Karachi, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::Tehran]=CityContainer(Color::Black,0, City::Baghdad,City::Moscow,City::Karachi,City::Delhi, City::emptyCity, City::emptyCity);
        //Color::red cities
        world[City::Bangkok]=CityContainer(Color::Red,0, City::Kolkata,City::Chennai,City::Jakarta,City::HoChiMinhCity,City::HongKong, City::emptyCity);
        world[City::Beijing]=CityContainer(Color::Red,0, City::Shanghai,City::Seoul, City::emptyCity, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::HoChiMinhCity]=CityContainer(Color::Red,0, City::Jakarta,City::Bangkok,City::HongKong,City::Manila, City::emptyCity, City::emptyCity);
        world[City::HongKong]=CityContainer(Color::Red,0, City::Bangkok,City::Kolkata,City::HoChiMinhCity,City::Shanghai,City::Manila,City::Taipei);
        world[City::Jakarta]=CityContainer(Color::Red,0, City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney, City::emptyCity, City::emptyCity);
        world[City::Manila]=CityContainer(Color::Red,0, City::Taipei,City::SanFrancisco,City::HoChiMinhCity,City::Sydney, City::HongKong, City::emptyCity);
        world[City::Osaka]=CityContainer(Color::Red,0, City::Taipei,City::Tokyo, City::emptyCity, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::Seoul]=CityContainer(Color::Red,0, City::Beijing,City::Shanghai,City::Tokyo, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::Shanghai]=CityContainer(Color::Red,0, City::Beijing,City::HongKong,City::Taipei,City::Seoul,City::Tokyo, City::emptyCity);
        world[City::Sydney]=CityContainer(Color::Red,0, City::Jakarta,City::Manila,City::LosAngeles, City::emptyCity, City::emptyCity, City::emptyCity);
        world[City::Taipei]=CityContainer(Color::Red,0, City::Shanghai,City::HongKong,City::Osaka,City::Manila, City::emptyCity, City::emptyCity);
        world[City::Tokyo]=CityContainer(Color::Red,0, City::Seoul,City::Shanghai,City::Osaka,City::SanFrancisco, City::emptyCity, City::emptyCity);
    }

    int& pandemic::Board::operator[](City c) {
        return world[c].diseaseLevel;
    }

    CityContainer& pandemic::Board::getCityContainer(City city){
        return world[city];
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
    
    void pandemic::Board::remove_cures(){
        //for each city in the map
        for(auto& pair: world){
            CityContainer currentCity = pair.second;
            currentCity.removeResearchLab();
        }
    }

    ostream &operator<<(ostream &os, const Board &b){
        for(auto& pair: b.world){
            os << b.cityToString(pair.first) << endl;
        }
        return os;
    }

    std::string pandemic::Board::cityToString(const City c) const{
        if(c == City::Atlanta) return "City::Atlanta";
        if(c == City::Chicago) return "City::Chicago";
        if(c == City::Essen) return "City::Essen";
        if(c == City::London) return "City::London";
        if(c == City::Madrid) return "City::Madrid";
        if(c == City::Milan) return "City::Milan";
        if(c == City::Montreal) return "City::Montreal";
        if(c == City::NewYork) return "City::NewYork";
        if(c == City::Paris) return "City::Paris";
        if(c == City::SanFrancisco) return "City::SanFrancisco";
        if(c == City::StPetersburg) return "City::StPetersburg";
        if(c == City::Washington) return "City::Washington";
        if(c == City::Bangkok) return "City::Bangkok";
        if(c == City::Beijing) return "City::Beijing";
        if(c == City::HoChiMinhCity) return "City::HoChiMinhCity";
        if(c == City::HongKong) return "City::HongKong";
        if(c == City::Jakarta) return "City::Jakarta";
        if(c == City::Manila) return "City::Manila";
        if(c == City::Osaka) return "City::Osaka";
        if(c == City::Seoul) return "City::Seoul";
        if(c == City::Shanghai) return "City::Shanghai";
        if(c == City::Sydney) return "City::Sydney";
        if(c == City::Taipei) return "City::Taipei";
        if(c == City::Tokyo) return "City::Tokyo";
        if(c == City::Algiers) return "City::Algiers";
        if(c == City::Baghdad) return "City::Baghdad";
        if(c == City::Cairo) return "City::Cairo";
        if(c == City::Chennai) return "City::Chennai";
        if(c == City::Delhi) return "City::Delhi";
        if(c == City::Istanbul) return "City::Istanbul";
        if(c == City::Karachi) return "City::Karachi";
        if(c == City::Kolkata) return "City::Kolkata";
        if(c == City::Moscow) return "City::Moscow";
        if(c == City::Mumbai) return "City::Mumbai";
        if(c == City::Riyadh) return "City::Riyadh";
        if(c == City::Tehran) return "City::Tehran";
        if(c == City::Bogota) return "City::Bogota";
        if(c == City::BuenosAires) return "City::BuenosAires";
        if(c == City::Johannesburg) return "City::Johannesburg";
        if(c == City::Khartoum) return "City::Khartoum";
        if(c == City::Kinshasa) return "City::Kinshasa";
        if(c == City::Lagos) return "City::Lagos";
        if(c == City::Lima) return "City::Lima";
        if(c == City::LosAngeles) return "City::LosAngeles";
        if(c == City::MexicoCity) return "City::MexicoCity";
        if(c == City::Miami) return "City::Miami";
        if(c == City::Santiago) return "City::Santiago";
        if(c == City::SaoPaulo) return "City::SaoPaulo";
        return "Fail";
    }

    std::string pandemic::Board::colorToEnum(const Color color) const{
        if(color == Color::Blue) return "Color::Blue";
        if(color == Color::Red) return "Color::Red";
        if(color == Color::Black) return "Color::Black";
        if(color == Color::Yellow) return "Color::Yellow";
        return "Fail";
    }


}