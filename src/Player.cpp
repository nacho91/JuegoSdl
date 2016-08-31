#include "Player.h"

Player::Player()
{
    //ctor
}

Player::~Player()
{
    //dtor
}

void Player::load(int x, int y, int width, int height, std::string textureID){
    GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* renderer){
    GameObject::draw(renderer);
}

void Player::update(){
    x -= 1;
}
