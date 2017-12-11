#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

int main() {
    int n, m, t, a, b, d;
    cin >> n;
    vector<vii> AL;
    vector<int> tn;
    AL.assign(n, vii());

    for (int i = 0; i < n; i++) {
        cin >> t;
        tn.push_back(t);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        AL[--a].push_back({--b, d});
        AL[b].push_back({a, d});
    }

    auto comp = [] (iii &a, iii &b) { return get<0>(a) == get<0>(b) ? get<1>(a) < get<1>(b) : get<0>(a) > get<0>(b); };
    priority_queue<iii, viii, decltype(comp)> pq(comp);
    pq.push(make_tuple(0, tn[0], 0));
    vii visited;
    visited.assign(n, {INF, 0});
    visited[0] = {0, tn[0]};
    int dest = n - 1;
    while (!pq.empty()) {
        iii cur = pq.top(); pq.pop();
        int cw = get<0>(cur), cf = get<1>(cur), cn = get<2>(cur);
        if (cn == dest) break;
        for (auto &a: AL[cn]) {
            int nw = cw + a.second, nn = a.first, nf = tn[nn] + cf;
            if (visited[nn].first > nw || (visited[nn].first == nw && nf > visited[nn].second)) {
                visited[nn] = {nw, nf};
                pq.push(make_tuple(nw, nf, nn));
            }
        }
    }

    if (visited[dest].first == INF) cout << "impossible" << endl;
    else cout << visited[dest].first << " " << visited[dest].second << endl;

    return 0;
}