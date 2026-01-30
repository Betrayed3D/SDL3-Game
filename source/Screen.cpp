#include<Screen.h>

Screen::Screen()
{
    ShowWindow = false;
}

Screen::~Screen()
{
    // Destructor code
}

bool Screen::InitSDL(SDL_InitFlags InitFlags)
{
    bool Success{false};

    if(!SDL_Init(InitFlags))
    {
        SDL_Log("Failed to start: ", InitFlags, " SDL error: ", SDL_GetError());
        Success = false;
        return Success;
    }

    Success = true;
    return Success;
}

bool Screen::CreateWindow(const char* WindowTitle, int WindowWidth, int WindowHeight, SDL_WindowFlags WindowFlags)
{
    bool Success{false};
    
    Window = SDL_CreateWindow(WindowTitle, WindowWidth, WindowHeight, WindowFlags);
    if(Window == NULL)
    {
        SDL_Log("Window creation failed. SDL error: ", SDL_GetError());
        return Success;
    }

    Success = true;
    return Success;
}

void Screen::RenderLoop()
{
    ShowWindow = true;
    while(ShowWindow == true)
    {
        while(SDL_PollEvent(&MainEvent))
        {
            if(MainEvent.type == SDL_EVENT_QUIT)
            {
                ShowWindow = false;
                ExitSDL();
            }
        }
    }

}

void Screen::ExitSDL()
{
    SDL_DestroyWindow(Window);
    SDL_Quit();
}