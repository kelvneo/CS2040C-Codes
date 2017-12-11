#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
// typedef tuple<int, int, int> iii;
typedef vector<ii> vii;

int main() {
    int V, E, u, v, w, s, t, ans = 0;
    cin >> V >> E;
    vector<vii> AL;
    vector<int> dist;
    vector<int> paths;
    AL.assign(V, vii());
    dist.assign(V, 1000000000);
    paths.assign(V, 0);
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        AL[u].push_back({v, w});
    }
    cin >> s >> t;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    paths[s] = 1;
    dist[s] = 0;
    while (!pq.empty()) {
        ii n = pq.top(); pq.pop();
        if (n.second == t) break;
        for (ii &a: AL[n.second]) {
            int nw = n.first + a.second;
            if (nw < dist[a.first]) {
                paths[a.first] = paths[n.second];
                dist[a.first] = nw;
                pq.push({nw, a.first});
            } else if (nw == dist[a.first]) {
                paths[a.first] += paths[n.second];
            }
        }
    }
    cout << paths[t] << endl;
    return 0;
}