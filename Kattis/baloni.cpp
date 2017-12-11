#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int b[1000002] = {0}, n, h, ans = 0;
    cin >> n;
    while (n--) {
        cin >> h;
        b[h]++;
        if (b[++h] > 0) b[h]--;
        else ans++;
    }
    cout << ans << endl;
}