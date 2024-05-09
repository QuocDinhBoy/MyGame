#include <bits/stdc++.h>
using namespace std;
bool isValid (string s) {
    if (s.length() % 2 == 1) return false;
    int n = s.length();
    int dem[n];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
        if (s[i] == 40) {
            if (s[j] == 41) dem[i] = abs(i - j);
        }
        if (s[i] == 91) {
            if (s[j] == 93) dem[i] = abs(i - j);
        }   
        if (s[i] == 123) {
            if (s[j] == 125) dem[i] = abs(i - j);
        }
        if (s[i] == 41) {
            if (s[j] == 40) dem[i] = abs(i - j);
        }
        if (s[i] == 93) {
            if (s[j] == 91) dem[i] = abs(i - j);
        }
        if (s[i] == 125) {
            if (s[j] == 123) dem[i] = abs(i - j);
    }
        }
    }
    for (int i = 0 ; i < n;i++) {
        if (dem[0] % 2 == 0) {
            if (dem[i] % 2 == 1) return false;
        }
        else {
            if (dem[i] % 2 == 0) return false;
        }
    }
    return true;
}
int main () {
	string s;
	cin >> s;
	cout << isValid(s);
}
