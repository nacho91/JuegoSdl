#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <SDLGameObject.h>


class MenuButton : public SDLGameObject
{
    public:
        MenuButton(const LoaderParams* params);
        virtual ~MenuButton();

        void update();
        void draw();
        void clean();
    protected:

    private:
};

#endif // MENUBUTTON_H
