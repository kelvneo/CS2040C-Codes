#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, tmp, a = 0, b = 0;
    bool isA = true;
    priority_queue<int> vals;
    cin >> n;
    while (n--) {
        cin >> tmp;
        vals.push(tmp);
    }
    while (!vals.empty()) {
        int val = vals.top(); vals.pop();
        if (isA) {
            a += val;
        } else {
            b += val;
        }
        isA = !isA;
    }
    cout << a << " " << b << endl;
}