#include <bits/stdc++.h>
using namespace std;
int main () {
    int n,m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> a[i][j];
        }
    }
    int dem = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (i == 0 && j == 0) {
                if (a[i+1][j] < a[i][j] && a[i][j+1] < a[i][j]) dem++;
            }
            else if (i == n && j == 0) {
                if (a[i-1][j] < a[i][j] && a[i][j+1] < a[i][j]) dem++;
            }
            else if (i == 0 && j == m - 1) {
                if (a[i+1][j] < a[i][j] && a[i][j-1] < a[i][j]) dem++;
            }
            else if (i == n - 1 && j == m - 1) {
                if (a[i-1][j] < a[i][j] && a[i][j-1] < a[i][j]) dem++;
            }
            else if (i == 0) {
                if (a[i][j-1] < a[i][j] && a[i][j+1] < a[i][j] && a[i+1][j] < a[i][j]) dem++;
            }
            else if (i == n - 1) {
                if (a[i][j-1] < a[i][j] && a[i][j+1] < a[i][j] && a[i-1][j] < a[i][j]) dem++;
            }
            else if (j == 0) {
                if (a[i-1][j] < a[i][j] && a[i+1][j] < a[i][j] && a[i][j+1] < a[i][j]) dem++;
            }
            else if (j == m - 1) {
                 if (a[i-1][j] < a[i][j] && a[i+1][j] < a[i][j] && a[i][j-1] < a[i][j]) dem++;
            }
            else {
                if (a[i-1][j] < a[i][j] && a[i+1][j] < a[i][j] && a[i][j-1] < a[i][j] && a[i][j+1] < a[i][j]) dem++;
            }
        }
    }
    cout << dem;
}
