// Linux :
// Win64 : x86_64-w64-mingw32-g++ -Wall -Ilib/SDL2-2.0.16/x86_64-w64-mingw32/include -Llib/SDL2-2.0.16/x86_64-w64-mingw32/lib src/main.cpp -o bin/shcpoc.exe -static -lmingw32 -lSDL2main -lSDL2 -mwindows  -Wl,--dynamicbase -Wl,--nxcompat -Wl,--high-entropy-va -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lsetupapi -lversion -luuid

#include <SDL2/SDL.h>
#include <cstdlib>

int main(int argc, char* argv[]) 
{      
    if (SDL_Init(SDL_INIT_VIDEO) < 0)     
    {         
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        return EXIT_FAILURE;     
    }       
    SDL_Window* pWindow{ nullptr };     
    SDL_Renderer* pRenderer{ nullptr };       
    if (SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)     
    {         
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());         
        SDL_Quit();         
        return EXIT_FAILURE;     
    }
    SDL_SetWindowTitle(pWindow, "Test");     
    SDL_Delay(5000);      
    SDL_DestroyRenderer(pRenderer);     
    SDL_DestroyWindow(pWindow);     
    SDL_Quit();     
    return EXIT_SUCCESS; 
}