#include <bits/stdc++.h>
using namespace std;
string cipher (int k, string message) {
	for(unsigned int i = 0; i < message.length();i++) {
		if ((int)message[i] >= 65 && (int)message[i] <= 90) {
			if ((int)message[i] + k > 90) message[i] = 'A' + k - 91 + (int)message[i];
			else message[i] += k;
		}
		if ((int)message[i] >= 97 && (int)message[i] <= 122) {
			if ((int)message[i] + k > 122) message[i] = 'a' + k - 123 + (int)message[i];
			else message[i] += k;
		}
		if ((int)message[i] >= 48  && (int)message[i] <= 57) {
			if ((int)message[i] + k > 57) message[i] = '0' + k - 58 + (int)message[i];
			else message[i] += k;
		} 
	}
	return message;
}
int main () {
	string message;
	cin >> message;
	int k;
	cin >> k;
	cout << cipher (k,message);
}
