#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    int n, m, a, b;
    cin >> n >> m;

    vector<vi> AL;
    AL.assign(n, vi());
    set<int> unvisited;
    for (int i = 0; i < n; i++) unvisited.insert(i);

    while (m--) {
        cin >> a >> b;
        AL[a - 1].push_back(b - 1);
        AL[b - 1].push_back(a - 1);
    }

    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int c = q.front(); q.pop();
        unvisited.erase(c);
        for (int i: AL[c]) {
            if (unvisited.find(i) != unvisited.end()) q.push(i);
        }
    }

    if (unvisited.empty()) cout << "Connected" << endl;
    else for (int i: unvisited) cout << (i + 1) << endl;

    return 0;
}