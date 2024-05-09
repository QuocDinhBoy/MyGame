#include <bits/stdc++.h>

using namespace std;

void generatePasswords(int n, string s, string currentPassword = "") {
    if (n == 0) {
        cout << currentPassword << endl;
        return;
    }
    sort(s.begin(),s.end());
    for (char c : s) {
        string newPassword = currentPassword + c;
        generatePasswords(n - 1, s, newPassword);
    }
}

int main() {
    int n;
    string characters;

    cin >> n;
    cin >> characters;
    for (int i = 1;i <= n;i++) {
    generatePasswords(i, characters);
    }
    return 0;
}
