#ifndef _STRUCT__H
#define _STRUCT__H

#include <SDL.h>
#include "graphics.h"
#include <vector>
using namespace std;
struct Entity {
    Uint32 deathTime;
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
    vector<SDL_Rect> clips;
    int currentFrame = 0;
    int frameTime = 0;
    void init(SDL_Texture* _texture, int frames, const int _clips [][4]) {
        texture = _texture;
        SDL_Rect clip;
        for (int i = 0; i < frames; i++) {
            clip.x = _clips[i][0];
            clip.y = _clips[i][1];
            clip.w = _clips[i][2];
            clip.h = _clips[i][3];
            clips.push_back(clip);
        }
    }
    void tick(int delay) {
        frameTime++;
        if(frameTime == delay) {
                frameTime = 0;
                currentFrame = (currentFrame + 1) % clips.size();
        }
    }
    const SDL_Rect* getCurrentClip() const {
        return &(clips[currentFrame]);
    }
    bool offScreen() {
	     return x < -w || x > SCREEN_WIDTH || y > SCREEN_HEIGHT;
	}
	void move() {
        x += dx;
        y += dy;
	}
	bool collision(Entity* other) {
	    return (max(x, other->x) < min(x + w, other->x + other->w/2 - 20))
	        && (max(y, other->y) < min(y + h, other->y + other->h - 40));
	}
};

#endif // _STRUCT__H
