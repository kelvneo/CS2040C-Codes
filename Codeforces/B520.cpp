#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n >> m;
    int m2 = m << 1;
    int mu2 = m >> 2;
    queue<pair<int, int>> bfs;
    unordered_set<int> visited;
    bfs.push({n, ans});
    while (!bfs.empty()) {
        pair<int, int> top = bfs.front();
        visited.insert(top.first);
        bfs.pop();
        if (top.first == m) {
            cout << top.second << endl;
            break;
        } else {
            if (top.first << 1 < m2 && visited.find(top.first << 1) == visited.end())
                bfs.push({top.first << 1, top.second + 1});
            if (visited.find(top.first - 1) == visited.end())
                bfs.push({top.first - 1, top.second + 1});
        }
    }
}