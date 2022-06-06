#include "game.hpp"
#include <numeric>

using namespace std;

namespace bowling
{
    int Game::score()
    {
        auto score = 0;
        auto frame = _rolls.begin();
        for (int frame_index = 0; frame_index < 10; frame_index++)
        {
            score += score_frame(frame);
            frame += is_strike(frame) ? 1 : 2;
        }
        return score;
    }

    int Game::score_frame(Frame &frame)
    {
        if (is_strike(frame))
            return score_strike(frame);
        else if (is_spare(frame))
            return score_spare(frame);
        else
            return score_simple(frame);
    }

    int Game::score_simple(Frame &frame)
    {
        return *frame + *(frame + 1);
    }

    bool Game::is_spare(Frame &frame)
    {
        return *frame + *(frame + 1) == 10;
    }

    int Game::score_spare(Frame &frame)
    {
        return 10 + *(frame + 2);
    }

    bool Game::is_strike(Frame &frame)
    {
        return *frame == 10;
    }

    int Game::score_strike(Frame &frame)
    {
        return 10 + *(frame + 1) + *(frame + 2);
    }

    void Game::roll(int roll)
    {
        _rolls.push_back(roll);
    }
} // namespace bowling
