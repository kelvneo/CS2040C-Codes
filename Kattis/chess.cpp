#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
ii mv[] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}}, inv = {-1, -1};

int main() {
    int T;
    cin >> T;
    while (T--) {
        char cx, cy;
        int sx, sy, ex, ey;
        cin >> cx >> cy;
        sx = cx - 'A', sy = '8' - cy;
        cin >> cx >> cy;
        ex = cx - 'A', ey = '8' - cy;
        if ((sx % 2 == ex % 2) != (sy % 2 == ey % 2)) cout << "Impossible" << endl;
        else if (sx == ex && sy == ey) cout << "0 " << cx << " " << cy << endl;
        else {
            ii s = {sx, sy}, e = {ex, ey};

            int grid[8][8];
            memset(grid, -1, sizeof grid);
            grid[sy][sx] = 0;

            map<ii, ii> parent;
            parent[s] = inv;
            
            queue<ii> q;
            q.push(s);

            while (!q.empty()) {
                ii c = q.front(); q.pop();
                for (int i = 0; i < 4; i++) {
                    ii o = mv[i];
                    int ncx = c.first + o.first, ncy = c.second + o.second;
                    while (ncx >= 0 && ncx < 8 && ncy >= 0 && ncy < 8) {
                        if (grid[ncy][ncx] > grid[c.second][c.first] + 1 || grid[ncy][ncx] == -1) {
                            grid[ncy][ncx] = grid[c.second][c.first] + 1;
                            parent[{ncx, ncy}] = c;
                            q.push({ncx, ncy});
                        }
                        ncx += o.first; ncy += o.second;
                    }
                }
            }


            if (grid[ey][ex] <= 4) {
                list<ii> path;
                ii tmp = e;
                while (tmp != inv) {
                    path.push_front(tmp);
                    // cout << "(" << e.first << "," << e.second << ") -> (" << parent[e].first << "," << parent[e].second << ")" << endl; 
                    tmp = parent[tmp];
                }
                cout << grid[ey][ex] << " ";
                for (ii a: path) {
                    cout << char(a.first + 'A') << " " << abs(a.second - 8) << " ";
                }
                cout << endl;
            } else cout << "Impossible" << endl;
        }
    }
    return 0;
}