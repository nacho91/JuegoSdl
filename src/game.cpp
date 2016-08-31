#include "game.h"
#include <iostream>

using namespace std;

Game::Game()
{
    //ctor
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

    go.load(100, 100, 128, 82, "animate");
    player.load(300, 300, 128, 82, "animate");

    return true;
}

void Game::handleEvents(){

    SDL_Event event;

    if(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
            is_running = false;
            break;
        default:
            break;
        }
    }
}

void Game::update(){

    go.update();
    player.update();

    m_currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Game::render(){

    SDL_RenderClear(renderer);

    go.draw(renderer);
    player.draw(renderer);

    SDL_RenderPresent(renderer);
}

void Game::clean(){
    cout<<"Cleaning game\n";
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

