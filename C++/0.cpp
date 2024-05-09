#include<bits/stdc++.h>
using namespace std;

void sieve(int l, int r){
	int a[r-l+1];
	for(int i = 0; i <= r-l; i++){
		a[i] = 1;
	}
	for(int i = 2; i <= sqrt(r); i++){
		for(int j = max(i*i, (l+i-1)/i*i); j <= r; j+=i){
			a[j-l] = 0;
		}
	}
	int cnt = 0;
	for(int i = max(l, 2); i <= r; i++){
		if(a[i-l])
		cnt++;
	}
	cout << cnt;
}
int main(){
	int m,n;
	cin>>m>>n;
	sieve(m, n);
	return 0;
}
