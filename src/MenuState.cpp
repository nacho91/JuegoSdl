#include "MenuState.h"
#include <iostream>
#include <TextureManager.h>
#include <game.h>
#include <MenuButton.h>

const std::string MenuState::menuID = "MENU";

MenuState::MenuState()
{
    //ctor
}

void MenuState::update(){

    for(int i = 0; i < menuObjects.size(); i++)  {
        menuObjects[i]->update();
    }
}

void MenuState::render(){

    for(int i = 0; i < menuObjects.size(); i++)  {
        menuObjects[i]->draw();
    }
}

bool MenuState::onEnter(){
    cout<<"Enter menu\n";

    if(!TextureManager::Instance()->load("assets/menuPlay.png", "play", Game::Instance()->getRenderer())){
        cout<<"Error load menu_play.png\n";
        return false;
    }

    GameObject* play = new MenuButton(new LoaderParams(150, 300, 100, 19, "play"));

    menuObjects.push_back(play);

    return true;
}

bool MenuState::onExit(){
    cout<<"Exit menu\n";

    return true;
}
