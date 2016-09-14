#include "GameOverState.h"
#include <iostream>
#include <TextureManager.h>
#include <game.h>
#include <AnimatedGraphic.h>

const std::string GameOverState::gameOverID = "GAME_OVER";

GameOverState::GameOverState()
{
    //ctor
}

void GameOverState::update(){

    for(int i = 0; i < gameOverObjects.size(); i++)  {
        gameOverObjects[i]->update();
    }
}

void GameOverState::render(){

    for(int i = 0; i < gameOverObjects.size(); i++)  {
        gameOverObjects[i]->draw();
    }
}

bool GameOverState::onEnter(){
    cout<<"Enter menu\n";

    if(!TextureManager::Instance()->load("assets/game_over.png", "gameOver", Game::Instance()->getRenderer())){
        cout<<"Error load menu_play.png\n";
        return false;
    }

    GameObject* play = new AnimatedGraphic(new LoaderParams(150, 300, 103, 18, "gameOver"), 500);

    gameOverObjects.push_back(play);

    return true;
}

bool GameOverState::onExit(){
    cout<<"Exit menu\n";

    return true;
}

