#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
int n, m;
vector<vi> am;
pii coords[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void clearStar(int x, int y, int mx, int my) {
    if (x > -1 && y > -1 && y < my && x < mx && am[x][y] == 1) {
        am[x][y] = 0;
        for (pii s: coords) {
            clearStar(x + s.first, y + s.second, mx, my);
        }
    }
}

int main() {
    int cs = 1, ans = 0;
    char c;
    while (cin >> m >> n) {
        am.assign(m, vi());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> c;
                if (c == '-') am[i].push_back(1);
                else am[i].push_back(0);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (am[i][j] == 1) {
                    ans++;
                    clearStar(i, j, m, n);
                }
            }
        }
        cout << "Case " << cs++ << ": " << ans << endl; 
        ans = 0;
    }
}