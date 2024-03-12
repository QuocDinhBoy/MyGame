#include <bits/stdc++.h>
using namespace std;
bool sodoiguong(int n) {
	vector <int> a;
	while (n > 0) {
		a.push_back(n%10);
		n/=10;
	}
	int l = 0;
	int r = a.size() - 1;
	while (r >= 0) {
		if (a[l] != a[r]) {
			return false;
			break;
		}
		l++;
		r--;
	}
	return true;
}
int main () {
	int n;
	cin >> n;
	int dem[n];
	int a[n][2];
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < 2;j++) {
			cin >> a[i][j];
		}
		dem[i] = 0;
	}
	for (int i = 0;i < n;i++) {
		for (int j = a[i][0];j <= a[i][1];j++) {
			if (sodoiguong(j)) dem[i]++;
		}
	}
	for (int i = 0;i < n;i++) {
		cout << dem[i] << endl;
	}
}
