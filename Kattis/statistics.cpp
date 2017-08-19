#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("Kattis/input.txt", "r", stdin);
    int size = 0, caseno = 1;
    while (cin >> size) {
        int i, minnum = INT_MAX, maxnum = INT_MIN, range = 0, current;
        for (i = 0; i < size; i++) {
            cin >> current;
            minnum = min(current, minnum);
            maxnum = max(current, maxnum);
        }
        cout << "Case " << caseno++ << ": " << minnum << " " << maxnum << " " << maxnum - minnum << endl;
    }
    return 0;
}