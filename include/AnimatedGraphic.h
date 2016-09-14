#ifndef ANIMATEDGRAPHIC_H
#define ANIMATEDGRAPHIC_H

#include <SDLGameObject.h>


class AnimatedGraphic : public SDLGameObject
{
    public:
        AnimatedGraphic(const LoaderParams* params, int animSpeed);
        virtual ~AnimatedGraphic();

        virtual void draw();
        virtual void update();
        virtual void clean();
    protected:

    private:
        int animSpeed;
};

#endif // ANIMATEDGRAPHIC_H
