#include <bits/stdc++.h>
using namespace std;
vector<int> getCorrectResponse(vector<int> pin, vector<int> num) {
    vector <int> a;
    for (unsigned int i = 0;i < pin.size();i++) {
            a[i] = num[pin[i]];
        }
    return a;
}
int main () {
	vector<int> pin(5);
	vector<int> num(10);
	for (int i = 0;i < 5;i++) {
		cin >> pin[i];
}
	for (int i = 0;i < 10;i++) {
		cin >> num[i];
	}
	vector <int> b = getCorrectResponse(pin,num);
	for (int i = 0; i < b.size();i++) {
		cout << b[i];
	}
}
