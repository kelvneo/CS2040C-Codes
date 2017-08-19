#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("Kattis/input.txt", "r", stdin);
    int maxrooms, countbooked, i, tempbook;
    cin >> maxrooms >> countbooked;
    bool bookedrooms[maxrooms] = {};
    for (i = 0; i < countbooked; i++) {
        cin >> tempbook;
        bookedrooms[tempbook - 1] = 1;
    }
    for (i = 0; i < maxrooms; i++) {
        if (!bookedrooms[i]) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << "too late" << endl;
    return 0;
}