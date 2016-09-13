#include "MenuState.h"
#include <iostream>

const std::string MenuState::menuID = "MENU";

MenuState::MenuState()
{
    //ctor
}

void MenuState::update(){
}

void MenuState::render(){
}

bool MenuState::onEnter(){

    cout<<"Enter menu\n";

}

bool MenuState::onExit(){
    cout<<"Exit menu\n";
}
