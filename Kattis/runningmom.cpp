#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
unordered_map<string, vs> al;
unordered_map<string, int> status;

bool dfs(string v) {
    if (al[v].empty()) return false;
    else if (status[v] == 1) return true;
    else if (status[v] == 0) {
        status[v] = 1;
        for (string u: al[v]) if (dfs(u)) return true;
        status[v] = 2;
    }
    return false;
}

int main() {
    int n;
    string o, d, s;
    cin >> n;
    while (n--) {
        cin >> o >> d;
        al[o].push_back(d);
    }
    while (cin >> s) {
        cout << s << ' ';
        if (dfs(s)) cout << "safe" << endl;
        else cout << "trapped" << endl;
    }
    return 0;
}