#ifndef SDLGAMEOBJECT_H
#define SDLGAMEOBJECT_H

#include <GameObject.h>
#include <Vector2D.h>

class SDLGameObject : public GameObject
{
    public:
        SDLGameObject(const LoaderParams* params);

        virtual void draw();
        virtual void update();
        virtual void clean();
    protected:

        Vector2D position;
        Vector2D velocity;
        Vector2D acceleration;

        int width;
        int height;

        int currentFrame;
        int currentRow;

        std::string textureID;
    private:
};

#endif // SDLGAMEOBJECT_H
