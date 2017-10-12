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

/**
 * The node representing the hash element
 **/
struct HNode {
    int loc = 0;
    string name;
    HNode *next = NULL;
};

class HS {
private:
    HNode *data[200004] = {0};
    hash<string> hash_fn;
public:
    ~HS() {
        for (int i = 0; i < 200004; i++) {
            HNode *entry = data[i];
            while (entry != NULL) {
                HNode *prev = entry;
                entry = entry-> next;
                delete prev;
            }
            data[i] = NULL;
        }
    }

    int & operator [](string s) {
        int locID = hash_fn(s) % 200004;
        HNode *loc = data[locID];
        HNode *prev = NULL;

        while (loc != NULL) {  // Hash matches, so find the end of the list.
            if (loc -> name == s)  // If the data matches, return it.
                break;
            prev = loc;
            loc = loc -> next;
        }

        if (loc == NULL) {  // If still nothing at end, create new node.
            loc = new HNode();
            loc -> name = s;
            if (prev != NULL) {
                prev -> next = loc;
            }
        }
        if (data[locID] == NULL) 
            data[locID] = loc;
        return loc -> loc;
    }

};

class PQ {
private:
    Schedule *values[200004] = {0};
    HS locMap;  // Map the woman's name to the location of the array.
    int length = 1;
    int counter = 0;
    void shiftUp(int index) {
        while (index > 1 && index < length) {
            int parent = index >> 1;
            if (*(values[parent]) < *(values[index])) {
                locMap[values[parent] -> name] = index;
                locMap[values[index] -> name] = parent;
                swap(values[parent], values[index]);
            }
            index = parent;
        }
    }
    void shiftDown(int index) {
        while (index > 0 && index < length) {
            int left_id = index << 1;
            int right_id = left_id + 1;
            if (left_id >= length) break;  // Already at leaf 
            int higher_id = (values[right_id] != NULL && *(values[left_id]) < *(values[right_id])) ? right_id : left_id;
            if (*(values[index]) < *(values[higher_id])) {
                locMap[values[higher_id] -> name] = index;
                locMap[values[index] -> name] = higher_id;
                swap(values[higher_id], values[index]);                
            }
            index = higher_id;
        }
    }
public:
    PQ() {
    }
    void push(Schedule *data) {
        values[length] = data;
        locMap[data -> name] = length++;
        shiftUp(length - 1);
    }
    bool empty() {
        return length <= 1;
    }
    Schedule* top() {
        return values[1];
    }
    void pop() {
        delete values[1];
        values[1] = values[--length];
        values[length] = NULL;
        shiftDown(1);
    }
    void print() {
        cout << "Size: " << length << " | ";
        for (int i = 1; i < length; i++) {
            // if (locMap[values[i] -> name] != i)
            cout << "{" << i << "," << (locMap[values[i] -> name] == i) << ": " << values[i] -> name << " [" << values[i] -> id << "] -> " << values[i] -> dilation << "} " << endl;
        }
        cout << endl;
    }
    void ArriveAtHospital(string womanName, int dilation) {
        Schedule *s = new Schedule(womanName, counter++, dilation);
        push(s);
    }
    void UpdateDilation(string womanName, int dilation) {
        int location = locMap[womanName];
        Schedule *s = values[location];
        values[location] = values[--length];
        locMap[values[location] -> name] = location;
        values[length] = NULL;
        if (location > 1 && location < length && *(values[location >> 1]) < *(values[location])) {
            shiftUp(location);
        }
        else {
            shiftDown(location);
        }
        s -> dilation += dilation;
        push(s);
    }
    void GiveBirth(string womanName) {
        int location = locMap[womanName];
        Schedule *s = values[location];
        values[location] = values[--length];
        locMap[values[location] -> name] = location;
        delete s;
        values[length] = NULL;
        if (location > 1 && location < length && *(values[location >> 1]) < *(values[location]))
            shiftUp(location);
        else
            shiftDown(location);
    }
    string Query() {
        if (length > 1)
            return values[1] -> name;
        else
            return "The delivery suite is empty";
    }
};

int main() {
    //freopen("PS3/input.txt", "r", stdin);
    int instructions, instruction, val;
    string name;
    PQ data;
    cin >> instructions;
    while (instructions--) {
        cin >> instruction;
        // cout << "Operation: "; 
        switch (instruction) {
            case 0: cin >> name >> val;
                    // cout << "Insert | " << name << " = " << val << endl;
                    data.ArriveAtHospital(name, val);
                    break;
            case 1: cin >> name >> val;
                    // cout << "Update | " << name << " + " << val << endl;
                    data.UpdateDilation(name, val);
                    break;
            case 2: cin >> name;
                    // cout << "Delete | " << name << endl;
                    data.GiveBirth(name);
                    break;
            case 3: 
                    // cout << "Query  | ";
                    cout << data.Query() << endl;
                    break;
            default: break;
        };
        // cout << instruction << endl;
        // if (rand() % 1000 == 0)
            // data.print();
    }
    //data.print();
}