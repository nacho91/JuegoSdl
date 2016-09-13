#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <TextureManager.h>
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <GameStateMachine.h>

using namespace std;

class Game
{
    public:

        static Game* Instance();

        ~Game();

        bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
        void render();
        void update();
        void handleEvents();
        void clean();
        void quit();
        bool running(){ return is_running; }
        SDL_Renderer* getRenderer() const { return renderer; }

    protected:

    private:

        Game(){};

        static Game* instance;

        GameObject* go;
        GameObject* player;
        GameObject* enemy;

        std::vector<GameObject*> m_gameObjects;

        SDL_Window* window;
        SDL_Renderer* renderer;
        bool is_running;

        SDL_Texture* texture;
        SDL_Rect sourceRectangle;
        SDL_Rect destinationRectangle;

        int m_currentFrame;

        GameStateMachine* gameStateMachine;
};

#endif // GAME_H
