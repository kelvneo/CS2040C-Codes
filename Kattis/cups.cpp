#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("Kattis/input.txt", "r", stdin);
    int size, j;
    vector<pair<int, string>> cups;
    cin >> size >> ws;
    for (int i = 0; i < size; i++) {
        char a[20], b[20];
        scanf("%s %s ", a, b);
        if (isdigit(a[0])) {
            cups.push_back(make_pair(atoi(a) / 2, b));
        } else {
            cups.push_back(make_pair(atoi(b), a));
        }
    }
    sort(cups.begin(), cups.end());
    for (auto i: cups) {
        cout << i.second << endl;
    }
    return 0;
}