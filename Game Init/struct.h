#ifndef _STRUCT__H
#define _STRUCT__H

#include <SDL.h>
#include "graphics.h"
using namespace std;
struct Entity {
    int x;
    int y;
    int w;
    int h;
    double dx;
    double dy;
    int reload;
    int side;
    int health;
    SDL_Texture *texture;
    bool collides(Entity* other) {
	    return (max(x, other->x) < min(x + w, other->x + other->w))
	        && (max(y, other->y) < min(y + h, other->y + other->h));
	}
    bool offScreen() {
	     return x < -w || y < -h || x > SCREEN_WIDTH || y > SCREEN_HEIGHT;
	}
	void move() {
        x += dx;
        y += dy;
	}
};
struct App {
    int keyboard[MAX_KEYBOARD_KEYS];
};
#endif // _STRUCT__H
