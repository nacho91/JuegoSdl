#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int animSpeed) : SDLGameObject(pParams), animSpeed(animSpeed) {
}

AnimatedGraphic::~AnimatedGraphic()
{
    //dtor
}

void AnimatedGraphic::update(){
    currentFrame = int(((SDL_GetTicks() / (1000 / animSpeed)) %   2));
}

void AnimatedGraphic::draw(){
    SDLGameObject::draw();
}

void AnimatedGraphic::clean(){
    SDLGameObject::clean();
}
