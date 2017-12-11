#include <bits/stdc++.h>
using namespace std;

int dfs(unordered_map<string, vector<string>> &data, vector<string> &cur) {
    int ans = 1;
    if (cur.empty()) return ans;
    else {
        for (auto a: cur) {
            ans = max(ans, dfs(data, data[a]) + 1);
        }
        return ans;
    }
}

void toLower(string &s) {
    for (char &c : s) {
        if (c >= 'A' && c <= 'Z') {
            c = tolower(c);
        }
    }
}

int main() {
    int n, ans = 0;
    string s, r ,d;
    cin >> n;
    unordered_map<string, vector<string>> data;
    while(n--) {
        cin >> s >> r >> d;
        toLower(s);
        toLower(d);
        data[d].push_back(s);
    }
    cout << dfs(data, data["polycarp"]) << endl;
    return 0;
}