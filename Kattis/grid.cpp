#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
vector<vi> AM;
vector<vi> dist;
ii coords[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    int n, m;
    string s;
    cin >> n >> m >> ws;

    AM.assign(n, vi());
    dist.assign(n, vi());
    for (int i = 0; i < n; i++) dist[i].assign(m, -1);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (int j = 0; j < m; j++) {
            AM[i].push_back(s[j] - '0');
        }
    }

    queue<ii> q; q.push({0, 0});
    while (!q.empty()) {
        ii c = q.front(); q.pop();
        for ()
    }

    cout << dist[n - 1][m - 1] << endl;

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << AM[i][j];
    //     }
    //     cout << endl;
    // }
    return 0;
}