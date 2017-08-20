#include <bits/stdc++.h>
using namespace std;

void dosort(int unsorted[], int length);

int main() {
    freopen("sorting/experiment/test.txt", "r", stdin);
    string s;
    while (getline(cin, s)) {
        if (s[0] == '#')
            continue;
        istringstream ss(s);
        int sort[10] = {0,0,0,0,0,0,0,0,0,0}, ans[10] = {0,0,0,0,0,0,0,0,0,0}, i = 0, rans = 0, fail = 0;

        while (getline(ss, s, ' ')) {
            if (s == ">") {
                rans = 1;
                i = 0;
            }
            else if (rans)
                ans[i++] = stoi(s);
            else {
                cout << s << " ";
                sort[i++] = stoi(s);
            }
        }

        cout << "> ";

        dosort(sort, 10);
        
        for (i = 0; i < 10; i++) {
            cout << sort[i] << " ";
            if (sort[i] != ans[i]) {
                fail = 1;
            }
        }

        if (fail) {
            cout << ": \e[91mFAIL!\e[39m" << endl;
        } else {
            cout << ": \e[92mPASS!\e[39m" << endl;
        }

    }
    return 0;
}

void merge(int data[], int low, int mid, int high) {
    int length = high - low + 1;
    int* temp = new int[length];
    int left = low, right = mid + 1, tempId = 0;
    while (left <= mid && right <= high) {
        temp[tempId++] = (data[left] <= data[right]) ? data[left++] : data[right++];
    }
    while (left <= mid) temp[tempId++] = data[left++];
    while (right <= high) temp[tempId++] = data[right++];
    for (int i = 0; i < length; i++) data[i + low] = temp[i];
    delete[] temp;
}

void mergeSort(int unsorted[], int low, int high) {
    if (low < high) {
        int mid = (high + low) / 2;
        mergeSort(unsorted, low, mid);
        mergeSort(unsorted, mid + 1, high);
        merge(unsorted, low, mid, high);
    }
}

void dosort(int unsorted[], int length) {
    mergeSort(unsorted, 0, length - 1);
}