#include "game.hpp"
#include <numeric>

namespace bowling
{
    int Game::score()
    {
        auto score = 0;
        auto frame = _rolls.begin();
        do
        {
            auto frame_score = *frame + *(frame + 1);
            if (frame_score == 10)
                frame_score += *(frame + 2);
            score += frame_score;
            frame += 2;
        } while (frame != _rolls.end());
        
        return score;
    }

    void Game::roll(int roll)
    {
        _rolls.push_back(roll);
    }
} // namespace bowling
