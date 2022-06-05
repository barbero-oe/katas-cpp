#pragma once
// #include <vector>

namespace bowling
{
    class Game
    {
    private:
    int _score = 0;
    public:
        Game() {};

        void roll(int);
        int score();
    };

} // namespace bowling
