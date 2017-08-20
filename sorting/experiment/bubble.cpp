#include <bits/stdc++.h>
using namespace std;

void dosort(int unsorted[], int length);

int main() {
    freopen("sorting/experiment/test.txt", "r", stdin);
    string s;
    while (getline(cin, s)) {
        if (s[0] == '#')
            continue;
        istringstream ss(s);
        int sort[10] = {0,0,0,0,0,0,0,0,0,0}, ans[10] = {0,0,0,0,0,0,0,0,0,0}, i = 0, rans = 0, fail = 0;

        while (getline(ss, s, ' ')) {
            if (s == ">") {
                rans = 1;
                i = 0;
            }
            else if (rans)
                ans[i++] = stoi(s);
            else {
                cout << s << " ";
                sort[i++] = stoi(s);
            }
        }

        cout << "> ";

        dosort(sort, 10);
        
        for (i = 0; i < 10; i++) {
            cout << sort[i] << " ";
            if (sort[i] != ans[i]) {
                fail = 1;
            }
        }

        if (fail) {
            cout << ": \e[91mFAIL!\e[39m" << endl;
        } else {
            cout << ": \e[92mPASS!\e[39m" << endl;
        }

    }
    return 0;
}

void dosort(int unsorted[], int length) {
    int i, j;
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - i - 1; j++) {
            if (unsorted[j] > unsorted[j + 1]) {
                swap(unsorted[j], unsorted[j + 1]);
            }
        }
    }
}