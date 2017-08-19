#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, D, X, i, N = 0, M = 0;
    cin >> L >> D >> X;
    for (i = 0; i <= (D - L / 2); i++) {
        if (N == 0) {
            string sN = to_string(i + L);
            int tN = 0;
            for (char& c: sN) 
                tN += (c - '0');
            if (tN == X) N = i + L;
        }
        if (M == 0) {
            string sM = to_string(D + 1 - i);
            int tM = 0;
            for (char& c: sM) 
                tM += (c - '0');
            if (tM == X) M = D + 1 - i;
        }
        if (N != 0 && M != 0) break;
    }
    cout << N << endl;
    cout << M << endl;
}