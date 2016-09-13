//Using SDL and standard IO
#include <game.h>
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int FPS = 2;
const int DELAY_TIME = 1000.0f / FPS;

int main( int argc, char* args[] )
{
    Uint32 frameStart, frameTime;

    if(!Game::Instance()->init("Juego", 150, 150, SCREEN_HEIGHT, SCREEN_WIDTH, 0)){
        return -1;
    }

    while(Game::Instance()->running()){
        frameStart = SDL_GetTicks();

        Game::Instance()->handleEvents();
        Game::Instance()->update();
        Game::Instance()->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameStart < DELAY_TIME){
            SDL_Delay((int)(DELAY_TIME - frameTime));
        }
    }

    Game::Instance()->clean();

    return 0;
}
