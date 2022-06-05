#include "game.hpp"
#include <numeric>

namespace bowling
{
    int Game::score()
    {
        auto score = 0;
        for (int frame = 0; frame < 10; frame++)
        {
            score += frame_score(frame);
        }
        return score;
    }

    int Game::frame_score(int frame)
    {
        auto base_index = frame * 2;
        auto first = _rolls[base_index];
        auto second = _rolls[base_index + 1];

        auto score = first + second;
        if (score == 10)
            score += _rolls[base_index + 2];
        return score;
    }

    void Game::roll(int roll)
    {
        _rolls.push_back(roll);
    }
} // namespace bowling
