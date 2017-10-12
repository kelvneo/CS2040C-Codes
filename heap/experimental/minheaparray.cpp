#include <bits/stdc++.h>
using namespace std;

class MinHeapArray {
private:
    vector<int> data;
    int length = 0;
    void shiftUp(int index) {
        while (index > 1 && index <= length) {
            int parent = index >> 1;
            if (data[parent] > data[index]) {
                swap(data[parent], data[index]);
            }
            index = parent;
        }
    }
    void shiftDown(int index) {
        while (index > 0 && index <= length) {
            int left_id = index << 1;
            int right_id = left_id + 1;
            if (left_id > length) break;  // Already at leaf 
            int lower_child_id = (right_id > length || data[left_id] < data[right_id]) ? left_id : right_id;
            if (data[lower_child_id] < data[index])
                swap(data[lower_child_id], data[index]);
            index = lower_child_id;
        }
    }
public:
    MinHeapArray() {
        data.push_back(0);
        length++;
    }
    MinHeapArray(int init[], int initlength) {
        data.push_back(0);
        for (int i = 0; i < initlength; i++)
            data.push_back(init[i]);
        length = data.size() - 1;
        for (int i = length / 2; i >= 1; i--) {
            shiftDown(i);
        }
    }
    void push(int i) {
        data.push_back(i);
        length++;
        shiftUp(length);
    }
    void pop() {
        swap(data[length], data[1]);
        data.pop_back();
        length--;
        shiftDown(1);
    }
    int peek() {
        if (length > 0)
            return data[1];
        else
            return -1;
    }
    int size() {
        return length;
    }
    void print() {
        for (auto a: data) {
            cout << a << ' ';
        }
        cout << endl;
    }
};

int main() {
    int data[] = {91, 81, 71, 61, 51, 41, 31, 21, 11};
    MinHeapArray h(data, 9);
    h.push(55);
    while (h.size() > 0) {
        cout << h.peek() << ' ';
        h.pop();
    }
    cout << endl;
}