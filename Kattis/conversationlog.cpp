#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> word_count;

int main() {
    int m;
    string line, word, user;
    cin >> m >> ws;
    set<string> users;
    map<string, set<string>> words_used;
    while (m--) {
        getline(cin, line);
        istringstream iss(line);
        iss >> user;
        while (iss >> word) {
            users.insert(user);
            words_used[word].insert(user);
            word_count[word]++;
        }
    }

    int uc = users.size();
    vector<string> most_used;
    for (auto &a: words_used) {
        if (a.second.size() == uc) {
            most_used.push_back(a.first);
        }
    }
    if (most_used.empty()) cout << "ALL CLEAR" << endl;
    else {
        sort(most_used.begin(), most_used.end(), [](const string &a, const string &b) {
            return word_count[a] == word_count[b] ? a < b : word_count[a] > word_count[b];
        });
        for (auto &a: most_used) {
            cout << a << endl;
        }
    }
    return 0;
}