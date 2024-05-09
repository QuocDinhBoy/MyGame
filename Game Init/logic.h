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
#include <cmath>
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
    list<Entity*> balls;
    int score,highscore = 0;
    int backgroundX = 0;
    int monsterSpawnTimer;
    int startTime;
    int stageResetTimer;
    int batSpawnTimer;
    int ballSpawnTimer;
    double angle = 45 * M_PI / 180;
    TTF_Font* font;
    Mix_Music* gMusic;
    Mix_Chunk* lasergun,*failgame;
    SDL_Texture*background,*bulletTexture,*monsterTexture,*monsterHurtTexture,*fireTexture,*deadTexture,*scoreTexture,*highScoreTexture,
    *batTexture,*laserTexture,*batDeadTexture,*ballTexture;
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
        empty(balls);
    fighters.push_back(&player);
    initPlayer(player);
    monsterSpawnTimer = 0;
    score = 0;
    stageResetTimer = FRAME_PER_SECOND *3;
    batSpawnTimer = FRAME_PER_SECOND*25;
    ballSpawnTimer = FRAME_PER_SECOND*35;
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
        batTexture = graphics.loadTexture("image/FLYING.png");
        laserTexture = graphics.loadTexture("image/Laser_sheet.png");
        batDeadTexture = graphics.loadTexture("image/DEATH.png");
        gMusic = graphics.loadMusic("MusicSound/bgmusic.mp3");
        lasergun = graphics.loadSound("MusicSound/lasergun.wav");
        graphics.play(gMusic);
        failgame = graphics.loadSound("MusicSound/failgame.wav");
        font = graphics.loadFont("Font/GameFont7-vq2M.ttf",50);
        ballTexture = graphics.loadTexture("image/ball.png");
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
                if(fighter->type == MONSTER) {
                fighter->texture = monsterHurtTexture;
                fighter->init(monsterHurtTexture,MONSTER_HURT_FRAMES,MONSTER_HURT_CLIPS);}
                else {
                    fighter->texture = batDeadTexture;
                    fighter->init(batDeadTexture,BAT_DEAD_FRAMES,BAT_DEAD_CLIPS);
                }
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

    void spawnEnemies(void) {
        if(--monsterSpawnTimer <= 0) {
            Entity*monster = new Entity();
            fighters.push_back(monster);
            monster->x = SCREEN_WIDTH;
            monster->y = 10 + rand()%(SCREEN_HEIGHT - 64);
            monster->dx = -(2 +(rand()%2));
            monster->health = 1;
            monster->type = MONSTER;
            monster->side = SIDE_MONSTER;
            monster->texture = monsterTexture;
            monster->reload = FRAME_PER_SECOND * (1 + (rand() % 3));
            SDL_QueryTexture(monster->texture, NULL, NULL, &monster->w, &monster->h);
            monster->init(monsterTexture,MONSTER_FRAMES,MONSTER_CLIPS);
            monsterSpawnTimer = 100 +(rand() % 60);
        }
            if(--batSpawnTimer <= 0) {
            Entity*bat = new Entity();
            fighters.push_back(bat);
            bat->x = SCREEN_WIDTH;
            bat->y = 10 + rand()%(SCREEN_HEIGHT - 64);
            bat->dx = -(2 +(rand()%2));
            bat->health = 1;
            bat->type = BAT;
            bat->side = SIDE_MONSTER;
            bat->texture = batTexture;
            bat->reload = FRAME_PER_SECOND * (1 + (rand() % 3));
            SDL_QueryTexture(bat->texture, NULL, NULL, &bat->w, &bat->h);
            bat->init(batTexture,BAT_FRAMES,BAT_CLIPS);
            batSpawnTimer = 240 + (rand() % 120);
            }
    }
 void Balls(void) {
        if (--ballSpawnTimer <= 0) {
            Entity*ball = new Entity();
            balls.push_back(ball);
            ball->x = SCREEN_WIDTH - 50;
            ball->y = rand()%(SCREEN_HEIGHT - 50);
            ball->dx = 4*cos(angle);
            ball->dy = 4*sin(angle);
            ball->texture = ballTexture;
            SDL_QueryTexture(ball->texture, NULL, NULL, &ball->w, &ball->h);
            ballSpawnTimer = FRAME_PER_SECOND*30;
        }
    }

 void doBalls(void) {
        auto it = balls.begin();
        while(it != balls.end()) {
            auto temp = it++;
            Entity*b = *temp;
            b->move();
            if(b->collision(&player)) player.health = 0;
            if (++ b->time >= FRAME_PER_SECOND*20 || b->collision(&player)) {
                delete b;
                balls.erase(temp);
            }
            if (b->y + 50 >= SCREEN_HEIGHT || b->y <= 0) b->dy = -b->dy;
            if (b->x + 50 >= SCREEN_WIDTH || b->x <= 0) b->dx = -b->dx;
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
        Balls();
        doFighters();
        doBullets();
        doMonster();
        spawnEnemies();
        doBalls();
         if (player.health == 0 && --stageResetTimer <= 0) {
                graphics.playtime = LOSE;
                reset();
         }
    }

    void calcSlope(int x1, int y1, int x2, int y2, double *dx, double *dy){

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
        fire->type = 0;
        fire->texture = fireTexture;
        fire->side = SIDE_MONSTER;
        SDL_QueryTexture(fireTexture,NULL,NULL,&fire->w,&fire->h);
        calcSlope(player.x + (player.w / 2), player.y + (player.h / 2),
                  monster->x, monster->y, &fire->dx, &fire->dy);
        fire->dx *= MONSTER_BULLET_SPEED;
        fire->dy *= MONSTER_BULLET_SPEED;
        monster->reload = (rand() % FRAME_PER_SECOND * 2);
    }

    void LaserBat(Entity*bat) {
        Entity *laser = new Entity();
        bullets.push_back(laser);
        laser->x = bat->x - 260;
        laser->y = bat->y + 10;
        laser->health = 1;
        laser->type = 1;
        laser->texture = laserTexture;
        laser->side = SIDE_MONSTER;
        SDL_QueryTexture(fireTexture,NULL,NULL,&laser->w,&laser->h);
        laser->dx = bat->dx;
        laser->dy = bat->dy;
        bat->reload = FRAME_PER_SECOND * 10;
        laser->init(laser->texture,LASER_FRAMES,LASER_CLIPS);
    }

    void doMonster() {
        for (Entity*e : fighters) {
            if (e != &player && e ->health != 0 && --e->reload <=0) {
                if (e->type == 0) fireMonsterBullet(e);
                if(e->type == 1) LaserBat(e);}
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
           if (b->type == 0) graphics.renderTexture(b->texture,b->x,b->y);
           else {
                b->tick(20);
                graphics.render(b->x,b->y,*b);}
    }
    drawText(graphics);
    for (Entity*b : balls) graphics.renderTexture(b->texture,b->x,b->y);
    }
};
#endif // _LOGIC__H
