#include "PauseState.h"
#include <game.h>
#include <iostream>
#include <InputHandler.h>

const std::string PauseState::pauseID = "PAUSE";

PauseState::PauseState()
{
    //ctor
}

void PauseState::update(){

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_R))  {
        Game::Instance()->resume();
    }

}

void PauseState::render(){
}

bool PauseState::onEnter(){
    cout<<"Enter Pause\n";

    return true;
}

bool PauseState::onExit(){
    return true;
}
