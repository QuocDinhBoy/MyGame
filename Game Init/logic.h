#ifndef _LOGIC__H
#define _LOGIC__H

#include <iostream>
#include <list>
#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"
#include "graphics.h"
#include "struct.h"
#include <SDL_ttf.h>
using namespace std;
void initPlayer(Entity& player) {
    player.x = 100;
    player.y = 100;
    player.health = 1;
    player.side = SIDE_PLAYER;
    player.reload = 0;
}
void calcSlope(int x1, int y1, int x2, int y2, double *dx, double *dy)
{
	int steps = max(abs(x1 - x2), abs(y1 - y2));

	if (steps == 0)
	{
		*dx = *dy = 0;
		return;
	}

	*dx = (x1 - x2);
	*dx /= steps;

	*dy = (y1 - y2);
	*dy /= steps;
}
struct Game {
    Entity player;
    list<Entity*> fighters;
    list<Entity*> bullets;
    int score,highscore = 0;
    int backgroundX = 0;
    int monsterSpawnTimer;
    int stageResetTimer;
    TTF_Font* font;
    Mix_Music* gMusic;
    Mix_Chunk* lasergun,*failgame;
    SDL_Texture*background,*bulletTexture,*monsterTexture,*monsterHurtTexture,*fireTexture,*deadTexture,*scoreTexture,*highScoreTexture;
    void empty(list<Entity*>& entities) {
        while(!entities.empty()) {
            Entity*e = entities.front();
            entities.pop_front();
            if(e!=&player) delete e;
        }
    }
    void reset() {
        empty(fighters);
        empty(bullets);
    fighters.push_back(&player);
    initPlayer(player);
    monsterSpawnTimer = 0;
    score = 0;
    stageResetTimer = FRAME_PER_SECOND * 3;
    }
     void init(Graphics& graphics) {
        background = graphics.loadTexture("image/background.jpg");
        player.texture = graphics.loadTexture("image/MergedImages.png");
         SDL_QueryTexture(player.texture, NULL, NULL, &player.w, &player.h);
        player.init(player.texture,FLY_FRAMES,FLY_CLIPS);
        monsterTexture = graphics.loadTexture("image/monster.png");
        monsterHurtTexture = graphics.loadTexture("image/monster_hurt.png");
        bulletTexture = graphics.loadTexture("image/Bullet.png");
        fireTexture = graphics.loadTexture("image/fire.png");
        deadTexture = graphics.loadTexture("image/dead.png");
        gMusic = graphics.loadMusic("MusicSound/bgmusic.mp3");
        lasergun = graphics.loadSound("MusicSound/lasergun.wav");
        graphics.play(gMusic);
        failgame = graphics.loadSound("MusicSound/failgame.wav");
        font = graphics.loadFont("Font/GameFont7-vq2M.ttf",50);
        reset();
    }
    void doBackground(void) {
    if(--backgroundX <- SCREEN_WIDTH) backgroundX =0;
    }
    void drawBackground(SDL_Renderer* renderer){
        SDL_Rect dest;
        for (int x = backgroundX;x < SCREEN_WIDTH;x+=SCREEN_WIDTH) {
            dest.x = x;
            dest.y = 0;
            dest.w = SCREEN_WIDTH;
            dest.h = SCREEN_HEIGHT;
            SDL_RenderCopy(renderer,background,NULL,&dest);
        }
    }
    void fireBullet() {
        Entity*bullet = new Entity();
        bullets.push_back(bullet);

        bullet->x = player.x + 90;
        bullet->y = player.y + 34;
        bullet->dx = PLAYER_BULLET_SPEED;
        bullet->health = 1;
        bullet->texture = bulletTexture;
        bullet->side = SIDE_PLAYER;
        SDL_QueryTexture(bullet->texture,NULL,NULL,&bullet->w,&bullet->h);
        player.reload = PLAYER_RELOAD;
    }
    void doPlayer(int keyboard[],Graphics&graphics) {
        if (player.health == 0) return;
        if (player.reload > 0) player.reload--;
        player.dx = 0;
        player.dy = 0;
        if (keyboard[SDL_SCANCODE_W]) player.dy = -PLAYER_SPEED;
        if (keyboard[SDL_SCANCODE_S]) player.dy = PLAYER_SPEED;
        if (keyboard[SDL_SCANCODE_A]) player.dx = -PLAYER_SPEED;
        if (keyboard[SDL_SCANCODE_D]) player.dx = PLAYER_SPEED;
        if (keyboard[SDL_SCANCODE_SPACE] && player.reload == 0) {
                fireBullet();
                graphics.play(lasergun);
        }
    }
    void doFighters(void) {
        auto it = fighters.begin();
        it++;
        while (it != fighters.end()) {
            auto temp = it++;
            Entity* fighter = *temp;
            fighter->move();
            if (fighter->x < -fighter->w) fighter->health = 0;

            if (fighter->health == 0) {
                fighter->texture = monsterHurtTexture;
                fighter->init(monsterHurtTexture,MONSTER_HURT_FRAMES,MONSTER_HURT_CLIPS);
                fighter->side = 0;
                if (fighter->currentFrame == 7){
                delete fighter;
                fighters.erase(temp);
                continue;
                }
            }
        }
        player.move();
        if (player.x < 0) player.x = 0;
        else if (player.x >= SCREEN_WIDTH - player.w)
            player.x = SCREEN_WIDTH - player.w;
        if (player.y < 0) player.y = 0;
        else if (player.y >= SCREEN_HEIGHT - player.h)
            player.y = SCREEN_HEIGHT - player.h;
    }
    void doBullets(void) {
        auto it = bullets.begin();
        while(it != bullets.end()) {
            auto temp = it++;
            Entity*b = *temp;
            b->move();
            if (bulletHiFighter(b) || b->offScreen()) {
                delete b;
                bullets.erase(temp);
            }
        }
    }
    void spawnMonsters(void) {
        if(--monsterSpawnTimer <= 0) {
            Entity*monster = new Entity();
            fighters.push_back(monster);
            monster->x = SCREEN_WIDTH;
            monster->y = 10 + rand()%(SCREEN_HEIGHT - 64);
            monster->dx = -(2 +(rand()%2));
            monster->health = 1;
            monster->side = SIDE_MONSTER;
            monster->texture = monsterTexture;
             monster->reload = FRAME_PER_SECOND * (1 + (rand() % 3));
            SDL_QueryTexture(monster->texture, NULL, NULL, &monster->w, &monster->h);
            monster->init(monsterTexture,MONSTER_FRAMES,MONSTER_CLIPS);
            monsterSpawnTimer = 100 +(rand() % 60);
        }
    }
    bool bulletHiFighter(Entity*b) {
        for (Entity*fighter : fighters) {
            if (fighter->side != b->side && b->collision(fighter)) {
                fighter->health = 0;
               if(fighter != &player) {
                    score++;
                    highscore = max(score,highscore);
               }
                return true;
            }
        }
        return false;
    }
    void doLogic(int keyboard[],Graphics &graphics) {
        doBackground();
        doPlayer(keyboard,graphics);
        doFighters();
        doBullets();
        doMonster();
        spawnMonsters();
         if (player.health == 0 && --stageResetTimer <= 0) {
                graphics.playtime = LOSE;
                reset();
         }
    }
    void calcSlope(int x1, int y1, int x2, int y2, double *dx, double *dy)
{
	int steps = max(abs(x1 - x2), abs(y1 - y2));

	if (steps == 0)
	{
		*dx = *dy = 0;
		return;
	}

	*dx = (x1 - x2);
	*dx /= steps;

	*dy = (y1 - y2);
	*dy /= steps;
}
    void fireMonsterBullet(Entity*monster) {
        Entity *fire = new Entity();
        bullets.push_back(fire);

        fire->x = monster->x - 40;
        fire->y = monster->y;
        fire->health = 1;
        fire->texture = fireTexture;
        fire->side = SIDE_MONSTER;
        SDL_QueryTexture(fireTexture,NULL,NULL,&fire->w,&fire->h);
        calcSlope(player.x + (player.w / 2), player.y + (player.h / 2),
                  monster->x, monster->y, &fire->dx, &fire->dy);
        fire->dx *= MONSTER_BULLET_SPEED;
        fire->dy *= MONSTER_BULLET_SPEED;
        fire->dx = -MONSTER_BULLET_SPEED;
        monster->reload = (rand() % FRAME_PER_SECOND * 2);
    }
    void doMonster() {
        for (Entity*e : fighters) {
            if (e != &player && e ->health != 0 && --e->reload <=0) fireMonsterBullet(e);
        }
    }
    void drawText(Graphics&graphics) {
        string scoreText = "Score:" +to_string(score);
        scoreTexture = graphics.renderText(scoreText.c_str(),font,COLOR);
        graphics.renderTexture(scoreTexture,0,0);
        string highScoreText = "High Score:" + to_string(highscore);
        highScoreTexture = graphics.renderText(highScoreText.c_str(),font,COLOR);
        graphics.renderTexture(highScoreTexture,SCREEN_WIDTH - 400,0);
    }
    void draw(Graphics& graphics) {
    drawBackground(graphics.renderer);

    for (Entity*b : fighters) {
            if (b != &player)  {
            b->tick(10);
            graphics.render(b->x,b->y,*b);}
          else {
            if (b->health > 0) {
                b->tick(1);
            graphics.render(b->x,b->y,*b);}
            else {
                    graphics.renderTexture(deadTexture,b->x,b->y);
                    graphics.play(failgame);
            }
        }
    }
    for (Entity*b : bullets) {
            graphics.renderTexture(b->texture,b->x,b->y);
    }
    drawText(graphics);
    }
};
#endif // _LOGIC__H
