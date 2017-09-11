#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("PS2/input.txt", "r", stdin);
    int cases;
    while (cin >> cases && cases != 0) {
        stack<int> data;
        int command, value;
        bool impossible = false;
        for (int i = 0; i < cases; i++) {
            cin >> command >> value;
            if (!impossible) {
                if (command == 1) {
                    data.push(value);
                } else if (command == 2) {
                    if (data.empty() || data.top() != value) {
                        impossible = true;
                    } else {
                        data.pop();
                    }
                }
            }
        }
        if (impossible) {
            cout << "impossible" << endl;
        } else {
            cout << "stack" << endl;
        }
    }
}