#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> am;
ii coords[] = {{1, 0}, {0, 1}};  // Only go right and down

/**
 * Clear the face
 */
ii clearFace(int x, int y, int mx, int my, ii &es) {
    if (x > -1 && y > -1 && y < my && x < mx && am[x][y] > 0) {  // Check if not out of borders
        if (am[x][y] == 2) es.second++;  // If it is a smiling face
        else if (am[x][y] == 4) es.first++;  // If it is an eye
        am[x][y] = 0;  // Set to 0 to mark as visited
        for (ii s: coords) {
            es = clearFace(x + s.first, y + s.second, mx, my, es);
        }
    }
    return es;
}

int main() {
    // freopen("PE/inputB.txt", "r", stdin);
    int r, c, f = 0, sf = 0;
    string dr;
    cin >> r >> c;

    am.assign(r, vi());
    for (int i = 0; i < r; i++) {
        getline(cin, dr);
        for (int j = 0; j < c; j++) {
            if (dr[j] == '#') am[i].push_back(1);
            else if (dr[j] == 'v') am[i].push_back(2);
            else if (dr[j] == '^') am[i].push_back(3);
            else if (dr[j] == '*') am[i].push_back(4);
            else if (dr[j] == ' ') am[i].push_back(5);
            else am[i].push_back(0);
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (am[i][j] > 0) {
                f++;
                ii tes = {0, 0};
                ii es = clearFace(i, j, r, c, tes);
                if (es.second != 0) sf++;
            }
        }
    }
    cout << f << endl;
    cout << sf << endl;
    return 0;
}