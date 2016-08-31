//Using SDL and standard IO
#include <game.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Game* game = 0;

int main( int argc, char* args[] )
{
    game = new Game();

    if(!game->init("Juego", 150, 150, SCREEN_HEIGHT, SCREEN_WIDTH, 0)){
        return -1;
    }

    while(game->running()){
        game->handleEvents();
        game->update();
        game->render();

        SDL_Delay(10);
    }

    game->clean();

    return 0;
}
