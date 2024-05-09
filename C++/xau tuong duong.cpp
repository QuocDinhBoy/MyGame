#include <bits/stdc++.h>
using namespace std;
int xautuongduong(string &s) {
	int b = 0;
	for (unsigned int i = 0;i < s.size();i++) {
		for (unsigned int j = 0;j < s.size();j++) {
			if (s[i] == s[j] && i != j) b++;
		}
	}
	return b;
}
int main() {
	int n;
	cin >> n;
	string a[n];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for (int i = 0;i < n;i++) {
		cout << xautuongduong(a[i]) << endl;
	}
}
