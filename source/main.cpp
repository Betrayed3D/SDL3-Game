#include<SDL3/SDL_main.h>
#include"Game.h"

int main(int argc, char* argv[])
{
    Screen GameScreen;

    GameScreen.InitSDL(SDL_INIT_VIDEO);
    GameScreen.CreateWindow("Test Window", 800, 600, SDL_WINDOW_HIGH_PIXEL_DENSITY);
    GameScreen.RenderLoop();

    return 0;
}