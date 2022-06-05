#pragma once
#include <vector>

namespace bowling
{
    class Game
    {
    private:
    std::vector<int> _rolls;

    public:
        Game() {};

        void roll(int);
        int score();
    };

} // namespace bowling
