#include "InputHandler.h"
#include <game.h>

InputHandler* InputHandler::instance = NULL;

InputHandler* InputHandler::Instance(){
   if (!instance)
      instance = new InputHandler();

   return instance;
}

void InputHandler::update(){

    SDL_Event event;

    m_keystates = SDL_GetKeyboardState(0);

    while(SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_QUIT:
                Game::Instance()->quit();
            break;
            /*case SDL_KEYDOWN:
                onKeyDown();
            break;
            case SDL_KEYUP:
                onKeyUp();
            break;*/
        }
    }
}

bool InputHandler::isKeyDown(SDL_Scancode key){
    if(m_keystates != 0){
        if(m_keystates[key] == 1){
            return true;
        }else{
            return false;
        }
    }

    return false;
}

void InputHandler::clean(){
}
