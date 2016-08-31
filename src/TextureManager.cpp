#include "TextureManager.h"

 TextureManager* TextureManager::instance = NULL;

   TextureManager* TextureManager::Instance(){

   if (!instance)
      instance = new TextureManager;

   return instance;
}

TextureManager::~TextureManager()
{
    //dtor
}

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* renderer){

     SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

     if(pTempSurface == 0){
        return false;
     }

     SDL_Texture* pTexture =
     SDL_CreateTextureFromSurface(renderer, pTempSurface);
     SDL_FreeSurface(pTempSurface);

     if(pTexture != 0){
         textureMap[id] = pTexture;
         return true;
     }
     // reaching here means something went wrong
     return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip){
     SDL_Rect srcRect;
     SDL_Rect destRect;
     srcRect.x = 0;
     srcRect.y = 0;
     srcRect.w = destRect.w = width;
     srcRect.h = destRect.h = height;
     destRect.x = x;
     destRect.y = y;
     SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip){

     SDL_Rect srcRect;
     SDL_Rect destRect;
     srcRect.x = width * currentFrame;
     srcRect.y = height * (currentRow - 1);
     srcRect.w = destRect.w = width;
     srcRect.h = destRect.h = height;
     destRect.x = x;
     destRect.y = y;
     SDL_RenderCopyEx(pRenderer, textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
