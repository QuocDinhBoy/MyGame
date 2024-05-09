#include <bits/stdc++.h>
using namespace std;
void printArrow(int n, bool left) {
	for (int i = 1;i < 2*n;i++) {
		if (left == false) {
			if (i <= n) {
			for (int j = 1;j <2*n;j++) {
			if (j > (i-1)*2 && j < n + i) cout <<"*";
			else cout <<" ";
		}
		cout << endl;
		} else {
		for (int j = 1;j <2*n;j++) {
			if(j >= 2*(2*n - i) - 1 && j < 3*n - i) cout <<"*";
			else cout <<" ";
		}
		cout << endl;
	}
}
		if (left == true) {
			for (int j = 1;j < 2*n;j++) {
				if (j > abs(i-n) && j <= 2*abs(i-n)+1) cout << "*";
				else cout << " ";
			}
		cout << endl;
		}
	}
}
int main () {
	int n;
	cin >> n;
	bool left;
	cin >> left;
	printArrow (n,left);
}
