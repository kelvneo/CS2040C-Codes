#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, done = 0;
    double x, y, cx, cy;
    cin >> m;
    while (m--) {
        cin >> x >> y >> n;
        while (n--) {
            cin >> cx >> cy;
            if (!done) {
                double dx = pow(cx - x, 2);
                double dy = pow(cy - y, 2);
                double d = sqrt(dx + dy);
                if (d <= 8) {
                    done = 1;
                    cout << "light a candle" << endl;
                }
            }
        }
        if (!done) cout << "curse the darkness" << endl;
        done = 0;
    }
    return 0;
}