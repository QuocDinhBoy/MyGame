#include <bits/stdc++.h>
using namespace std;
struct Point  {
    double x,y;
};
struct Rect {
    double x,y,w,h;
    bool contains(Point p) {
    if (p.x >= x && p.x <= x + h && p.y >= y && p.y <= p.y + h) return true;
    return false;
}
};
int main () {
    Point point;
    Rect rect;
    cin >> rect.x >> rect.y >> rect.w >> rect.h >> point.x >> point.y;
    if(rect.contains(point)) cout <<"True";
    else cout <<"False";
    return 0;
}
