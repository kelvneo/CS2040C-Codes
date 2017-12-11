#include <bits/stdc++.h>
using namespace std;

// Making a String
int main() {
    unsigned long long ans = 0, d;
    int n;
    cin >> n;
    unordered_set<unsigned long long> data;
    while (n--) {
        cin >> d;
        while (!data.insert(d).second && d > 0) d--;
        ans += d;
    }
    cout << ans << endl;
}