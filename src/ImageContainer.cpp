#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "SDL_image.h"
#include "ImageContainer.h"

ImageContainer* ImageContainer::_img_ptr = nullptr;

ImageContainer* ImageContainer::get()
{
    if (_img_ptr == nullptr)
    {
        _img_ptr = new ImageContainer();
    }
    return _img_ptr;
}

void ImageContainer::destroy()
{
    if (_img_ptr != nullptr)
    {
        _img_ptr->deleteContainer();
        delete _img_ptr;
        _img_ptr = nullptr;
    }
}


SDL_Texture* ImageContainer::getImage(const std::string& key)
{
    if (this->_textures.find(key) == this->_textures.end())
    {
        return nullptr;
    }
    return this->_textures[key];
}

SDL_Texture* ImageContainer::loadImage(const std::string& key, const std::string& filename)
{
    if (this->_textures.find(key) != this->_textures.end())
    {
        // unload current image at key
        this->unloadImage(key);
    }

    // Load the image
    // SDL_Surface* surface = IMG_Load(filename.c_str());
    // if (!surface) {
    //     std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
    //     return nullptr;
    // }

    // Create a texture from the surface
    SDL_Texture* texture = IMG_LoadTexture(_ren_ptr, filename.c_str());
    // SDL_FreeSurface(surface);  // We no longer need the surface

    if (!texture) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    _textures.emplace(key, texture);
    return texture;
}

void ImageContainer::unloadImage(const std::string& key)
{
    if (this->_textures.find(key) == this->_textures.end())
    {
        return;
    }
    SDL_DestroyTexture(_textures[key]);
    _textures.erase(key);
}

void ImageContainer::unloadAllImages()
{
    for (std::pair<std::string, SDL_Texture*> p : _textures)
    {
        SDL_DestroyTexture(p.second);
    }
    _textures.clear();
}

void ImageContainer::deleteContainer()
{
    unloadAllImages();
    this->_ren_ptr = nullptr;
}

// void LoadImage:: grabImage(const char* imagePath) {
//     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//         std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
//     }

//     // Initialize SDL_image
//     if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
//         std::cerr << "Failed to initialize SDL_image: " << IMG_GetError() << std::endl;
//         SDL_Quit();
//     }

//     // Create a window
//     SDL_Window* window = SDL_CreateWindow("SDL2 Image Loading", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
//     if (!window) {
//         std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
//         IMG_Quit();
//         SDL_Quit();
//     }

//     // Create a renderer
//     SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//     if (!renderer) {
//         std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
//         SDL_DestroyWindow(window);
//         IMG_Quit();
//         SDL_Quit();
//     }

//     // Load the image
//     SDL_Surface* surface = IMG_Load(imagePath);
//     if (!surface) {
//         std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
//         SDL_DestroyRenderer(renderer);
//         SDL_DestroyWindow(window);
//         IMG_Quit();
//         SDL_Quit();
//     }

//     // Create a texture from the surface
//     SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
//     SDL_FreeSurface(surface);  // We no longer need the surface

//     if (!texture) {
//         std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
//         SDL_DestroyRenderer(renderer);
//         SDL_DestroyWindow(window);
//         IMG_Quit();
//         SDL_Quit();
//     }

//     // Main loop flag
//     bool quit = false;
//     // Event handler
//     SDL_Event e;

//     // While application is running
//     while (!quit) {
//         // Handle events on queue
//         while (SDL_PollEvent(&e) != 0) {
//             // User requests quit
//             if (e.type == SDL_QUIT) {
//                 quit = true;
//             }
//         }

//         // Clear screen
//         SDL_RenderClear(renderer);

//         // Render texture to screen
//         SDL_RenderCopy(renderer, texture, NULL, NULL);

//         // Update screen
//         SDL_RenderPresent(renderer);
//     }

//     // Clean up
//     SDL_DestroyTexture(texture);
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     IMG_Quit();
//     SDL_Quit();

// }