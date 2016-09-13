#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL2/SDL.h>

class InputHandler
{
    public:

        static InputHandler* Instance();

        void update();
        void clean();

        bool isKeyDown(SDL_Scancode key);
    private:

        InputHandler(){};
        ~InputHandler() {}
        static InputHandler* instance;

        const Uint8* m_keystates;

};

#endif // INPUTHANDLER_H
