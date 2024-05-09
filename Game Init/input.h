#include <SDL.h>
#include "defs.h"
#include "struct.h"
#include "logic.h"
#include "graphics.h"
#include <SDL_mixer.h>
struct Input {
    int reveal = 0;
    int x,y;
    int keyboard[MAX_KEYBOARD_KEYS] = {0};

	void init(){
        for (int i = 0; i < MAX_KEYBOARD_KEYS; i++) keyboard[i] = 0;
    }

    void get(Graphics&graphics) {
        Mix_Chunk*clickbutton;
        clickbutton = graphics.loadSound("MusicSound/clickbutton.wav");
        if (reveal < 350) reveal++;
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    exit(0);
                    break;

                case SDL_KEYDOWN:
                    if (event.key.repeat == 0
                        && event.key.keysym.scancode < MAX_KEYBOARD_KEYS) {
                        keyboard[event.key.keysym.scancode] = 1;
                    }
                    break;

                case SDL_KEYUP:
                    if (event.key.repeat == 0
                        && event.key.keysym.scancode < MAX_KEYBOARD_KEYS) {
                        keyboard[event.key.keysym.scancode] = 0;
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    if(graphics.playtime == 0) {
                      SDL_GetMouseState(&x, &y);
                    if (x >= SCREEN_WIDTH/2 - 125 && x <= SCREEN_WIDTH/2 + 125 && y >= 350 && y <= 457 && reveal == 350) {
                            graphics.play(clickbutton);
                            graphics.playtime = 1;
                    }
                    if (x >= SCREEN_WIDTH/2 - 125 && x <= SCREEN_WIDTH/2 + 125 && y >= 507 && y <= 614 && reveal == 350) exit(0);}
                 break;
                 break;
                default:
                    break;
            }
        }
    }
};
