#include <bits/stdc++.h>
using namespace std;
bool isIsomorphic(string a, string b) {
	for (unsigned int i = 0; i < a.length();i++) {
		for (unsigned int j = 0; j < b.length();j++) {
			if (a[i] == a[j] ||b[i] == b[j]) {
				if (a[i] - b[i] != a[j] - b[j]) {
					return false;
				}
			} 
		}
	}
	return true;
}
int main () {
	string a,b;
	cin >> a >> b;
	cout << isIsomorphic(a,b);
}
