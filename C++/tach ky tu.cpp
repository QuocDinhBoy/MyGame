#include <bits/stdc++.h>
using namespace std;
int main () {
	string s;
	getline (cin,s);
	map <char, int> a;
	int n = s.length();
	int dem[n];
	for (int i = 0;i < n;i++) {
		dem[i] = 0;
		if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (s[i] == s[j]) dem[i]++;
		}
	}
	for (int i = 0;i < n;i++) {
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) a.insert({s[i],dem[i]});
	}
	for (map <char, int> :: iterator it = a.begin(); it != a.end();it++) {
		cout << it->first <<" " << it->second << endl;
	}
}
