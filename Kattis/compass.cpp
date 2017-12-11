#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, n;
    cin >> c >> n;
    if (c == n) cout << 0 << endl;
    else {
        int ans = ((n - c) + 360) % 360;
        if (ans > 180) {
            ans -= 360;
        }
        cout << ans << endl;
    }
}