#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k, raw, x, c = 1e9;
    vector<int> tea, topping;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> raw;
        tea.push_back(raw);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> raw;
        topping.push_back(raw);
    }
    for (int i = 0; i < n; i++) {
        cin >> k;
        while (k--) {
            cin >> raw;
            c = min(c, tea[i] + topping[raw - 1]);
        }
    }
    cin >> x;
    cout << max(0, (x / c) - 1) << endl;
}