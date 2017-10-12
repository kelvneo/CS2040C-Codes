#include <bits/stdc++.h>
using namespace std;

int main() {
    int nums, possible = 0;
    cin >> nums;
    int data[nums], maxs[nums], mins[nums];
    for (int i = 0; i < nums; i++) {
        cin >> data[i];
        if (i == 0)
            maxs[0] = data[0];
        else {
            maxs[i] = max(maxs[i - 1], data[i]);
        }
    }
    mins[nums - 1] = data[nums - 1];
    for (int i = nums - 2; i >= 0; i--) {
        mins[i] = min(mins[i + 1], data[i]);
    }
    for (int i = 0; i < nums; i++) {
        if (data[i] >= maxs[i] && data[i] <= mins[i]) possible++;
    }
    cout << possible << endl;
    return 0;
}