#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string runner;
    double a, b, total = 1e9;
    multimap<double, string> ftime, subtime;
    vector<string> fin;
    cin >> n;
    while (n--) {
        cin >> runner >> a >> b;
        ftime.insert({a, runner});
        subtime.insert({b, runner});
    }
    for (auto &it: ftime) {
        vector<string> tmp;
        tmp.push_back(it.second);
        double tmptotal = it.first;
        for (auto it2 = subtime.begin(); tmp.size() != 4; it2++) {
            if (it.second != it2 -> second) {
                tmptotal += it2 -> first;
                tmp.push_back(it2 -> second);
            }
        }
        if (tmptotal < total) {
            total = tmptotal;
            fin = tmp;
        }
    }
    cout << total << endl;
    for (auto &b: fin) {
        cout << b << endl;
    }
    return 0;
}