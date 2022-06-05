#include "../src/bowling/game.hpp"
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
    // SECTION("when a spare is made then the score is 12") {
    //     roll_times(game, 5, 2);
    //     game.roll(1);
    //     roll_times(game, 0, 17);
    //     REQUIRE(12 == game.score());
    // }
}