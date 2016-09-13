#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H

#include "GameState.h"
#include "vector"

using namespace std;

class GameStateMachine
{
    public:
        void pushState(GameState* pState);
        void changeState(GameState* pState);
        void popState();

        void update();
        void render();
    protected:
    private:
        std::vector<GameState*> gameStates;
};

#endif // GAMESTATEMACHINE_H
