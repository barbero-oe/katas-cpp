#pragma once
#include <vector>

namespace bowling
{
    class Game
    {
    private:
    std::vector<int> _rolls;

    int frame_score(int);

    public:
        Game() {};

        void roll(int);
        int score();
    };

} // namespace bowling
