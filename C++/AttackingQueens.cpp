#include <bits/stdc++.h>
using namespace std;
bool isAttackingQueens(const vector<pair<int,int>> & queens) {
    for (int i = 0;i < queens.size();i++) {
        for (int j = i + 1;j < queens.size();j++) {
            if (queens[i].first == queens[j].first || queens[i].second == queens[j].second ||
                abs(queens[i].first - queens[j].first) == abs(queens[i].second - queens[j].second))
                return true;
            }
        }
    return false;
}
int main () {
    int n;
    cin >> n;
    vector <pair<int,int>> queens(n);
    for (int i = 0;i < n;i++) {
        int x,y;
        cin >> x >> y;
        queens[i] = make_pair(x,y);
    }
    if (isAttackingQueens(queens)) {
        cout <<"YES" <<endl;
    }
    else cout <<"NO"<< endl;
}
