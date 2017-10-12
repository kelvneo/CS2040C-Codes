#include <bits/stdc++.h>
using namespace std;

int main() {
    int lines, input;
    while ((cin >> lines) && lines != 0) {
        pair<int, int> firstlist[lines];
        for (int i = 0; i < lines; i++) {
            cin >> input;
            firstlist[i] = make_pair(input, i);
        }
        sort(firstlist, firstlist + lines);
        int temp[lines];
        for (int i = 0; i < lines; i++) {
            cin >> temp[i];
        }
        sort(temp, temp + lines);
        pair<int, pair<int, int>> secondlist[lines];
        for (int i = 0; i < lines; i++) {
            secondlist[i] = make_pair(temp[i], firstlist[i]);
        }
        sort(secondlist, secondlist + lines, [](pair<int, pair<int, int>> left, pair<int, pair<int, int>> right) {
            return left.second.second < right.second.second;
        });
        for (int i = 0; i < lines; i++) {
            cout << secondlist[i].first << endl;
        }
        cout << endl;
    }
    return 0;
}