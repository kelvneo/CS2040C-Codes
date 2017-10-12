#include <bits/stdc++.h>
using namespace std;

typedef tuple<unsigned long, unsigned int, unsigned int> iqs;  // Instruction - Queue set

int main() {
    string instruction;
    priority_queue<iqs, vector<iqs>, greater<iqs>> data;
    unsigned int print_amount, qid, freq;
    while ((cin >> instruction) && instruction != "#") {
        cin >> qid >> freq;
        data.push(make_tuple(freq, qid, freq));
    }
    cin >> print_amount;
    while (print_amount--) {
        iqs top = data.top();
        data.pop();
        cout << get<1>(top) << endl;
        data.push(make_tuple(get<0>(top) + get<2>(top), get<1>(top), get<2>(top)));
    }
    iqs.clear();
    return 0;
}