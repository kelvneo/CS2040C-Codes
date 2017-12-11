#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main() {
    int n, m, low = INF, high = -INF, ans = 0;
    cin >> n;
    while (n--) {
        cin >> m;
        if (m > high) {
            ans++;
            high = m;
        } else if (m < low) {
            ans++;
            low = m;
        }
    }
    cout << ans << endl;
    return 0;
}