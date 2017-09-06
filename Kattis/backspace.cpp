#include <bits/stdc++.h>
using namespace std;

int main() {
    deque<char> words;
    char c;
    while((c = getchar()) != '\n' && c != '\0') {
        if (c == '<' && !words.empty()) {
            words.pop_back();
        } else {
            words.push_back(c);
        }
    }
    for (char d: words) {
        cout << d;
    }
    cout << endl;
    return 0;
}