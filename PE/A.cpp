#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("PE/inputA.txt", "r", stdin);
    int N, d, Q, V;
    multiset<int> data;  // Holds all the numbers
    cin >> N;
    // Take in all current numbers in array
    while (N--) {
        cin >> d;
        data.insert(d);
    }
    cin >> Q;
    // Take in all the queries
    while (Q--) {
        cin >> d;
        if (d == 0) {
            if (data.empty()) {
                // If it is empty, just print 0
                cout << 0 << endl;
            } else {
                // Take the set's first and last values.
                cout << (*(--data.end()) - *(data.begin())) << endl;
            }
        } else if (d < 0) {
            // Find the value first by negating.
            auto loc = data.find(abs(d));
            // Only erase if can be found.
            if (loc != data.end())
                data.erase(loc);
        } else {
            // Just insert
            data.insert(d);
        }
    }
    return 0;
}