#ifndef INTRO_H_INCLUDED
#define INTRO_H_INCLUDED

#include <iostream>
#include <list>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"
#include "struct.h"
#include <SDL_ttf.h>
using namespace std;
struct Menu{
    int x,y;
    int reveal = 0;
    SDL_Texture *background,*logo,*play,*exit;
    int backgroundX = 0;
    void init(Graphics& graphics){
        background = graphics.loadTexture("image/background.jpg");
        logo = graphics.loadTexture("image/logo.png");
        play = graphics.loadTexture("image/play.png");
        exit = graphics.loadTexture("image/exit.png");
    }
    void doBackground(void) {
    if(--backgroundX < -SCREEN_WIDTH) backgroundX = 0;
    }
    void drawBackground(SDL_Renderer*renderer) {
        SDL_Rect dest;
        for (int x = backgroundX;x < SCREEN_WIDTH;x += SCREEN_WIDTH) {
            dest.x = x;
            dest.y = 0;
            dest.w = SCREEN_WIDTH;
            dest.h = SCREEN_HEIGHT;

            SDL_RenderCopy(renderer,background,NULL,&dest);
        }
    }
    void drawLogo(Graphics&graphics) {
        SDL_Rect dest;
        dest.x = 0;
        dest.y = 0;
        SDL_QueryTexture(logo,NULL,NULL,&dest.w,&dest.h);
        dest.h = min(reveal,dest.h);
        graphics.blitRect(logo,&dest,(SCREEN_WIDTH/2) - (dest.w/2),-60);
        if (reveal == 350) {
            graphics.renderTexture(play,SCREEN_WIDTH/2 - 125,350);
            graphics.renderTexture(exit,SCREEN_WIDTH/2 - 125,507);
        }
    }
    void doLogic()  {
        doBackground();
        if(reveal < 350) {
            reveal++;
          }
        }
    void draw(Graphics&graphics) {
        drawBackground(graphics.renderer);
        drawLogo(graphics);
    }
};

#endif // INTRO_H_INCLUDED
