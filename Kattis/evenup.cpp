#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("Kattis/input.txt", "r", stdin);
    int amount, input;
    cin >> amount;
    stack<int> cards;
    for (int i = 0; i < amount; i++) {
        cin >> input;
        if (cards.empty() || (cards.top() + input) % 2 == 1) {
            cards.push(input);
        } else {
            cards.pop();
        }
    }
    cout << cards.size() << endl;
}