#include <bits/stdc++.h>
using namespace std;
struct Point {
    double x, y;
};

void print(Point p) {
    cout << p.x << " " << p.y;
}
Point mid_point(const Point&a,const Point&b) {
    Point c;
    c.x = (a.x + b.x)/2;
    c.y = (a.y + b.y)/2;
    return c;
}
int main (){
   Point a,b,c;
   cin >> a.x >> a.y >> b.x >> b.y;
   c = mid_point(a,b);
   cout << c.x << " "<< c.y;
}
