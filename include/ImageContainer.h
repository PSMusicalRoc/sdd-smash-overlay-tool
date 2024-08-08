#ifndef _EZSTREAM_IMAGECONTAINER_H_
#define _EZSTREAM_IMAGECONTAINER_H_

#include <map>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

//Singleton that stores all loaded images
class ImageContainer
{
private:
    static ImageContainer* _img_ptr; // reference to singleton
    std::map<std::string, SDL_Texture*> _textures; // map of all loaded textures
    SDL_Renderer* _ren_ptr;

    // Default Constructor (for singleton)
    ImageContainer() {}

public:
    // get reference to the singleton
    static ImageContainer* get();

    static void destroy();

    // Outputs a string key for 
    static std::string makeCSSImgKey(const std::string& character);
    static std::string makeCostumeImgKey(const std::string& character, int cost_num);
    static std::string makeRenderImgKey(const std::string& character, int cost_num);

    void setRenderer(SDL_Renderer* ren) { this->_ren_ptr = ren; }

    // get loaded image from _textures
    SDL_Texture* getImage(const std::string& key);

    // load new image into _textures
    SDL_Texture* loadImage(const std::string& key, const std::string& file_name);
    
    // removes one image from _textures
    void unloadImage(const std::string& key);

    // clears _textures
    void unloadAllImages();
    
    void deleteContainer();
};

#endif