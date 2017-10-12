#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int height, maxsize, index = 1;
    cin >> height;
    maxsize = 1 << (height + 1);
    string directions;
    getline(cin, directions);
    for (char c: directions) {
        if (c == 'L') {
            index <<= 1;
        }
        else if (c == 'R') {
            index = (index << 1) + 1;
        }
    }
    cout << maxsize - index << endl;
    return 0;
}