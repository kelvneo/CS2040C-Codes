#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while(getline(cin, s)) {
        istringstream ss(s);
        while(getline(ss, s, '-')) {
            cout << s[0];
        }
    }
    cout << endl;
    return 0;
}