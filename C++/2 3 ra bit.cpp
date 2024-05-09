#include <bits/stdc++.h>
using namespace std;
void printbits(int n,int a) {
	vector <int> b;
		while (a != 0) {
			b.push_back(a % 2);
			a/=2;
}
	vector <int> c;
	int l = b.size();
for (unsigned int i = 0;i < l/2;i++) {
	swap(b[i],b[l-1-i]);
}
while (b.size() < n) {
	b.insert(b.begin(),0);
}
for (int i = 0;i < n;i++) {
	cout << b[i];

}
}
int main () {
	int n;
	cin >> n;
	int a = 0;
	for (int i = 0;i < n;i++) {
		a += pow(2,i);
	}
	for (int i = 0;i <= a;i++) {
		printbits(n,i);
		cout << endl;
	}
}
