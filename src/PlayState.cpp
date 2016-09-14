#include "PlayState.h"
#include <TextureManager.h>
#include <game.h>
#include <InputHandler.h>

const std::string PlayState::playID = "PLAY";

PlayState::PlayState()
{
    //ctor
}

void PlayState::update(){

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))  {
        Game::Instance()->pause();
    }

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_O))  {
        Game::Instance()->over();
    }

    for(int i = 0; i < playObjects.size(); i++)  {
        playObjects[i]->update();
    }
}

void PlayState::render(){

    for(int i = 0; i < playObjects.size(); i++)  {
        playObjects[i]->draw();
    }
}

bool PlayState::onEnter(){
    cout<<"Enter Play\n";

    if(!TextureManager::Instance()->load("assets/char9.png", "player", Game::Instance()->getRenderer())){
        cout<<"Error load char9.png\n";
        return false;
    }

    GameObject* player = new Player(new LoaderParams(150, 300, 128, 82, "player"));

    playObjects.push_back(player);

    return true;
}

bool PlayState::onExit(){
    cout<<"Exit Play\n";

    return true;
}
