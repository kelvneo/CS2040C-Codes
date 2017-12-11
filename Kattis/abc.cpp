#include <bits/stdc++.h>
using namespace std;

int main() {
    int num[3];
    string order;
    cin >> num[0] >> num[1] >> num[2] >> ws;
    getline(cin, order);
    sort(num, num + 3);
    for (auto &a: order) cout << num[a - 'A'] << " ";
    cout << endl;
    return 0;
}