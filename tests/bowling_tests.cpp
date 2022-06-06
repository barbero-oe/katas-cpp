#include "../src/bowling/game.hpp"
#include <iostream>
#include <catch2/catch_test_macros.hpp>

void roll_times(bowling::Game &game, int value, int times)
{
    for (int i = 0; i < times; i++)
        game.roll(value);
}

TEST_CASE("A new bowling game", "[bowling]")
{
    bowling::Game game;

    SECTION("when no pines are tumbled then score is zero")
    {
        roll_times(game, 0, 20);
        REQUIRE(0 == game.score());
    }
    SECTION("when a single pine is always tumbled then score is 20")
    {
        roll_times(game, 1, 20);
        REQUIRE(20 == game.score());
    }
    SECTION("when two pines are always tumbled then the score is 40")
    {
        roll_times(game, 2, 20);
        REQUIRE(40 == game.score());
    }
    SECTION("when a spare is made then the score is 12") {
        roll_times(game, 5, 2);
        game.roll(1);
        roll_times(game, 0, 17);
        REQUIRE(12 == game.score());
    }
    SECTION("when a spare is made at the end then the score is 12") {
        roll_times(game, 0, 18);
        roll_times(game, 5, 2);
        game.roll(1);
        REQUIRE(11 == game.score());
    }
    SECTION("when a strike is made then the score is 14") {
        game.roll(10);
        game.roll(1);
        game.roll(1);
        roll_times(game, 0, 17);
        REQUIRE(14 == game.score());
    }
    SECTION("when a strike is made at the end then the score is 13") {
        roll_times(game, 0, 18);
        game.roll(10);
        game.roll(1);
        game.roll(1);
        REQUIRE(12 == game.score());
    }
    SECTION("when a play is made the calculation is right") {
        game.roll(1);
        game.roll(4);
        game.roll(4);
        game.roll(5);
        game.roll(6);
        game.roll(4);
        game.roll(5);
        game.roll(5);
        game.roll(10);
        game.roll(0);
        game.roll(1);
        game.roll(7);
        game.roll(3);
        game.roll(6);
        game.roll(4);
        game.roll(10);
        game.roll(2);
        game.roll(8);
        game.roll(6);
        REQUIRE(133 == game.score());
    }
    // SECTION("when a play is made the calculation is right 2") {
    //     roll_times(game, 4, 6);
    //     game.roll(10);
    //     // game.roll(5);
    //     // game.roll(10);
    //     roll_times(game, 4, 10);
    //     // roll_times(game, 0, 20 - 8);
    //     REQUIRE(24 + 10 + 4 + 4 + 44 == game.score());
    // }
}