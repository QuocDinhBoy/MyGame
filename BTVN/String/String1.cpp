#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long a[N];
    set<long long> lib;

    for (auto& x : a) {
        cin >> x;
        lib.insert(x);
    }

    if (lib.size() == N) cout << "Yes";
    else cout << "No";

    return 0;
}
