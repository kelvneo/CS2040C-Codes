#include <bits/stdc++.h>
using namespace std;

int main() {
    int C, c = 0, n, l, j, k, possible = 1;
    cin >> C >> n;
    for (int i = 0; i < n; i++) {
        cin >> l >> j >> k;
        if (l > c) possible = 0;
        c -= l;
        if (c + j > C) possible = 0;
        c += j;
        if (k != 0 && c != C) possible = 0;
    }
    if (possible && c == 0 && j == 0 && k == 0) cout << "possible" << endl;
    else cout << "impossible" << endl;
    return 0;
}