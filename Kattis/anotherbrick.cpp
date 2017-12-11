#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, n, x, ans = 1;
    cin >> h >> w >> n;
    while (h--) {
        int tw = w;
        while (tw > 0) {
            cin >> x; n--;
            tw -= x;
        }
        if (tw < 0) { ans = 0; break; }
    }
    while (n--) cin >> x;
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}