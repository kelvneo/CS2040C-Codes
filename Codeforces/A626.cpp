#include <bits/stdc++.h>
using namespace std;

// Robot Sequence
int main() {
    int c, ans = 0;
    string d;
    cin >> c;
    cin >> d;
    for (int i = 0; i < c - 1; i++) {
        int x = 0, y = 0;
        for (int j = i; j < c; j++) {
            switch(d[j]) {
                case 'R': x++; break;
                case 'L': x--; break;
                case 'U': y++; break;
                case 'D': y--; break;
                default: break;
            }
            if (x == 0 && y == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}