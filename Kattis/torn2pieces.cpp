#include <bits/stdc++.h>
using namespace std;

typedef set<string> vs;

int main() {
    int n;
    string raw, s, t, c, d;
    unordered_map<string, vs> AL;
    unordered_map<string, string> parent;
    cin >> n >> ws;
    while (n--) {
        getline(cin, raw);
        istringstream iss(raw);
        iss >> c;
        while (iss >> d) {
            AL[c].insert(d);
            AL[d].insert(c);
        }
    }
    cin >> s >> t;
    parent[s] = "";
    stack<string> st;
    st.push(s);
    while (!st.empty()) {
        string cur = st.top(); st.pop();
        for (auto &a: AL[cur]) {
            if (parent.find(a) == parent.end()) {
                parent[a] = cur;
                st.push(a);
            }
        }
    }
    if (parent.find(t) == parent.end()) {
        cout << "no route found" << endl;
    } else {
        list<string> ans;
        while (t != "") {
            ans.push_front(t);
            t = parent[t];
        }

        for (auto &a: ans) cout << a << " ";
        cout << endl;
    }
    // for (auto &a: AL) {
    //     cout << a.first << ": ";
    //     for (auto &b: a.second) cout << b << " ";
    //     cout << endl;
    // }
    return 0;
}