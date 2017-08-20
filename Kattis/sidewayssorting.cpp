#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("Kattis/input.txt", "r", stdin);
    int r, c;
    while (cin >> r >> c) {
        if (r == 0 && c == 0) 
            break;
        
        string data[r];
        for (int i = 0; i < r; i++) {
            getline(cin >> ws, data[i]);
        }

        for (int i = 0; i < c - 1; i++) {
            for (int j = 0; j < c - i - 1; j++) {
                for (int k = 0; k < r; k++) {
                    if (tolower(data[k][j]) > tolower(data[k][j + 1])) {
                        for (int l = 0; l < r; l++)
                            swap(data[l][j], data[l][j + 1]);
                        break;
                    } else if (tolower(data[k][j]) < tolower(data[k][j + 1])) break;
                }
            }
        }

        for (int i = 0; i < r; i++) {
            cout << data[i] << endl;
        }

        cout << endl;

    }

    return 0;
}