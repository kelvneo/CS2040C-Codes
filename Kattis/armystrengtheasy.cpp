#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, ng, nm, s;
    string rs;
    cin >> T >> ws >> ws;
    while (T--) {
        priority_queue<int, vector<int>, greater<int>> g, m;
        cin >> ng >> nm >> ws;
        getline(cin, rs);
        istringstream iss(rs);
        while (iss >> s) {
            g.push(s);
        }
        getline(cin, rs);
        iss = istringstream(rs);
        while (iss >> s) {
            m.push(s);
        }

        while (!g.empty() && !m.empty()) {
            int lg = g.top(), lm = m.top();
            // cout << lg << ' ' << lm << endl;
            if (lg == lm || lg > lm) {
                m.pop();
            } else {
                g.pop();
            }
        }

        if (g.empty() && m.empty()) {
            cout << "uncertain" << endl;
        } else if (g.empty()) {
            cout << "MechaGodzilla" << endl;
        } else {
            cout << "Godzilla" << endl;
        }
        cin >> ws;
    }
    return 0;
}