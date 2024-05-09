#include <bits/stdc++.h>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	int b[n];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for (int i = 0;i < n;i++) {
		if(b[i] == -1) continue;
		b[i] = 1;
		for (int j = 0;j < n;j++) {
			if (i != j && a[i] == a[j]) {
				b[i] ++;
				b[j] = -1;
			}
		}
	}
	for (int i = 0;i < n;i++) {
		if (b[i] != -1) cout << a[i] <<" "<<b[i]<< endl;
	}
	return 0;
}

