#include "MenuButton.h"

MenuButton::MenuButton(const LoaderParams* params) : SDLGameObject(params)
{
    currentFrame = 0;
}

MenuButton::~MenuButton()
{
    //dtor
}

void MenuButton::draw(){
    SDLGameObject::draw();
}

void MenuButton::update(){
    SDLGameObject::update();
}

void MenuButton::clean(){
    SDLGameObject::clean();
}
