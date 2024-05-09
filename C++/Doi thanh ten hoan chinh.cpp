#include <bits/stdc++.h>
using namespace std;
int main () {
	string s;
	getline(cin,s);
	if (s[0] != 32) s[0] -= 32;
	for (unsigned int i = 1;i < s.size();i++) {
		if (s[i-1] == 32) {
			if (s[i] >= 'a' && s[i] <= 'z') {
		 	s[i] -=32;
		 }
		}	
	}
	for (unsigned int i = 0;i < s.size();i++) {
		if (s[i] == 32) s[i] -= 32;
	}
	for (unsigned int i = 0;i < s.size();i++) {
		if (s[i] == 0) s.erase(s.begin() + i);
	}
	cout << s.size();
//	for (unsigned int i = 1;i < s.size();i++) {
//		if (s[i] >= 'A' && s[i] <= 'Z') {
//			s.insert(s.begin() + i,' ');
//		}
//	}
	cout << s;
	return 0;
}
