#include <bits/stdc++.h>
using namespace std;

// Beautiful Paintings
int main() {
    int n, v, ans = 0;
    vector<unordered_set<int>> a;
    unordered_set<int> temp;
    a.push_back(temp);
    cin >> n;
    while (n--) {
        int i = 0;
        cin >> v;
        while (i < a.size() && !a[i].insert(v).second) i++;
        if (i >= a.size()) {
            unordered_set<int> temp;
            a.push_back(temp);
            a[i].insert(v);
        }
    }
    for (auto i: a) {
        ans += i.size() - 1;
    }
    cout << ans << endl;
    return 0;
}