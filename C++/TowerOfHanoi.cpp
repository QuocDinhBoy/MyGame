#include <bits/stdc++.h>
using namespace std;

long long TowerOfHanoi(int n) {
    if (n == 1) return 1;
    return 2*TowerOfHanoi(n-1) + 1;
}

int main() {
    int n,m;
    cin >> n >> m;
    cout << TowerOfHanoi(n);
}
