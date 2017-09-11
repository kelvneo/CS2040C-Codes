#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("PS2/input.txt", "r", stdin);
    int cases;
    while (cin >> cases && cases != 0) {
        queue<int> qdata;
        stack<int> sdata;
        priority_queue<int> pqdata;
        int command, value;
        bool isstack = true, isqueue = true, ispqueue = true;
        for (int i = 0; i < cases; i++) {
            cin >> command >> value;
            if (command == 1) {
                if (isqueue)
                    qdata.push(value);
                if (isstack)
                    sdata.push(value);
                if (ispqueue)
                    pqdata.push(value);
            } else {
                if (isstack && (sdata.empty() || sdata.top() != value))
                    isstack = false;
                else
                    sdata.pop();
                if (isqueue && (qdata.empty() || qdata.front() != value))
                    isqueue = false;
                else
                    qdata.pop();
                if (ispqueue && (pqdata.empty() || pqdata.top() != value))
                    ispqueue = false;
                else
                    pqdata.pop();
            }
        }
        if (isstack && (isqueue || ispqueue) || (isqueue && ispqueue)) {
            cout << "not sure" << endl;
        } else if (isstack && !(isqueue || ispqueue)) {
            cout << "stack" << endl;
        } else if (isqueue && !(isstack || ispqueue)) {
            cout << "queue" << endl;
        } else if (ispqueue && !(isstack || isqueue)) {
            cout << "priority queue" << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
}