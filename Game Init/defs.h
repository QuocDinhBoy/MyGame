#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED
#define SIDE_PLAYER 0
#define SIDE_MONSTER 1
#define PLAYER_RELOAD 32
#define FRAME_PER_SECOND 60
#define BG_COLOR_R 96
#define BG_COLOR_G 128
#define BG_COLOR_B 255
#define BG_COLOR_A 255
#define MONSTER_BULLET_SPEED 4
#define MENU 0
#define PLAY 1
#define LOSE 2
const SDL_Color COLOR = {0,0,0,0};
const int DELETE_DELAY_MS = 2000;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 700;
const char* WINDOW_TITLE = "Init";
const int PLAYER_SPEED = 4;

const int PLAYER_BULLET_SPEED = 16;
const int MAX_KEYBOARD_KEYS = 350;
const int FLY_CLIPS[][4] = {
    {  0, 0, 150,102},
    { 150, 0, 150, 102}};
const int FLY_FRAMES = sizeof(FLY_CLIPS)/sizeof(int)/4;
const int MONSTER_CLIPS[][4] = {
    {0,0,64,64},
    {64,0,64,64},
    {128,0,64,64},
    {192,0,64,64}};
const int MONSTER_FRAMES = sizeof(MONSTER_CLIPS)/sizeof(int)/4;
const int MONSTER_HURT_CLIPS[][4] = {
    {0,0,64,64},
    {64,0,64,64},
    {128,0,64,64},
    {192,0,64,64}};
const int MONSTER_HURT_FRAMES = sizeof(MONSTER_HURT_CLIPS)/sizeof(int)/4;
#endif // DEFS_H_INCLUDED
