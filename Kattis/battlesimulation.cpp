#include <bits/stdc++.h>
using namespace std;

int main() {
    string raw, ans = "";
    getline(cin, raw);
    for (int i = 0; i < raw.size(); i++) {
        if (raw[i] == 'R') {
            if (i + 2 < raw.size() && ((raw[i + 1] == 'B' && raw[i + 2] == 'L') || (raw[i + 1] == 'L' && raw[i + 2] == 'B'))) {
                ans += "C";
                i += 2;
            } else {
                ans += "S";
            }
        } else if (raw[i] == 'B') {
            if (i + 2 < raw.size() && ((raw[i + 1] == 'R' && raw[i + 2] == 'L') || (raw[i + 1] == 'L' && raw[i + 2] == 'R'))) {
                ans += "C";
                i += 2;
            } else {
                ans += "K";
            }
        } else if (raw[i] == 'L') {
            if (i + 2 < raw.size() && ((raw[i + 1] == 'R' && raw[i + 2] == 'B') || (raw[i + 1] == 'B' && raw[i + 2] == 'R'))) {
                ans += "C";
                i += 2;
            } else {
                ans += "H";
            }
        } 
    }
    cout << ans << endl;
    return 0;
}