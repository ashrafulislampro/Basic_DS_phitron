#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            return -1; // Queue is empty
        }
        Node* delNode = head;
        int delValue = delNode->val;
        head = head->next;
        delete delNode;
        if (head == NULL) {
            tail = NULL; // Queue becomes empty
        }
        return delValue;
    }

    int front() {
        if (isEmpty()) {
            return -1; // Queue is empty
        }
        return head->val;
    }
};

int main() {
    int t, q, idx, val;
    cin >> t;
    while (t--) {
        Queue obj; // New queue for each test case
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> idx;
            if (idx == 1) {
                cin >> val;
                obj.enqueue(val);
            } else if (idx == 2) {
                cout << "Dequeued = " << obj.dequeue() << endl;
            } else if (idx == 3) {
                cout << "Front = " << obj.front() << endl;
            } else if (idx == 4) {
                cout << "Empty = " << obj.isEmpty() << endl;
            }
        }
    }
    return 0;
}
