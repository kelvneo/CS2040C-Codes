#include <bits/stdc++.h>
using namespace std;

class PQ {
private:
    int values[100000] = {0};
    int length = 1;
public:
    void push(int data) {
        values[length++] = data;
        int i = length - 1;
        while (i > 1 && values[i >> 1] < values[i]) {
            swap(values[i >> 1], values[i]);
            i >>= 1;
        }
    }
    bool empty() {
        return length <= 1;
    }
    int top() {
        return values[1];
    }
    void pop() {
        values[1] = values[--length];
        values[length] = 0;
        int i = 1;
        while (i < length) {
            int leftid = i << 1;
            int rightid = leftid + 1;
            int higherid = values[leftid] < values[rightid] ? rightid : leftid;
            if (values[i] < values[higherid]) {
                swap(values[i], values[higherid]);
            } 
            i = higherid;
        }
    }
    void print() {
        for (int i = 1; i < length; i++) {
            cout << values[i] << ' ';
        }
        cout << endl;
    }
};

struct Node {
    int value;
    Node *next;
};

class S {
private:
    Node *head = 0;
    int length = 0;
public:
    void push(int data) {
        Node *newhead = new Node;
        newhead -> next = head;
        newhead -> value = data;
        head = newhead;
        length++;
    }
    bool empty() {
        return length <= 0;
    }
    int top() {
        return head -> value;
    }
    void pop() {
        Node *tmp = head;
        head = tmp -> next;
        delete tmp;
        length--;
    }
    void clear() {
        int len = length;
        for (int i = 0; i < len; i++) {
            pop();
        }
    }
};

class Q {
private:
    Node *head = 0;
    Node *tail = 0;
    int length = 0;
public:
    void push(int data) {
        Node *newtail = new Node;
        newtail -> next = 0;
        newtail -> value = data;
        if (length != 0)
            tail -> next = newtail;
        else {
            head = newtail;
        }
        tail = newtail;
        length++;
    }
    bool empty() {
        return length <= 0;
    }
    int front() {
        return head -> value;
    }
    int end() {
        return tail -> value;
    }
    void pop() {
        Node *tmp = head;
        head = tmp -> next;
        delete tmp;
        length--;
    }
    void clear() {
        int len = length;
        for (int i = 0; i < len; i++) {
            pop();
        }
    }
};

int main() {
    //freopen("PS2/input.txt", "r", stdin);
    int cases;
    while (cin >> cases && cases != 0) {
        Q qdata;
        S sdata;
        PQ pqdata;
        int command, value;
        bool isstack = true, isqueue = true, ispqueue = true;
        for (int i = 0; i < cases; i++) {
            cin >> command >> value;
            if (command == 1) {
                if (isqueue)
                    qdata.push(value);
                if (isstack)
                    sdata.push(value);
                if (ispqueue)
                    pqdata.push(value);
            } else {
                if (isstack && (sdata.empty() || sdata.top() != value))
                    isstack = false;
                else
                    sdata.pop();
                if (isqueue && (qdata.empty() || qdata.front() != value))
                    isqueue = false;
                else
                    qdata.pop();
                if (ispqueue && (pqdata.empty() || pqdata.top() != value))
                    ispqueue = false;
                else
                    pqdata.pop();
            }
        }
        if (isstack && (isqueue || ispqueue) || (isqueue && ispqueue)) {
            cout << "not sure" << endl;
        } else if (isstack && !(isqueue || ispqueue)) {
            cout << "stack" << endl;
        } else if (isqueue && !(isstack || ispqueue)) {
            cout << "queue" << endl;
        } else if (ispqueue && !(isstack || isqueue)) {
            cout << "priority queue" << endl;
        } else {
            cout << "impossible" << endl;
        }
        qdata.clear();
        sdata.clear();
    }
}