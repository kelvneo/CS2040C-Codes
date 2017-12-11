#include <bits/stdc++.h>
using namespace std;

int main() {
    int f, s, g, u, d, b = 0;
    cin >> f >> s >> g >> u >> d;
    vector<int> visited(f + 1, -1);
    queue<int> q;
    visited[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == g) break;
        if (u > 0 && cur + u <= f && visited[cur + u] == -1) {
            visited[cur + u] = visited[cur] + 1;
            q.push(cur + u);
        }
        if (d > 0 && cur - d > 0 && visited[cur - d] == -1) {
            visited[cur - d] = visited[cur] + 1;
            q.push(cur - d);
        }
    }
    if (visited[g] != -1) cout << visited[g] << endl;
    else cout << "use the stairs" << endl;
}