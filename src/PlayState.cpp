#include "PlayState.h"

const std::string PlayState::playID = "PLAY";

PlayState::PlayState()
{
    //ctor
}

void PlayState::update(){
}

void PlayState::render(){
}

bool PlayState::onEnter(){
        cout<<"Enter play\n";
}

bool PlayState::onExit(){
}
