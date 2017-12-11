#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
int grid[8][8];
ii offset[] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

int main() {
    int n, x, y, mx = 0;
    string pos;
    cin >> n;
    while (n--) {
        memset(grid, -1, sizeof grid);
        cin >> pos;
        x = pos[0] - 'a';
        y = '8' - pos[1];
        grid[y][x] = 0;
        // cout << "(" << x << "," << y << ")" << endl;

        queue<ii> q;
        q.push({x, y});
        while (!q.empty()) {
            ii c = q.front(); q.pop();
            int w = grid[c.second][c.first];
            for (ii o: offset) {
                x = c.first + o.first;
                y = c.second + o.second;
                if (x > -1 && y > -1 && x < 8 && y < 8 && grid[y][x] == -1) {
                    mx = max(w + 1, mx);
                    grid[y][x] = w + 1;
                    q.push({x, y});
                }
            }
        }

        cout << mx << ' ';

        for (int j = 0; j < 8; j++) {            
            for (int i = 0; i < 8; i++) {
                if (grid[j][i] == mx) cout << char(i + 'a') << char(8 - j + '0') << ' ';
            }
        }
        cout << endl;
        // for (int i = 0; i < 8; i++) {
        //     for (int j = 0; j < 8; j++) {
        //         cout << grid[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
    }
    return 0;
}
