#include "GameObject.h"
#include "TextureManager.h"
#include "Vector2D.h"


void GameObject::load(int x, int y, int width, int height, std::string textureID){
    this->position.setX(x);
    this->position.setY(y);
    this->width = width;
    this->height = height;
    this->textureID = textureID;
    this->currentRow = 1;
    this->currentFrame = 1;
}

void GameObject::draw(SDL_Renderer* renderer){
    TextureManager::Instance()->drawFrame(textureID, position.getX(), position.getX(), width, height, currentRow, currentFrame, renderer);
}

void GameObject::update(){
    position.setX(position.getX() + 1);
    position.setY(position.getY() + 1);
}

void GameObject::clean(){
}
