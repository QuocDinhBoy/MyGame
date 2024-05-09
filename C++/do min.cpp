#include <bits/stdc++.h>
using namespace std;
int main () {
	int m,n;
	cin >> m >> n;
	char a[m][n];
	int dem[m][n];
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cin >> a[i][j];
			dem[i][j] = 0;
		}
	}
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (a[i][j] != '*') {
				if (a[i][j-1] == '*' && j - 1 >= 0) dem[i][j]++;
				if (a[i-1][j] == '*' && i - 1 >= 0) dem[i][j]++;
				if (a[i-1][j-1] == '*' && i - 1 >= 0 && j - 1 >= 0) dem[i][j]++;
				if (a[i+1][j] == '*' && i + 1 < m) dem[i][j]++;
				if (a[i][j+1] == '*' && j + 1 < n) dem[i][j]++;
				if (a[i+1][j+1] == '*' && i + 1 < m && j + 1 < n) dem[i][j]++;
				if (a[i-1][j+1] == '*' && i - 1 >= 0 && j + 1 < n) dem[i][j]++;
				if (a[i+1][j-1] == '*' && i + 1 < m && j - 1 >= 0) dem[i][j]++;
			}
		}
	}
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
		if (a[i][j] == '.') cout << dem[i][j] <<" ";
		else cout << a[i][j] << " ";
		}
		cout << endl;
	}
} 
