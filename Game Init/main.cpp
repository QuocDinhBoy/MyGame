#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"
#include "struct.h"
#include "logic.h"
#include <ctime>
#include "input.h"
using namespace std;
    void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
int main (int agr,char* argv[])
{
    srand(time(0));

    Graphics graphics;
    graphics.init();

    Input input;
    input.init();

    Game game;
    game.init(graphics);
    while (1)
	{
		graphics.prepareScene();

		input.get();

        game.doLogic(input.keyboard);
        game.draw(graphics);

		graphics.presentScene();

	}
    graphics.quit();
    return 0;
}
