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
                addHelper(std::ref(temp), value);
            }
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
    
};


int main() {
    BST<int> bst;
    bst.add(15);
    bst.add(10);
    bst.add(20);

}
