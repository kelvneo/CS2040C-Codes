#include <bits/stdc++.h>
using namespace std;

// Qualifying Contest
int main() {
    int n, m, r, s;
    cin >> n >> m;
    vector<pair<int, string>> d[m];
    string name;
    while (n--) {
        cin >> name >> r >> s;
        d[r - 1].push_back({s, name});
    }
    for (int i = 0; i < m; i++) {
        sort(d[i].begin(), d[i].end(), greater<pair<int, string>>());
        auto a = d[i][0];
        auto b = d[i][1];
        if (d[i].size() > 2 && b.first == d[i][2].first) {
            cout << "?" << endl;
        }
        else cout << a.second << ' ' << b.second << endl;
    }
    return 0;
}