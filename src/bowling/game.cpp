#include "game.hpp"

namespace bowling
{
    int Game::score()
    {
        return _score;
    }

    void Game::roll(int roll)
    {
        _score += roll;
    }
} // namespace bowling
