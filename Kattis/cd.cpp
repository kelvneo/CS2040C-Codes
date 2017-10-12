#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int N, M, d, ans = 0;
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) 
            break;
        unordered_set<unsigned int> N_cd;
        N_cd.reserve(max(N, M) << 1);
        while (N--) {
            cin >> d;
            N_cd.insert(d);
        }
        while (M--) {
            cin >> d;
            auto loc = N_cd.find(d);
            if (loc != N_cd.end()) {
                N_cd.erase(loc);
                ans++;
            }
        }
        cout << ans << endl;
        ans = 0;
    }
}