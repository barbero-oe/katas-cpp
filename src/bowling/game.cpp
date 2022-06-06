#include "game.hpp"
#include <numeric>

using namespace std;

namespace bowling
{
    int Game::score()
    {
        auto score = 0;
        auto frame_cursor = _rolls.begin();
        for (int frame = 0; frame < 10; frame++)
        {
            if (is_strike(frame_cursor))
            {
                score += score_strike(frame_cursor);
                frame_cursor += 1;
            }
            else if (is_spare(frame_cursor))
            {
                score += score_spare(frame_cursor);
                frame_cursor += 2;
            }
            else
            {
                score += score_simple(frame_cursor);
                frame_cursor += 2;
            }
        }
        return score;
    }

    int Game::score_simple(const vector<int>::const_iterator &it)
    {
        return *it + *(it + 1);
    }

    bool Game::is_spare(const vector<int>::const_iterator &it)
    {
        return *it + *(it + 1) == 10;
    }

    int Game::score_spare(const vector<int>::const_iterator &it)
    {
        return 10 + *(it + 2);
    }

    bool Game::is_strike(const vector<int>::const_iterator &it)
    {
        return *it == 10;
    }

    int Game::score_strike(const vector<int>::const_iterator &it)
    {
        return 10 + *(it + 1) + *(it + 2);
    }

    void Game::roll(int roll)
    {
        _rolls.push_back(roll);
    }
} // namespace bowling
