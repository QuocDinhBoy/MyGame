
#include <bits/stdc++.h>

using namespace std;

void test(string S) {
    int l = S.size();
    for (int i = 0; i < l; i++) {
        if (S[i] != S[l-1-i]) {
            cout << "No";
            break;
        }
        if (i == int(l/2)) {
            cout << "Yes";
            break;
        }
    }
}

int main()
{
    string k; cin >> k;
    test(k);
    return 0;
}
