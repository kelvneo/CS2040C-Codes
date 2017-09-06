#include <bits/stdc++.h>
using namespace std;

int main() {
    int length = 8, primes[length] = {2, 3 ,5, 7, 11, 13, 17, 19}, input = 0;
    unsigned long ans = 1, max = 1;
    for (int i = 0; i < length; i++) {
        cin >> input;
        ans += input * max;
        max *= primes[i];
    }
    cout << (max - ans) << endl;
}