#include <bits/stdc++.h>
using namespace std;
bool areAnagrams(string str1, string str2) {
	int a[200];
	for (int i = 0;i < 200;i++) {
		a[i] = 0;	
	}
	for (unsigned int i = 0;i <= str1.length();i++) {
		if((int)str1[i] >= 65 && (int)str1[i] <= 90) 
		a[(int)str1[i] + 32]++;
		else a[(int)str1[i]]++;
	}
	for (unsigned int i = 0;i <= str2.length();i++) {
		if((int)str2[i] >= 65 && (int)str2[i] <= 90) 
		a[(int)str2[i] + 32]--;
		else a[(int)str2[i]]--;
	}
	for (int i =97;i <= 122;i++) {
		if (a[i] != 0) return false;
	}
return true;
}
int main () {
	string str1,str2;
	cin >> str1 >> str2;
	if(areAnagrams(str1,str2)) cout <<"True";
	else cout <<"False";
	return 0;	
}
