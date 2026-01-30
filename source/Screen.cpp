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

bool Screen::SDLCreateWindow(const char* WindowTitle, int WindowWidth, int WindowHeight, SDL_WindowFlags WindowFlags)
{
    bool Success{false};
    
    // Create the SDL window
    MainWindow = SDL_CreateWindow(WindowTitle, WindowWidth, WindowHeight, WindowFlags);
    if(MainWindow == NULL)
    {
        SDL_Log("Window creation failed. SDL error: ", SDL_GetError());
        return Success;
    }
    else
    {
        // Create OpenGL context
        MainContext = SDL_GL_CreateContext(MainWindow);
        if(MainContext == NULL)
        {
            SDL_Log("Failed to create OpenGL context. SDL error: ", SDL_GetError());
            return Success;
        }
        else
        {
            // Set current context
            if(!SDL_GL_MakeCurrent(MainWindow,MainContext))
            {
                SDL_Log("SDL_GL_MakeCurrent failed! SDL error: ", SDL_GetError());
                return Success;
            }
        }
    }

    // Keep the window open
    ShowWindow = true;
    while(ShowWindow == true)
    {
        while(SDL_PollEvent(&MainEvent))
        {
            if(MainEvent.type == SDL_EVENT_QUIT)
            {
                ShowWindow = false;
                ExitSDL(MainWindow);
            }
        }
    }

    Success = true;
    return Success;
}

void Screen::ExitSDL(SDL_Window* Window)
{
    SDL_DestroyWindow(Window);
    SDL_Quit();
}