#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include <GameState.h>
#include <GameObject.h>
#include <vector>

using namespace std;

class GameOverState : public GameState
{
    public:
        GameOverState();

        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateID() const { return gameOverID; }
    protected:
    private:

        static const std::string gameOverID;

        std::vector<GameObject*> gameOverObjects;
};

#endif // GAMEOVERSTATE_H
