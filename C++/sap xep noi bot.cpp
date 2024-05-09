#include <bits/stdc++.h>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	for(int i = n - 1;i > 0;i--){
		bool swapped = false;
		for (int j = 1;j <= i;j++) {
			if (a[j-1] > a[j]) {
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}	
			swapped = true;
		if (!swapped) break;
		}
}
	for (int i = 0;i < n;i++) {
		cout << a[i] <<" ";
	}
	return 0;
}
