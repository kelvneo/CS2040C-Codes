#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("Kattis/input.txt", "r", stdin);
    int size;
    while (cin >> size) {
        if (size == 0) break;

        string data[size];
        for (int i = 0; i < size; i++) {
            getline(cin >> ws, data[i]);
        }

        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j][0] > data[j + 1][0])
                    swap(data[j], data[j + 1]);
                else if (data[j][0] == data[j + 1][0]) {
                    if (data[j][1] > data[j + 1][1])
                        swap(data[j], data[j + 1]);
                }
            }
        }

        for (int i = 0; i < size; i++) {
            cout << data[i] << endl;
        }

        cout << endl;

    }

    return 0;
}