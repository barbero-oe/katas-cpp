#pragma once
#include <vector>

namespace bowling
{
    class Game
    {
    private:
    std::vector<int> _rolls;

    bool is_spare(const std::vector<int>::const_iterator&);
    bool is_strike(const std::vector<int>::const_iterator&);

    int score_simple(const std::vector<int>::const_iterator&);
    int score_spare(const std::vector<int>::const_iterator&);
    int score_strike(const std::vector<int>::const_iterator&);

    public:
        Game() {};

        void roll(int);
        int score();
    };

    bool is_spare(const std::vector<int>::const_iterator&);
} // namespace bowling
