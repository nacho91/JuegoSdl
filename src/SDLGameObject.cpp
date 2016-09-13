#include "SDLGameObject.h"
#include "TextureManager.h"
#include "game.h"

SDLGameObject::SDLGameObject(const LoaderParams* params) : GameObject(params), position(params->getX(), params->getY()), velocity(0, 0), acceleration(0, 0)
{
    this->width = params->getWidth();
    this->height = params->getHeight();
    this->textureID = params->getTextureID();

    this->currentFrame = 1;
    this->currentRow = 1;
}

void SDLGameObject::draw(){
    TextureManager::Instance()->drawFrame(textureID, (int) position.getX(), (int) position.getY(), width, height, currentRow, currentFrame, Game::Instance()->getRenderer());
}

void SDLGameObject::update(){
    velocity += acceleration;
    position += velocity;
}

void SDLGameObject::clean(){
}
