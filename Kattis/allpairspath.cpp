#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main() {
    int n, m, q, u, v, w;
    while (cin >> n >> m >> q, n > 0 || m > 0 || q > 0) {
        int AM[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                AM[i][j] = INF;
            }
            AM[i][i] = 0;
        }
        while (m--) {
            cin >> u >> v >> w;
            AM[u][v] = min(AM[u][v], w);
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (AM[i][k] != INF && AM[k][j] != INF)
                        AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
                }
            }
        }
        while (q--) {
            cin >> u >> v;
            int w = AM[u][v];
            for (int i = 0; i < n; i++) {
                if (AM[u][i] != INF && AM[i][v] != INF && AM[i][i] < 0) {
                    w = -INF;
                    break;
                }
            }
            if (w == INF) cout << "Impossible" << endl;
            else if (w == -INF) cout << "-Infinity" << endl;
            else cout << w << endl;
        }
        cout << endl;
    }
    return 0;
}