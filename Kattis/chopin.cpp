#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, string> m = {{"A#","Bb"}, {"Bb","A#"}, {"C#","Db"}, {"Db","C#"}, {"D#","Eb"}, {"Eb","D#"}, {"F#","Gb"}, {"Gb","F#"}, {"G#","Ab"}, {"Ab","G#"}};
    string n, t;
    for(int i = 1; cin >> n >> t; ++i){
        cout << "Case " << i << ": ";
        if(m.find(n) != m.end()){
            cout << m[n] << " " << t << endl;
        } else {
            cout << "UNIQUE" << endl;
        }
    }
    return 0;
}