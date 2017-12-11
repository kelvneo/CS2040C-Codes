#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    int n, m, q, s, u, v, w, t;
    while ((cin >> n >> m >> q >> s) && !(n == 0 && m == 0 && q == 0 && s == 0)) {
        vector<vii> AL(n, vii());
        while (m--) {
            cin >> u >> v >> w;
            AL[u].emplace_back(v, w);
        }

        vector<int> dist(n, 1 << 30);
        dist[s] = 0;
        set<ii> pq; pq.insert({0, s});
        while (!pq.empty()) {
            ii cur = *pq.begin(); pq.erase(pq.begin());
            for (auto &N: AL[cur.second]) {
                int nw = cur.first + N.second;
                if (nw < dist[N.first]) {
                    pq.insert({nw, N.first});
                    dist[N.first] = nw;
                }
            }
        }

        while (q--) {
            cin >> t;
            if (dist[t] == (1 << 30)) {
                cout << "Impossible" << endl;                
            } else {
                cout << dist[t] << endl;
            }
        }
    }
    return 0;
}