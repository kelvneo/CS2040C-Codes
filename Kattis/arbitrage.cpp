#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, r, i1, i2;
    string raw, c1, c2, rr;
    while (cin >> c && c) {
        unordered_map<string, int> cid(c);
        double AM[c][c], d1, d2;
        memset(AM, 0, sizeof AM);
        
        for (int i = 0; i < c; i++) {
            cin >> raw;
            cid[raw] = i;
            AM[i][i] = 1.0;
        }

        cin >> r;
        while (r--) {
            cin >> c1 >> c2;
            getline(cin, raw, ':');
            istringstream iss(raw);
            iss >> d1;
            cin >> d2;
            i1 = cid[c1];
            i2 = cid[c2];
            AM[i1][i2] = max(AM[i1][i2], d2 / d1);
        }

        for (int k = 0; k < c; k++) {
            for (int i = 0; i < c; i++) {
                for (int j = 0; j < c; j++) {
                    AM[i][j] = max(AM[i][j], AM[i][k] * AM[k][j]);
                }
            }
        }

        bool ok = true;
        for (int i = 0; i < c; i++) {
            if (AM[i][i] > 1.0) {
                ok = false;
            }
        }

        if (ok) cout << "Ok" << endl;
        else cout << "Arbitrage" << endl;
    }
}