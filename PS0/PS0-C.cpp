#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("PS0/input", "r", stdin);
    string s;
    while(getline(cin, s)) {
        istringstream ss(s);
        unsigned long a[10] = {0,0,0,0,0,0,0,0,0,0}, i = 0;

        if (s == "0 0") break;

        while (getline(ss, s, ' ')) {
            a[i++] = stol(s);
        }

        unsigned long results = 0;
        for (i = 0; i < 10; i++) {
            results += a[i];
        }

        cout << results << endl;

    }
}