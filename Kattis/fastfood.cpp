#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
    int t, n, m, k, l, j;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        unsigned long ans = 0;
        vector<int> types, mincount, prizes;
        types.assign(m, -1);
        mincount.assign(n, 1 << 30);
        prizes.assign(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> k;
            for (j = 0; j < k; j++) {
                cin >> l;
                types[l - 1] = i;
            }
            cin >> l;
            prizes[i] = l;
        }

        for (int i = 0; i < m; i++) {
            cin >> j;
            if (types[i] > -1 && mincount[types[i]] > j) {
                mincount[types[i]] = j;
            }
        }

        for (int i = 0; i < n; i++) {
            if (mincount[i] < (1 << 30)) {
                ans += (prizes[i] * mincount[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}