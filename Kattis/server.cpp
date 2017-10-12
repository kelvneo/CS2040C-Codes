#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n, input, completed = 0;
    cin >> T >> n;
    while (T--) {
        cin >> input;
        n -= input;
        if (n >= 0) {
            completed++;
        } else {
            break;
        }
    }
    cout << completed << endl;
    return 0;
}