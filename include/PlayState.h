#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include <GameState.h>
#include <GameObject.h>
#include <vector>

class PlayState : public GameState
{
    public:
        PlayState();
        void update();
        void render();

        bool onEnter();
        bool onExit();

        virtual std::string getStateID() const { return playID; }
    protected:
    private:

        static const std::string playID;

        std::vector<GameObject*> playObjects;
};

#endif // PLAYSTATE_H
