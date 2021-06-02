#include <bits/stdc++.h>

//Created by @amrhossamdev
using namespace std;

template<class t>
class LinkedList {
    struct Node {
        t item;
        Node *next;
    };
    // first item will not have next node
    Node *head = nullptr;
public:
    void append(int val) {
        Node *newNode = new Node; // reserved place in memory
        newNode->item = val; // assign item to node
        newNode->next = nullptr; // always null because last item have no address

        if (isEmpty()) { // special case if the node is empty & this will be the first item
            head = newNode; //head now point @the new node
        } else {
            Node *temp = head; // temp pointing at first element
            //start lopping till we found a null address
            while (temp->next != nullptr) {
                // temp will point at the next node till we found a null address then loop will stop
                temp = temp->next;
            }
            // congrats we reached the last element now we can connect our newNode to it
            temp->next = newNode;
        }
    }

    void append(int val, int pos) {
        Node *newNode = new Node;
        newNode->item = val;
        newNode->next = NULL;
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp->next != NULL; ++i) {
            // getting the last node before the position we want to insert
            // to make the newNode point at the nextNode to make the insert operation done
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;

    }

    void removeAt(int pos) {
        if (!isEmpty()) {
            Node *temp, *temp2;
            temp = temp2 = head;
            if (pos == 0) {
                head = temp->next;
                delete temp;
                return;
            } else {
                for (int i = 0; i < pos - 1 && temp->next != NULL; ++i) {
                    temp = temp->next;
                }
                if (temp->next == NULL) return; // if the user enter pos not in range of the linkedlist

                temp2 = temp->next; // pointing at the node we want to delete actually
                temp->next = temp->next->next; // we are getting the node next to the node we want to delete
                //then i will delete our the node we want to delete at the temp2
                delete temp2;
            }
        }
    }

    void remove(int val) {
        if (!isEmpty()) {
            Node *temp, *prev;
            prev = temp = head; // first they pointing at the first item

            // if the value we need to delete in the first of the linked list /*SPECIAL CASE*/
            if (temp->item == val) {
                head = temp->next;
                delete temp;
                return;
            }
            while (temp != NULL && temp->item != val) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL) { // we didn't found the item, so thanks for remove method !
                return;
            } else {
                //prev will now start pointing at the temp's next
                prev->next = temp->next;
                delete temp;
            }

        }
    }

    void display() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->item << " ";
            temp = temp->next;
        }
    }

    int size() {
        Node *temp = head;
        int size = 0;
        while (temp != nullptr) {
            temp = temp->next;
            size++;
        }
        return size;
    }

    void reverse() {
        if (!isEmpty()) {
            Node *curr, *prev, *next;
            prev = next = NULL;
            curr = head;
            while (curr != NULL) {
                next = curr->next; // saving the curr next
                curr->next = prev;  // cutting link
                prev = curr;  // change the link
                curr = next;
            }
            head = prev;
        }
    }

    bool isEmpty() {
        if (head == nullptr) return true;
        return false;
    }
    
};

int main() {
    LinkedList<int> list;
    list.append(1); // 0
    list.append(2); // 1
    list.append(3); // 2
    list.append(4); // 3
    list.display();
 

    return 0;
}

