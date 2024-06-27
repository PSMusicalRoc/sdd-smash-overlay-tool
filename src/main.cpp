#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include <SDL.h>

#include "MainWindow.h"

#include <iostream>

int main(int argc, char** argv)
{
    // init SDL backend
    if ( SDL_Init(SDL_INIT_EVERYTHING) < 0 )
    {
        std::cerr << "SDL Init Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // create window
    SDL_Window* win;
    SDL_Renderer* ren;
    win = SDL_CreateWindow( "RPI EZ-Stream",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1000, 500, SDL_WINDOW_SHOWN
    );
    if ( win == NULL )
    {
        std::cerr << "SDL Create Window Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    // create renderer
    ren = SDL_CreateRenderer( win, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED );
    if ( ren == NULL )
    {
        std::cerr << "SDL Create Renderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        return -1;
    }


    // Set up ImGui

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    // disable imgui ini
    io.IniFilename = NULL;
    
    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForSDLRenderer( win, ren );
    ImGui_ImplSDLRenderer2_Init( ren );

    MainWindow mw;

    SDL_Event ev;
    bool app_still_running = true;
    ImVec4 clear_color = ImVec4(0.0f, 0.0f, 0.0f, 1.00f);
    while ( app_still_running )
    {

        // Poll for events, do things based on
        // which event it is
        while ( SDL_PollEvent(&ev) )
        {
            ImGui_ImplSDL2_ProcessEvent( &ev );
            if (ev.type == SDL_EventType::SDL_QUIT)
            {
                app_still_running = false;
            }
        }

        if ( !app_still_running ) continue;

        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();


        // Do all graphics calls in between here...

        ImGui::ShowDemoWindow(NULL);

        ImGui::Begin("TestWindow", NULL);

        mw.render();

        ImGui::End();

        
        
        // ... and here.
        
        
        ImGui::Render();
        SDL_RenderSetScale( ren, io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y );
        SDL_SetRenderDrawColor( ren, (Uint8)(clear_color.x * 255),
            (Uint8)(clear_color.y * 255), (Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255) );
        SDL_RenderClear( ren );
        ImGui_ImplSDLRenderer2_RenderDrawData( ImGui::GetDrawData(), ren );
        SDL_RenderPresent( ren );
    }

    // deinit imgui
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    // delete window and renderer
    SDL_DestroyRenderer( ren );
    SDL_DestroyWindow( win );

    // close SDL backend
    SDL_Quit();

    return 0;
}