#ifndef MENUSTATE_H
#define MENUSTATE_H

#include <GameState.h>

class MenuState : public GameState
{
    public:
        MenuState();

        virtual void update();
        virtual void render();
        virtual bool onEnter();
        virtual bool onExit();

        virtual std::string getStateID() const { return menuID; }
    protected:
    private:

        static const std::string menuID;
};

#endif // MENUSTATE_H
