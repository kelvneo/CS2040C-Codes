#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("Kattis/input.txt", "r", stdin);
    int count, i;
    cin >> count;
    for (i = 0; i < count; i++) {
        char name[31];
        int pyear, byear, courses, trash;
        scanf("%s %d/%d/%d %d/%d/%d %d", name, &pyear, &trash, &trash, &byear, &trash, &trash, &courses);
        cout << name;
        if (pyear >= 2010 || byear >= 1991) cout << " eligible"  << endl;
        else if (courses > 40) cout << " ineligible"  << endl;
        else cout << " coach petitions"  << endl;
    }
    return 0;
}