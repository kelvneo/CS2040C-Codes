#include <bits/stdc++.h>
using namespace std;

class Schedule {
public:
    string name;
    int id;
    int dilation;
    Schedule(string n, int i, int d): name(n), id(i), dilation(d) {
    }
    friend bool operator< (const Schedule &left, const Schedule &right) {
        if (left.dilation == right.dilation)
            return left.id > right.id;
        return left.dilation < right.dilation;
    }
};

int main() {
    return 0;
}
