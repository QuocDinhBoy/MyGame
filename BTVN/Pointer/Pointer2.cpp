#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    double a[n];
    for (auto& x : a) cin >> x;

    double avg = 0, ps = 0;
    for (auto x : a) avg += x;
    avg /= n;

    for (auto x : a) {
        ps += ((x - avg)*(x - avg));
    }
    ps /= n;

    cout << avg << endl << ps;

    return 0;
}
