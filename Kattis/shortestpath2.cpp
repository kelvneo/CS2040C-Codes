#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int ,int> iiii;  // destination, min takeoff, interval, cost
typedef vector<iiii> viiii;

int main() {
    int n, m, q, s, u, v, t, p, d, dest;
    while (cin >> n >> m >> q >> s, n > 0 || m > 0 || q > 0 || s > 0) {
        vector<viiii> AL;
        AL.assign(n, viiii());
        while (m--) {
            cin >> u >> v >> t >> p >> d;
            AL[u].push_back(make_tuple(v, t, p ,d));
        }

        vector<int> visited;
        visited.assign(n, 1e9);
        visited[s] = 0;
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, s});
        while (!pq.empty()) {
            ii c = pq.top(); pq.pop();
            for (iiii &nb: AL[c.second]) {
                int nv = get<0>(nb), nt = get<1>(nb), np = get<2>(nb), nd = get<3>(nb);
                if (c.first <= nt && visited[nv] > (nt + nd)) {
                    int nw = nt + nd;
                    visited[nv] = nw;
                    pq.push({nw, nv});
                } else if (np > 0) {
                    int wt = np - ((c.first - nt) % np);
                    if (wt == np) wt = 0;
                    int nw = c.first + wt + nd;
                    if (visited[nv] > nw) {
                        visited[nv] = nw;
                        pq.push({nw, nv});
                    }
                }
            }
        }

        while (q--) {
            cin >> dest;
            if (visited[dest] == 1e9) cout << "Impossible" << endl;
            else cout << visited[dest] << endl;
        }
        cout << endl;
    }

    return 0;
}