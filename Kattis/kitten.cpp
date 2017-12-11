#include <bits/stdc++.h>
using namespace std;

// typedef vector<int> vi;

int main() {
    int k;
    vector<int> AL;
    AL.assign(100, -1);
    string s;
    cin >> k >> ws;
    while (getline(cin, s)) {
        if (s == "-1") break;

        int p = -1, c;
        istringstream iss(s);
        while (getline(iss, s, ' ')) {
            if (p == -1) {
                p = stoi(s);
            } else {
                AL[stoi(s)] = p;
            }
        }
    }

    while (k != -1) {
        cout << k << ' ';
        k = AL[k];
    }
    cout << endl;
    return 0;
}