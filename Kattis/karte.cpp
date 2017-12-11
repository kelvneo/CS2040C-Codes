#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, set<int>> cards;
    string raw;
    getline(cin, raw);
    for (int i = 0; i < raw.length() / 3; i++) {
        int o = i * 3;
        char t = raw[o];
        int cno = stoi(raw.substr(o + 1, 2));
        if (!cards[t].insert(cno).second) {
            cout << "GRESKA" << endl;
            return 0;
        }
    }
    cout << (13 - cards['P'].size()) << " " << (13 - cards['K'].size()) << " " << (13 - cards['H'].size()) << " " << (13 - cards['T'].size()) << endl;
    return 0;
}