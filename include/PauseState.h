#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include <GameState.h>
#include <GameObject.h>
#include <vector>

using namespace std;

class PauseState : public GameState
{
    public:
        PauseState();

        virtual void update();
        virtual void render();

        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateID() const { return pauseID; }
    protected:

    private:

        static const std::string pauseID;

        std::vector<GameObject*> pauseObjects;
};

#endif // PAUSESTATE_H
