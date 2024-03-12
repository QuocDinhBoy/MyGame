#include <bits/stdc++.h>
using namespace std;
struct Rect {
    double x,y,w,h;
};
struct Ship {
    Rect rect;
    double dx,dy;
    string id;
    void move () {
        rect.x += dx;
        rect.y += dy;
    }
};
void display(const Ship&ship) {
    cout << ship.id << " " << ship.rect.x << " " << ship.rect.y << endl;
}
int main () {
    Ship ship1,ship2;
    cin >> ship1.id >> ship1.rect.x >> ship1.rect.y >> ship1.dx >> ship1.dy;
    cin >> ship2.id >> ship2.rect.x >> ship2.rect.y >> ship2.dx >> ship2.dy;
    int loop = 0;
    while (loop < 10) {
        ship1.move();ship2.move();
        display(ship1);display(ship2);
        loop++;
    }
    return 0;
}

