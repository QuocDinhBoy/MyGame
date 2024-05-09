#include <bits/stdc++.h>
using namespace std;
int dequy(int n,int a[]) {
    int Max = 0;
    for (int i = 1;i <= n;i++) {
        int temp = a[i] + dequy(n-i,a);
        if (Max < temp) Max = temp;
    }
    return Max;
}
int main () {
    int n;
    cin >> n;
    int a[n+1];
    a[0] = 0;
    for (int i = 1;i <= n;i++) {
            cin >> a[i];
    }
    cout << dequy(n,a);
}
