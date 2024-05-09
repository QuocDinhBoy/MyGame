#include <bits/stdc++.h>
using namespace std;
long long prime[1000001];
long long dem[1000001];
void sang() {
	dem[0] = 0;
	for (int i = 0; i <= 1000000;i++) {
		prime[i] = 1;
	}
	prime[0] = 0;prime [1] = 0;
	for (int i = 0;i <= sqrt(1000000);i++) {
		if (prime[i]) {
			for (int j = i*i;j <= 1000000;j += i) {
				prime[j] = 0;
			}
		}
	}
	for (int i = 0;i <= 1000000;i++) {
		if (prime[i]) dem[i] = dem[i - 1] + 1;
		else dem[i] = dem[i-1];
	}
}
int main () {
	sang();
	int n,l,r;
	cin >> n;
	while (n--) {
		cin >> l >> r;
		cout << dem[r] - dem[l-1];
	}
}

