#include <bits/stdc++.h>
using namespace std;

void binarySearch(int min, int max) {
    int mid = (max + min) / 2;
    string output;
    cout << mid << endl;
    cin  >> output;
    if (output == "correct");
    else if (output == "lower") binarySearch(min, mid - 1);
    else if (output == "higher") binarySearch(mid + 1, max);
}

int main() {
    binarySearch(1, 1000);
}