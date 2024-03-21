#ifndef _LOGIC__H
#define _LOGIC__H

#include <iostream>
#include <list>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"
#include "struct.h"

using namespace std;
void initPlayer(Entity& player) {
    player.x = 350;
    player.y = 320;
    player.health = 1;
    player.side = SIDE_PLAYER;
    player.reload = 0;
}


struct Game {
    Entity player;
    list <Entity*> bullets;
    list <Entity*> fighters;
    int stageResetTimer;
    void empty(list<Entity*>& entities) {
        while (!entities.empty()) {
            Entity* e = entities.front();
            entities.pop_front();
            if (e != &player) delete e;
        }
    }
    SDL_Texture *bulletTexture,*background;
    int backgroundX = 0;

    void reset() {
        empty(fighters);
        empty(bullets);
        fighters.push_back(&player);
        initPlayer(player);
        stageResetTimer = FRAME_PER_SECOND * 3;
    }

    void init(Graphics& graphics) {
//    player.texture = graphics.loadTexture("image/thang main.png");
    SDL_QueryTexture(player.texture,NULL,NULL,&player.w, &player.h);
    player.texture = graphics.loadTexture("image/Gunner_Blue_Run.png");
    bulletTexture = graphics.loadTexture("image/bullet.png");
    background = graphics.loadTexture("image/background.jpg");
    reset();
}

    void fireBullet() {
    Entity *bullet = new Entity();
    bullets.push_back(bullet);

    bullet->x = player.x + 70;
    bullet->y = player.y + 18.5;
    bullet->w = 40;
    bullet->h = 40;
    bullet->dx = PLAYER_BULLET_SPEED;
    bullet->health = 1;
    bullet->texture = bulletTexture;
    bullet->side = SIDE_PLAYER;
    SDL_QueryTexture(bullet->texture, NULL, NULL, &bullet->w, &bullet->h);

    player.reload =PLAYER_RELOAD;
}

    void doPlayer(int keyboard[]){
    if (player.health == 0) return;
    player.dx = player.dy = 0;
    if (player.reload > 0) player.reload --;

    if (keyboard[SDL_SCANCODE_UP] || keyboard[SDL_SCANCODE_W]) if (player.y == 320) player.dy = -60;
    if (keyboard[SDL_SCANCODE_LEFT] || keyboard[SDL_SCANCODE_A]) player.dx = -PLAYER_SPEED;
    if (keyboard[SDL_SCANCODE_RIGHT] || keyboard[SDL_SCANCODE_D]) player.dx = PLAYER_SPEED;
    if (keyboard[SDL_SCANCODE_SPACE] && player.reload == 0) fireBullet();}
    void doBullets(void)
    {
        auto it = bullets.begin();
        while (it != bullets.end()) {
            auto temp = it++;
            Entity* b = *temp;
            b->move();
            if (b->offScreen()) {
                delete b;
                bullets.erase(temp);
            }
        }
    }


    void doFighters(void)
    {
//        auto it = fighters.begin();
//        it++;
//
//        while (it != fighters.end()) {
//            auto temp = it++;
//            Entity* fighter = *temp;
//
//            fighter->move();
//            if (fighter->x < -fighter->w) fighter->health = 0;
//
//            if (fighter->health == 0) {
//                delete fighter;
//                fighters.erase(temp);
//                continue;
//            }
//        }

        player.move();
        if (player.x < 0) player.x = 0;
        else if (player.x >= SCREEN_WIDTH - player.w)
            player.x = SCREEN_WIDTH - player.w;
        if (player.y < 320) player.y += 3;
	}

    void doBackground(void) {
        if (--backgroundX < -SCREEN_WIDTH)
        {
            backgroundX = 0;
        }
    }

    void doLogic(int keyboard[]) {
//        doBackground();
//        if (player.health == 0 && --stageResetTimer <= 0) reset();
         doPlayer(keyboard);
         doFighters();
         doBullets();
    }

    void drawBackground(SDL_Renderer* renderer) {
    SDL_Rect backgroundDest;
    for (int x = backgroundX;x < SCREEN_WIDTH;x += SCREEN_WIDTH) {
        backgroundDest.x = x;
        backgroundDest.y = 0;
        backgroundDest.w = SCREEN_WIDTH;
        backgroundDest.h = SCREEN_HEIGHT;

        SDL_RenderCopy(renderer,background,NULL,&backgroundDest);
    }
}
    void draw(Graphics& graphics) {
    drawBackground(graphics.renderer);
    for (Entity* b: bullets)
    graphics.renderTexture(b->texture, b->x, b->y);
}
};
#endif // _LOGIC__H
