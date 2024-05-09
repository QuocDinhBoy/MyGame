#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main() {
    int Q,y,x;
    cin >> Q;
    set <int> s;
    for (int i = 0;i < Q;i++) {
            cin >> y >> x;
        switch(y) {
        case 1: s.insert(x);
        break;
        case 2: s.erase(x);
        break;
        case 3: {
            auto it = s.find(x);
            if (it == s.end()) cout <<"No" << endl;
            else cout <<"Yes"<< endl;
        }
        break;
        }
    }
    return 0;
}



