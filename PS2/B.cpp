#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("PS2/input.txt", "r", stdin);
    int cases;
    while (cin >> cases && cases != 0) {
        queue<int> qdata;
        stack<int> sdata;
        int command, value;
        bool isstack = true, isqueue = true;
        for (int i = 0; i < cases; i++) {
            cin >> command >> value;
            if (command == 1) {
                if (isqueue)
                    qdata.push(value);
                if (isstack)
                    sdata.push(value);
            } else {
                if (isstack && (sdata.empty() || sdata.top() != value))
                    isstack = false;
                else
                    sdata.pop();
                if (isqueue && (qdata.empty() || qdata.front() != value))
                    isqueue = false;
                else
                    qdata.pop();
            }
        }
        if (isstack && isqueue) {
            cout << "not sure" << endl;
        } else if (isstack) {
            cout << "stack" << endl;
        } else if (isqueue) {
            cout << "queue" << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
}