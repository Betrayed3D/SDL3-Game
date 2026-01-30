#pragma once
#include<SDL3/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>

class Screen
{
private:
    SDL_Window* MainWindow;
    SDL_Event MainEvent;
    SDL_GLContext MainContext;
    bool ShowWindow;
public:
    Screen();
    ~Screen();
    bool InitSDL(SDL_InitFlags InitFlags);
    bool SDLCreateWindow(const char* WindowTitle, int WindowWidth, int WindowHeight, SDL_WindowFlags WindowFlags);
    bool CreateRenderer();
    void RenderLoop();
    void ExitSDL(SDL_Window* Window);
};