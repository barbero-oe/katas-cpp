#pragma once
#include <vector>

namespace bowling
{
    class Game
    {
    private:
    std::vector<int> _rolls;

    int frame_score(int);
    int simple_score(const std::vector<int>::const_iterator&);
    bool is_spare(const std::vector<int>::const_iterator&);
    int score_spare(const std::vector<int>::const_iterator&);

    public:
        Game() {};

        void roll(int);
        int score();
    };

    bool is_spare(const std::vector<int>::const_iterator&);
} // namespace bowling
