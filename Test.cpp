//
// Created by stycks on 05/05/2021.
//
#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "OperationsExpert.hpp"

using namespace pandemic;

TEST_CASE("Basic Board methods"){
    Board board;
    CHECK(board.is_clean());//board should be clean at first
    board[Atlanta] = 3;
    board[Washington] = 5;
    CityContainer c =board.getCityContainer(Atlanta);
    CHECK(c.getDiseaseLevel() == 3);
    c =board.getCityContainer(Washington);
    CHECK(c.getDiseaseLevel() == 5);
}

TEST_CASE("Basic Player methods"){
    Board board;
    OperationsExpert player(board, Atlanta);
    CHECK_EQ(player.getCurrentCity(), City::Atlanta);
    CHECK_NOTHROW(player.drive(Washington));//drive to a neighbor
    CHECK_EQ(player.getCurrentCity(), City::Washington);
    CHECK_THROWS(player.fly_charter(Cairo));
    CHECK_NOTHROW(player.take_card(Cairo));
    CHECK_NOTHROW(player.fly_direct(Cairo));
    player.take_card(Cairo);
    player.build();
    player.take_card(Cairo);
    CHECK_NOTHROW(player.fly_charter(Chicago));
    CHECK_THROWS(player.build());
    player.take_card(Chicago);
    CHECK_NOTHROW(player.build());
    CHECK_NOTHROW(player.fly_charter(Cairo));
    player.take_card(Chicago);
    player.fly_direct(Chicago);
    player.take_card(Atlanta);
    player.take_card(Chicago);
    player.take_card(Essen);
    player.take_card(London);
    player.take_card(Madrid);
    CHECK_THROWS(player.discover_cure(Red));
    CHECK_NOTHROW(player.discover_cure(Blue));
    CHECK_NOTHROW(player.treat(Chicago));
    CHECK_THROWS(player.treat(Chicago));
    CHECK_THROWS(player.fly_shuttle(London));
    CHECK_THROWS(player.fly_shuttle(London));
    player.take_card(London);
    CHECK_NOTHROW(player.fly_direct(London));
    CHECK_EQ(player.role(), "OperationsExpert" );

}
