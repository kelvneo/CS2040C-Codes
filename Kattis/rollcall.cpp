#include <bits/stdc++.h>
using namespace std;

int main() {
    string fn, ln;
    map<string, set<string>> s_ln;
    unordered_map<string, int> fn_d;
    while ((cin >> fn >> ln)) {
        auto in = s_ln.insert({ln, set<string>()});
        if (!fn_d.insert({fn, 1}).second) fn_d[fn] += 1;
        s_ln[ln].insert(fn);
    }
    for (auto &a: s_ln) {
        for (auto &b: a.second) {
            cout << b;
            if (fn_d[b] != 1) cout << " " << a.first;
            cout << endl;
        }
    }
    return 0;
}