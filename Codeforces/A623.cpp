#include <bits/stdc++.h>
using namespace std;

vector<int> data[505];

int dfs(bool visited[], int v) {
    if (data[v].empty()) return 1;
    else {
        int d = 1;
        visited[v] = true;
        for (auto a: data[v]) {
            if (!visited[a])
                d = max(d, dfs(visited, a) + 1);
        }
        return d;
    }
}

// Graph and String
int main() {
    int n, m, u, v, mx = 0;
    cin >> n >> m;
    string c = string(n, 'c');
    while (m--) {
        cin >> u >> v;
        data[u - 1].push_back(v - 1);
        data[v - 1].push_back(u - 1);
    }
    for (int i = 0; i < n; i++) {
        bool visited[505] = {0};
        if (data[i].size() == n - 1) c[i] = 'b';
        else if (data[i].size() == 1) c[i] = 'a';
        if (mx != n)
            mx = max(mx, dfs(visited, i));
    }
    if (mx == n) {
        cout << "Yes" << endl;
        cout << c << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}