#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include <GameState.h>


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
};

#endif // PLAYSTATE_H
