#pragma once
#include<SDL3/SDL.h>

class Screen
{
private:
    SDL_Window* Window;
    SDL_Event MainEvent;
    bool ShowWindow;
public:
    Screen();
    ~Screen();
    bool InitSDL(SDL_InitFlags InitFlags);
    bool CreateWindow(const char* WindowTitle, int WindowWidth, int WindowHeight, SDL_WindowFlags WindowFlags);
    bool CreateRenderer();
    void RenderLoop();
    void ExitSDL();
};