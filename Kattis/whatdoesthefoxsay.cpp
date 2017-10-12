#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t >> ws;
    while (t--) {
        string s;
        list<string> sounds;
        unordered_multimap<string, list<string>::iterator> sounds_loc;
        sounds_loc.reserve(203);
        getline(cin, s);       
        istringstream iss(s);
        while (getline(iss, s, ' ')) {
            sounds.push_back(s);
            sounds_loc.insert({s, --sounds.end()});
        }
        while (getline(cin, s)) {
            if (s == "what does the fox say?") {
                for (auto a: sounds) {
                    cout << a << ' ';
                }
                cout << endl;
                break;
            } else {
                istringstream iss(s);
                while (getline(iss, s, ' '));
                auto a = sounds_loc.find(s);
                while (a != sounds_loc.end()) {
                    sounds.erase(a -> second);
                    sounds_loc.erase(a);
                    a = sounds_loc.find(s);
                }
            }
        }
    }
}