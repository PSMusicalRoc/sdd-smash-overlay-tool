#ifndef _LOADIMAGE_H_
#define _LOADIMAGE_H_

#include <string>

class LoadImage {

    private: 
        static LoadImage* _reference;

    public: 
        static LoadImage* get();
        static void destroy();

        SDL_Texture* grabImage(const char* imagePath, SDL_Renderer* mainRender);


};

#endif