#include <bits/stdc++.h>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (i == 0 && j == n/2) a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	for (int z = 2;z <= n*n;z++){
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (a[i][j] == z - 1) {
				if (i == 0) {
					if (j != n - 1) {
						a[n-1][j+1] = z;
					}
					else a[i+1][j] = z;
				}
				else {
					if (j != n - 1) {
						if (a[i-1][j+1] == 0) {
							a[i-1][j+1] = z;
						}
						else a[i+1][j] = z;
					}
					else a[i-1][0] = z; 
				}
				}
			}
		}
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << a[i][j] <<" ";
		}
		cout << endl;
	}
}
