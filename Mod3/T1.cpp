#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int initialData) {
        data = initialData;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        Node* currentNode = head;
        while (currentNode) {
            Node* toBeDeleted = currentNode;
            currentNode = currentNode->next;
            delete toBeDeleted;
        }
    }

    void Append(Node* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void Prepend(Node* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void InsertAfter(Node* currentNode, Node* newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else if (currentNode == tail) {
            tail->next = newNode;
            tail = newNode;
        }
        else {
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }

    void RemoveAfter(Node* currentNode) {
        if (currentNode == nullptr && head) {
            // Special case: remove head
            Node* nodeBeingRemoved = head;
            head = head->next;
            delete nodeBeingRemoved;

            if (head == nullptr) {
                // Last item was removed
                tail = nullptr;
            }
        }
        else if (currentNode->next) {
            Node* nodeBeingRemoved = currentNode->next;
            Node* succeedingNode = currentNode->next->next;
            currentNode->next = succeedingNode;
            delete nodeBeingRemoved;
            if (succeedingNode == nullptr) {
                // Remove tail
                tail = currentNode;
            }
        }
    }

    void PrintList() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "null" << endl;
    }
};

// Main function to test the LinkedList class
int main() {
    LinkedList myList;

    Node* node1 = new Node(15);
    Node* node2 = new Node(25);
    Node* node3 = new Node(35);

    cout << "Appending nodes:" << endl;
    myList.Append(node1);
    myList.Append(node2);
    myList.Append(node3);
    myList.PrintList(); // Expected: 10 -> 20 -> 30 -> null

    cout << "Prepending a node:" << endl;
    Node* node4 = new Node(5);
    myList.Prepend(node4);
    myList.PrintList(); // Expected: 5 -> 10 -> 20 -> 30 -> null

    cout << "Inserting after a node:" << endl;
    Node* node5 = new Node(15);
    myList.InsertAfter(node1, node5);
    myList.PrintList(); // Expected: 5 -> 10 -> 15 -> 20 -> 30 -> null

    cout << "Removing a node after another:" << endl;
    myList.RemoveAfter(node1);
    myList.PrintList(); // Expected: 5 -> 10 -> 20 -> 30 -> null

    return 0;
}