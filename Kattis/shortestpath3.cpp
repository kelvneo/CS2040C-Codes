#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
typedef tuple<int, int, int> iii;

int main() {
    int n, m, q, s, u, v, w, t;
    while (cin >> n >> m >> q >> s, n > 0 || m > 0 || q > 0 || s > 0) {
        vector<int> dist;
        dist.assign(n, INF);
        dist[s] = 0;

        vector<iii> EL;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            EL.push_back(make_tuple(u, v, w));
        }

        for (int i = 1; i < n; i++) {
            for (auto &a: EL) {
                u = get<0>(a), v = get<1>(a), w = get<2>(a);
                if (dist[u] != INF && dist[v] > dist[u] + w) dist[v] = dist[u] + w;
            }
        }

        for (int i = 1; i < n; i++) {
            for (auto &a: EL) {
                u = get<0>(a), v = get<1>(a), w = get<2>(a);
                if (dist[u] == -INF) dist[v] = -INF;
                else if (dist[u] != INF && dist[u] + w < dist[v]) dist[v] = -INF;
            }
        }

        while (q--) {
            cin >> t;
            if (dist[t] == -INF) cout << "-Infinity" << endl;
            else if (dist[t] == INF) cout << "Impossible" << endl;
            else cout << dist[t] << endl;
        }
        cout << endl;
    }
    return 0;
}