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
            if (is_spare(frame_cursor)) {
                score += score_spare(frame_cursor);
                frame_cursor += 2;
            } else {
                score += simple_score(frame_cursor);
                frame_cursor += 2;
            }
        }
        return score;
    }

    bool Game::is_spare(const vector<int>::const_iterator& it) {
        return *it + *(it + 1) == 10;
    }

    int Game::score_spare(const vector<int>::const_iterator& it) {
        return 10 + *(it + 2);
    }

    int Game::simple_score(const vector<int>::const_iterator& it) {
        return *it + *(it + 1);
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
