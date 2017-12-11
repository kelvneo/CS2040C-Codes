#include <bits/stdc++.h>
using namespace std;

struct TNode {
	TNode *parent, *left, *right;
	string key;
	int height = 0;
	int size = 0;
};

class Tree {
protected:
	TNode *root;
	string TNodeToKey(TNode *v) { return v == NULL ? "" : v -> key; }
	int h(TNode *v) { return v == NULL ? -1 : v -> height; }
	int size(TNode *v) { return v == NULL ? 0 : v -> size; }
	void inorder(TNode* T) {
		if (T == NULL) return;
		inorder(T->left);
		cout << T -> key << ' ';
		inorder(T->right);
	  }
	TNode *findMinNode(TNode *v) {
		if (v == NULL || v -> left == NULL) return v;
		else return findMinNode(v -> left);
	}
	string findMin() {
		return TNodeToKey(findMinNode(root));
	}
	TNode *findMaxNode(TNode *v) {
		if (v == NULL || v -> right == NULL) return v;
		else return findMaxNode(v -> right);
	}
	string findMax() {
		return TNodeToKey(findMaxNode(root));
	}
	TNode *successorNode(TNode *v) {
		if (v == NULL) return NULL;
		else if (v -> right != NULL) return findMinNode(v -> right);
		else {
			TNode *p = v -> parent;
			while (p != NULL && p -> right == v) {
				v = p;
				p = v -> parent;	
			}
			return p;
		}
	}
	string successor(TNode *v) {
		return TNodeToKey(successorNode(v));
	}
	TNode *predecessorNode(TNode *v) {
		if (v == NULL) return NULL;
		else if (v -> left != NULL) return findMaxNode(v -> left);
		else {
			TNode *p = v -> parent;
			while (p != NULL && p -> left == v) {
				v = p;
				p = v -> parent;
			}
			return p;
		}
	}
	string predecessor(TNode *v) {
		return TNodeToKey(predecessorNode(v));
	}
	TNode *rotateLeft(TNode *v) {
		TNode* p = v -> right;
		p -> parent = v -> parent;
		v -> parent = p;
		v -> right = p -> left;
		if (v -> right != NULL) v -> right -> parent = v;
		p -> left = v;

		v -> height = max(h(v -> left), h(v -> right)) + 1;
		p -> height = max(h(p -> left), h(p -> right)) + 1;
		v -> size = size(v -> left) + size(v -> right) + 1;
		p -> size = v -> size +  size(v -> right) + 1;
		return p;
	}
	TNode *rotateRight(TNode *v) {
		TNode* p = v -> left;
		p -> parent = v -> parent;
		v -> parent = p;
		v -> left = p -> right;
		if (v -> left != NULL) v -> left -> parent = v;
		p -> right = v;

		v -> height = max(h(v -> left), h(v -> right)) + 1;
		p -> height = max(h(p -> left), h(p -> right)) + 1;
		v -> size = size(v -> left) + size(v -> right) + 1;
		p -> size = v -> size +  size(v -> left) + 1;
		return p;
	}
	TNode *search(TNode *v, string key) {
		if (v == NULL) return v;
		else if (v -> key == key) return v;
		else if (v -> key < key) return search(v -> right, key);
		else return search(v -> left, key);
	}
	TNode *insert(TNode *v, string key) {
		if (v == NULL) {
			v = new TNode;
			v -> key = key;
			v -> parent = v -> left = v -> right = NULL;
		} else if (v -> key < key) {
			v -> right = insert(v -> right, key);
			v -> right -> parent = v;
		} else {
			v -> left = insert(v -> left, key);
			v -> left -> parent = v;
		}

		int bal = h(v -> left) - h(v -> right);
		if (bal == 2) {
			int bal2 = h(v -> left -> left) - h(v -> left -> right);
			if (bal2 == -1) v -> left = rotateLeft(v -> left);
			v = rotateRight(v);
		} else if (bal == -2) {
			int bal2 = h(v -> right -> left) - h(v -> right -> right);
			if (bal2 == 1) v -> right = rotateRight(v -> right);
			v = rotateLeft(v);
		}
		v -> height = max(h(v -> left), h(v -> right)) + 1;
		v -> size = size(v -> left) + size(v -> right) + 1;
		return v;
	}
	TNode *remove(TNode *v, string key) {
		if (v == NULL) return v;

		if (v -> key == key) {
			if (v -> left == NULL && v -> right == NULL) v = NULL;
			else if (v -> left == NULL && v -> right != NULL) {
				v -> right -> parent = v -> parent;
				v = v -> right;
			} else if (v -> left != NULL && v -> right == NULL) {
				v -> left -> parent = v -> parent;
				v = v -> left;
			} else {
				string sv = successor(v);
				v -> key = sv;
				v -> right = remove(v -> right, sv);
			}
		} else if (v -> key < key) {
			v -> right = remove(v -> right, key);
		} else {
			v -> left = remove(v -> left, key);
		}

		if (v != NULL) {
			int bal = h(v -> left) - h(v -> right);
			if (bal == 2) {
				int bal2 = h(v -> left -> left) - h(v -> left -> right);
				if (bal2 == -1)
					v -> left = rotateLeft(v -> left);
				v = rotateRight(v);
			} else if (bal == -2) {
				int bal2 = h(v -> right -> left) - h(v -> right -> right);
				if (bal2 == 1) v -> right = rotateRight(v -> right);
				v = rotateLeft(v);
			}
			v -> height = max(h(v -> left), h(v -> right)) + 1;
			v -> size = size(v -> left) + size(v -> right) + 1;
		}

		return v;
	}
	int rank(TNode *v, string key) {
		if (v == NULL) return 1;
		else if (v -> key == key) return size(v -> left) + 1;
		else if (v -> key < key) return size(v -> left) + 1 + rank(v -> right, key);
		else return rank(v -> left, key);
	}
public:
	Tree() { }
	void insert(string key) { root = insert(root, key);	}
	void remove(string key) { root = remove(root, key); }
	int distance(string a, string b) { return rank(root, b) - rank(root, a); }
	void inorder() {
		inorder(root);
		cout << endl;
	}
};

int Query(string START, string END, int gender, Tree &male_names, Tree &female_names);

int Query(string START, string END, int gender, Tree &male_names, Tree &female_names) {
	switch (gender) {
		case 0:
			return male_names.distance(START, END) + female_names.distance(START, END);
		case 1:
			return male_names.distance(START, END);
		case 2:
			return female_names.distance(START, END);
		default:
			return 0;
	}
}

int main() {
	//freopen("PS4/input.txt", "r", stdin);
	Tree male_names;
	Tree female_names;
	string a, b;
	int instruction, gender;
	while (1) {
		cin >> instruction;
		switch (instruction) {
			case 0: return 0;
			case 1:
				cin >> a >> gender;
				switch (gender) {
					case 1:
						male_names.insert(a);
						break;
					case 2:
						female_names.insert(a);
						break;
					default: break;
				}
				break;
			case 2:
				cin >> a;
				male_names.remove(a);
				female_names.remove(a);
				break;
			case 3:
				cin >> a >> b >> gender;
				cout << Query(a, b, gender, male_names, female_names) << endl;
				break;
			default:
				male_names.inorder();
				female_names.inorder();
				break;
		}
	}
	return 0;
}
