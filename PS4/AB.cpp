#include <bits/stdc++.h>
using namespace std;

void AddSuggestion(string babyName, int genderSuitability);
void RemoveSuggestion(string babyName);
int QuerySpecific(string START, string END, set<string> &names);
int Query(string START, string END, int gender);

set<string> male_names;
set<string> female_names;

int main() {
    //freopen("PS4/input.txt", "r", stdin);
    string a, b;
    int instruction, gender;
    while (1) {
        cin >> instruction;
        switch (instruction) {
            case 0: return 0;
            case 1:
                cin >> a >> gender;
                AddSuggestion(a, gender);
                break;
            case 2:
                cin >> a;
                RemoveSuggestion(a);
                break;
            case 3:
                cin >> a >> b >> gender;
                cout << Query(a, b, gender) << endl;
                break;
            default: break;
        }
    }
}

void AddSuggestion(string babyName, int genderSuitability) {
    switch (genderSuitability) {
        case 1:
            male_names.insert(babyName);
            break;
        case 2:
            female_names.insert(babyName);
            break;
        default:
            break;
    }
}

void RemoveSuggestion(string babyName) {
    auto a = male_names.find(babyName);
    if (a == male_names.end()) {
        a = female_names.find(babyName);
        female_names.erase(a);
    } else {
        male_names.erase(a);
    }
}

int QuerySpecific(string START, string END, set<string> &names) {
    int ans = 0;
    if (START == END) return 0;

    auto s = names.lower_bound(START), e = names.lower_bound(END);
    if (s == names.begin() && e == names.end())
        return names.size();
    
    return distance(s, e);
}

int Query(string START, string END, int gender) {
    switch (gender) {
        case 0:
            return QuerySpecific(START, END, male_names) + QuerySpecific(START, END, female_names);
        case 1:
            return QuerySpecific(START, END, male_names);
        case 2:
            return QuerySpecific(START, END, female_names);
        default:
            return 0;
    }
}