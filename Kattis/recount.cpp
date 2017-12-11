#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> votes(100001);
    string top_name, input;
    int top_count = 0, runoff = 0;
    while (getline(cin, input)) {
        if (input == "***") break;
        
        int nc = votes[input]++;
        if (nc > top_count) {
            top_name = input;
            top_count = nc;
            runoff = 0;
        } else if (nc == top_count) {
            runoff = 1;
        }
    }
    if (runoff) cout << "Runoff!" << endl;
    else cout << top_name << endl;
    return 0;
}