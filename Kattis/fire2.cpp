#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<char> vc;
typedef vector<int> vi;
ii mv[] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int w, h, ans = 0, out = 0;
        ii invalid = {-10, -10};
        char c;
        cin >> w >> h;
        vector<vc> grid;
        grid.assign(h, vc());
        queue<ii> d, pp;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> c;
                grid[i].push_back(c);
                if (c == '@') pp.push({i, j});
                else if (c == '*') d.push({i, j});
            }
            cin >> ws;
        }

        while (!pp.empty()) {
            int fires = d.size();
            while (fires--) {
                ii cur = d.front(); d.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = cur.first + mv[i].first, ny = cur.second + mv[i].second;
                    if (nx < 0 || nx >= h || ny < 0 || ny >= w || grid[nx][ny] == '#' || grid[nx][ny] == '*') continue;
                    else {
                        grid[nx][ny] = '*';
                        d.push({nx, ny});
                    }
                }
            }
            int players = pp.size();
            while (players--) {
                ii cur = pp.front(); pp.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = cur.first + mv[i].first, ny = cur.second + mv[i].second;
                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                        out = 1;
                        pp = queue<ii>();
                        break;
                    } else if (grid[nx][ny] == '.') {
                        grid[nx][ny] = c;
                        pp.push({nx, ny});
                    }
                }
                if (pp.size() == 0) break;
            }
            ans++;
        }
        if (out) cout << ans << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}