#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n, m, r, u, v, CC = 0;
vector<vi> al;
vi visited;

void dfs(int u) {
    if (visited[u] == 0) {
        visited[u] = 1;
        for (int i: al[u])
            dfs(i);
    }
}

int main() {
    cin >> n;
    while (n--) {
        cin >> m >> r;
        al.assign(m, vi());
        visited.assign(m, 0);
        while (r--) {
            cin >> u >> v;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        for (int i = 0; i < m; i++) {
            if (visited[i] == 0) {
                CC++;
                dfs(i);
            }
        }
        cout << (CC - 1) << endl;
        CC = 0;
    }
    return 0;
}