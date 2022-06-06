#pragma once
#include <vector>

namespace bowling
{
    class Game
    {
    private:
    std::vector<int> _rolls;

    typedef const std::vector<int>::const_iterator Frame;


    bool is_spare(Frame&);
    bool is_strike(Frame&);

    int score_frame(Frame&);
    int score_simple(Frame&);
    int score_spare(Frame&);
    int score_strike(Frame&);

    public:
        Game() {};

        void roll(int);
        int score();
    };
} // namespace bowling
