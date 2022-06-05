#include "game.hpp"
#include <numeric>

namespace bowling
{
    int Game::score()
    {
        return std::reduce(_rolls.begin(), _rolls.end());
    }

    void Game::roll(int roll)
    {
        _rolls.push_back(roll);
    }
} // namespace bowling
