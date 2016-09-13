#include "game.h"
#include <iostream>
#include <InputHandler.h>

using namespace std;

Game* Game::instance = NULL;

Game* Game::Instance(){
   if (!instance)
      instance = new Game();

   return instance;
}

bool Game::init(const char* title, int xpos, int ypos, int height, int width, int flags){

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        cout<<"SDL init success\n";

        window = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

        if(window != 0){
            cout<<"Window create success\n";

            renderer = SDL_CreateRenderer(window, -1, 0);

            if(renderer != 0){
                cout<<"Renderer create success\n";

                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            }else{
                cout<<"Renderer init fail\n";
                return false;
            }
        }else{
            cout<<"Window init fail\n";
            return false;
        }
    }else{
        cout<<"SDL init fail\n";
        return false;
    }

    cout<<"Init success\n";

    is_running = true;

    if(!TextureManager::Instance()->load("assets/char9.png", "animate", renderer)){
        return false;
    }

   /* go = new GameObject(100, 100);
    player = new Player(300, 300);
    enemy = new Enemy(0, 0);

    go->load(100, 100, 128, 82, "animate");
    player->load(300, 300, 128, 82, "animate");
    enemy->load(0, 0, 128, 82, "animate");*/

    m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82,"animate")));
    m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82,"animate")));

    return true;
}

void Game::handleEvents(){
    //InputHandler::Instance()->update();
    InputHandler::Instance()->update();
}

void Game::quit(){
    is_running = false;
}

void Game::update(){

    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++){
        m_gameObjects[i]->update();
    }

    m_currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Game::render(){

    SDL_RenderClear(renderer);

    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++){
        m_gameObjects[i]->draw();
    }

    SDL_RenderPresent(renderer);
}

void Game::clean(){
    cout<<"Cleaning game\n";
    InputHandler::Instance()->clean();
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

