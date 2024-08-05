#ifndef _EZSTREAM_IMAGECONTAINER_H_
#define _EZSTREAM_IMAGECONTAINER_H_

#include <map>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class ImageContainer
{
private:
    static ImageContainer* _img_ptr;
    std::map<std::string, SDL_Texture*> _textures;
    SDL_Renderer* _ren_ptr;

    ImageContainer() {}

public:
    static ImageContainer* get();
    static void destroy();

    // Outputs a string key for 
    static std::string makeCSSImgKey(const std::string& character);
    static std::string makeCostumeImgKey(const std::string& character, int cost_num);
    static std::string makeRenderImgKey(const std::string& character, int cost_num);

    void setRenderer(SDL_Renderer* ren) { this->_ren_ptr = ren; }
    SDL_Texture* getImage(const std::string& key);
    SDL_Texture* loadImage(const std::string& key, const std::string& filename);
    void unloadImage(const std::string& key);
    void unloadAllImages();
    void deleteContainer();
};

#endif