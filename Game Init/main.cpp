#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"
#include "struct.h"
#include "logic.h"
#include "input.h"
#include <ctime>
#include <SDL_ttf.h>
#include "intro.h"
#include "gameover.h"
using namespace std;

int main (int agr,char* argv[])
{
    srand(time(0));
    Graphics graphics;
    graphics.init();
    Input input;
    input.init();

    Game game;
    game.init(graphics);

    Menu menu;
    menu.init(graphics);

    GameOver gameover;
    gameover.init(graphics);

    int x, y;
    while (1)
	{
		graphics.prepareScene();
		input.get(graphics);
        if (graphics.playtime == PLAY) {
            game.doLogic(input.keyboard,graphics);
            game.draw(graphics);}
        if (graphics.playtime == MENU){
            menu.doLogic();
            menu.draw(graphics);}
        if (graphics.playtime == LOSE){
            gameover.doLogic(input.keyboard,graphics);
            gameover.draw(graphics);
        }
		graphics.presentScene();
		SDL_Delay(10);
	}
    graphics.quit();
    return 0;
}
