#include <bits/stdc++.h>
using namespace std;
int b[100001]
int main () {
    int n;
    cin >> n;
    int S = 0;
    int a[n];
    for (int i = 0;i < n;i++) {
    cin >> a[i];
    }
    b[0] = a[0]
    for (int i = 1;i < n;i++) {
        b[i] = b[i-1] + a[i];
    }
    for (int i = 0;i < n;i++) {
    cout << b[i] << " ";}
}
