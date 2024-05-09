#ifndef GAMEOVER_H_INCLUDED
#define GAMEOVER_H_INCLUDED

#include <iostream>
#include <list>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"
#include "struct.h"
#include <SDL_ttf.h>
using namespace std;
struct GameOver{
    TTF_Font*font;
    SDL_Texture *background,*gameover,*press;
    Mix_Chunk* pressR;
    int backgroundX = 0;

    void init(Graphics& graphics){
        background = graphics.loadTexture("image/background.jpg");
        gameover = graphics.loadTexture("image/gameover.png");
        font = graphics.loadFont("Font/a.ttf",70);
        pressR = graphics.loadSound("MusicSound/90s-game-ui-2-185095.wav");
    }

    void doBackground(void) {
    if(--backgroundX < -SCREEN_WIDTH) backgroundX = 0;}

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
    void doMaster(int keyboard[],Graphics&graphics) {
        if (keyboard[SDL_SCANCODE_R]) {
            graphics.play(pressR);
            graphics.playtime = PLAY;

        }
    }

    void drawText(Graphics&graphics) {
        press = graphics.renderText("Press R to try again !",font,COLOR);
        graphics.renderTexture(press,SCREEN_WIDTH/2 - 180,390);
    }

    void doLogic(int keyboard[],Graphics&graphics)  {
        doBackground();
        doMaster(keyboard,graphics);
    }

    void draw(Graphics&graphics) {
        drawBackground(graphics.renderer);
        graphics.renderTexture(gameover,SCREEN_WIDTH/2 - 215,100);
        drawText(graphics);
    }
};

#endif // GAMEOVER_H_INCLUDED
