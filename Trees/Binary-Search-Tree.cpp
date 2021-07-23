#include <bits/stdc++.h>

using namespace std;

template<class t>

class BST {
private:
    struct Node {
        t data;
        Node *left;
        Node *right;

        Node(t value) {
            data = value;
            left = right = nullptr;
        }
    };

    Node *root = nullptr;


    void addHelper(Node *temp, t value) {
        if (value <= temp->data) {
            if (temp->left == nullptr) {
                temp->left = new Node(value);
            } else {
                addHelper(temp->left, value);
            }
        } else {
            if (temp->right == nullptr) {
                temp->right = new Node(value);
            } else {
                addHelper(temp->right, value);
            }
        }
    }

    t getMaxHelper(Node *temp) {
        if (temp->right == nullptr) {
            return temp->data;
        } else {
            return getMaxHelper(temp->right);
        }
    }

    t getMinHelper(Node *temp) {
        if (temp->left == nullptr) {
            return temp->data;
        } else {
            return getMaxHelper(temp->left);
        }
    }

public:
    void add(t value) {
        if (root == NULL) {
            root = new Node(value);

        } else {
            //We pass root in argument because temp will point on root
            addHelper(root, value);
        }
    }

    t getMax() {
        return getMaxHelper(root);
    }

    t getMin() {
        return getMinHelper(root);
    }

};


int main() {
    BST<int> bst;
    bst.add(1);
    bst.add(2);
    bst.add(1231);
    bst.add(10);
    bst.add(15);
    bst.add(20);

    cout << bst.getMax() << " " << bst.getMin();

}
