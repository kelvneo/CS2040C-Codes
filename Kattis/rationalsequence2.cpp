#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
    unsigned int P, K, p, q, ans;
    char slash;
    cin >> P;
    stack<ii> data;
    while (P--) {
        cin >> K >> p >> slash >> q;
        ans = 1;
        while (p > 1 || q > 1) {
            data.push({p, q});
            if (p > q) {
                p -= q;
            } else {
                q -= p;
            }
        }
        while (!data.empty()) {
            ii n = data.top(); data.pop();
            ans <<= 1;
            if (n.first > n.second) ans++;
        }
        cout << K << ' ' << ans << endl;
    }
}