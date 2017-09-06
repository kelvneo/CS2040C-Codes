#include <bits/stdc++.h>
using namespace std;

int main() {
//    freopen("Kattis/input.txt", "r", stdin);
    int data[5], length = 5;
    for (int i = 0; i < length; i++) cin >> data[i];

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                for (int k = 0; k < length; k++) cout << data[k] << " ";
                cout << endl;
            }
        }
    }
}