#include <bits/stdc++.h>
using namespace std;
int main () {
	long long a[2][4];
	long long b,c,d,e;
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 4;j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0;i < 2;i++) {
		if (a[i][0] > a[i][2]) swap(a[i][0],a[i][2]);
		if (a[i][1] > a[i][3]) swap(a[i][1],a[i][3]);
}
	if ((a[0][0] < a[1][0] && a[0][3] < a[1][3]) ||(a[0][0] > a[1][0] && a[0][3] > a[1][3])) cout << 0;
	else {
	if (a[0][0] > a[1][0]) b = a[0][0];
	else b = a[1][0];
	if (a[0][1] > a[1][1]) c = a[0][1];
	else c = a[1][1];
	if (a[0][2] < a[1][2]) d = a[0][2];
	else d = a[1][2];
	if (a[0][3] < a[1][3]) e = a[0][3];
	else e = a[1][3];
	long long S;
	S = (d - b)*(e - c);
	cout << S;}
}

