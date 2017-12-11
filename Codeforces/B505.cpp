#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> data[100];

int dfs(vector<int> &visited, int v, int end, int color) {
    // cout << " -> " << (v + 1) << '(' << color << ')';
    if (v == end) return 1;
    if (visited[v]) return 0;
    int ans = 0;
    visited[v] = 1;
    for (auto &a: data[v]) {
        if (a.second == color && dfs(visited, a.first, end, color)) return 1;
    }
    visited[v] = 2;
    // cout << " X";
    return 0;
}

int main() {
    int n, m, a, b, c, q, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        data[a - 1].push_back({b - 1, c - 1});
        data[b - 1].push_back({a - 1, c - 1});
    }
    cin >> q;
    while (q--) {
        cin >> u >> v;
        int ans = 0;
        for (int i = 0; i < m; i++) {
            vector<int> visited;
            visited.assign(n, 0);
            // cout << u;
            if (dfs(visited, u - 1, v - 1, i))
                ans ++;
            // cout << endl;
        }
        cout << ans << endl;
    }
    return 0;
}