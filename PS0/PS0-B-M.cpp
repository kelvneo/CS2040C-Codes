#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B;
    while (1) {
        scanf("%lld %lld", &A, &B);
        if (A == 0 && B == 0) break;
        printf("%lld\n", A + B);
    }
    return 0;
}