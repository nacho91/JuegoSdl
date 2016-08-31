#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.h"
#include "Player.h"

class Game
{
    public:
        Game();
        ~Game();

        bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
        void render();
        void update();
        void handleEvents();
        void clean();
        bool running(){ return is_running; }

    protected:

    private:

        GameObject go;
        Player player;

        SDL_Window* window;
        SDL_Renderer* renderer;
        bool is_running;

        SDL_Texture* texture;
        SDL_Rect sourceRectangle;
        SDL_Rect destinationRectangle;

        int m_currentFrame;
};

#endif // GAME_H
