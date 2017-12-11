#include <bits/stdc++.h>
using namespace std;

// Bakery
int main() {
    int n, m, k, u, v, l, s, ans = 1000000001;
    cin >> n >> m >> k;
    vector<pair<int, int>> d[n];
    set<int> storages;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> l;
        d[u - 1].push_back({v - 1, l});
        d[v - 1].push_back({u - 1, l});
    }
    while (k--) {
        cin >> s;
        storages.insert(s - 1);
    }
    for (auto a: storages) {
        for (auto b: d[a]) {
            if (b.second < ans && storages.find(b.first) == storages.end())
                ans = b.second;
        }
    }
    if (ans == 1000000001) cout << "-1" << endl;
    else cout << ans << endl;
    return 0;
}