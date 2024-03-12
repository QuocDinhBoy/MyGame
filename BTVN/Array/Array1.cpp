#include <bits/stdc++.h>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	bool seen = false;
	int check[n+1];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		check[i] = 0;
	}
	for (int i = 0; i < n;i++) {
		check[a[i]]++;
		if (check[a[i]] != 1) {
			seen = true;
			break;
		}
	}
	if (seen == true) cout <<"Yes";
	else if (seen == false) cout <<"No";
}
