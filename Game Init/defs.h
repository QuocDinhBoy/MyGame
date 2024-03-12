#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED
#define SIDE_PLAYER 0
#define PLAYER_RELOAD 8
#define FRAME_PER_SECOND 60
#define BG_COLOR_R 96
#define BG_COLOR_G 128
#define BG_COLOR_B 255
#define BG_COLOR_A 255

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Init";
const int PLAYER_SPEED = 4;
const int PLAYER_BULLET_SPEED = 16;
const int MAX_KEYBOARD_KEYS = 350;
const int MAN_CLIPS[][4] = {
    {  0, 0, 64, 64},
    { 64, 0, 64, 64},
    {128, 0, 64, 64},
    {192, 0, 64, 64}};
const int MAN_FRAMES = sizeof(MAN_CLIPS)/sizeof(int)/4;
#endif // DEFS_H_INCLUDED
