#include "Player.h"
#include "InputHandler.h"

Player::Player(const LoaderParams* params) : SDLGameObject(params)
{
    //ctor
}

void Player::draw(){
    SDLGameObject::draw();
}

void Player::update(){

     velocity.setX(0);
    velocity.setY(0);

    handleInput();

    currentFrame = int(((SDL_GetTicks() / 100) % 6));

    SDLGameObject::update();
}

void Player::handleInput(){
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)){
        position.setX(position.getX() + 0.1f);
    }

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)){
        position.setX(position.getX() - 0.1f);
    }

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)){
        position.setY(position.getY() - 0.1f);
    }

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)){
        position.setY(position.getY() + 0.1f);
    }
}

void Player::clean(){
}
