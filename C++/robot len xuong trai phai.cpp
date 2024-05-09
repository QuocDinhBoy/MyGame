#include <bits/stdc++.h>
using namespace std;
bool circle (string moves) {
	int k = 0;
	for (unsigned int i = 0;i < moves.length();i++) {
		if (moves[i] == 76 || moves[i] == 85) k++;
		else k--;
	}
	if (k == 0) return true;
	else return false;
}
int main () {
	string moves;
	cin >> moves;
	cout << circle(moves);
}
