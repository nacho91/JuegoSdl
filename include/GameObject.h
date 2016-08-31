#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

class GameObject
{
    public:
        GameObject();
        virtual ~GameObject();

        void load(int x, int y, int width, int height, std::string textureID);
        void draw(SDL_Renderer* renderer);
        void update();
        void clean();
    protected:

        int x;
        int y;

        std::string textureID;
        int currentFrame;
        int currentRow;

        int width;
        int height;

    private:

};

#endif // GAMEOBJECT_H
