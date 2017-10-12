#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        string s, name, food;

        getline(cin, s);
        int orders = stoi(s);

        if (orders == 0) break;

        map<string, set<string>> food_name;

        while (orders--) {
            getline(cin, s);
            istringstream iss(s);
            getline(iss, name, ' ');
            while (getline(iss, food, ' ')) {
                auto search = food_name.find(food);
                if (search != food_name.end()) {
                    (search -> second).insert(name);
                } else {
                    food_name.insert({food, {name}});
                }
            }
        }
        for (auto it = food_name.begin(); it != food_name.end(); ++it) {
            cout << it -> first << ' ';
            for (auto n: it -> second) {
                cout << n << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
}