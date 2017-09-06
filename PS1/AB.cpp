#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("PS1/input", "r", stdin);
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        int size, halfsize, j, k;
        cin >> size;
        halfsize = size / 2;
        unsigned long ans = 0, temp;
        unsigned long *data = new unsigned long[size];
        if (size == 1) {
            cin >> ans;
            cout << ans << endl;
            delete [] data;
        } else {
            for (j = 0; j < halfsize; j++) {
                cin >> temp;
                for (k = j * 2 - 1; k >= 0 && data[k] >= temp; k--) {
                    data[k + 1] = data[k];
                }
                data[k + 1] = temp;
                //cin >> data[j * 2];
                ans += data[j];

                cin >> temp;
                for (k = j * 2; k >= 0 && data[k] >= temp; k--) {
                    data[k + 1] = data[k];
                }
                data[k + 1] = temp;
                ans += (data[j] + data[j + 1]) / 2;
            }
            if (size % 2 == 1) {
                cin >> temp;
                for (k = j * 2 - 1; k >= 0 && data[k] >= temp; k--) {
                    data[k + 1] = data[k];
                }
                data[k + 1] = temp;
                ans += data[j];
            }
            cout << ans << endl;
            delete[] data;
        }
    }
}