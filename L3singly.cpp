/*
id: 22011763
name: Aqil Muqriz Bin Mohd Khairul Hasni
lab group: G1
lab: L3 (Singly)
*/

#include <string>
#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
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

    void add_element(Node* newNode) {
        if (!newNode) return;

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next_ptr = newNode;
            tail = newNode;
        }
    }

    void display_list() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }

    void delete_by_value(string val) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->name == val) {
                if (prev == nullptr) {
                    head = current->next_ptr;
                    delete current;
                    current = head;
                } else {
                    prev->next_ptr = current->next_ptr;
                    if (current == tail) {
                        tail = prev;
                    }
                    delete current;
                    current = prev->next_ptr;
                }
            } else {
                prev = current;
                current = current->next_ptr;
            }
        }

        if (head == nullptr) {
            tail = nullptr;
        }
    }

    Node* get_head() const {
        return head;
    }
};

int main() {
    LinkedList linkedlst;

    linkedlst.add_element(new Node("Ali"));
    linkedlst.add_element(new Node("Ahmed"));
    linkedlst.add_element(new Node("Abu"));

    cout << "Original list: ";
    linkedlst.display_list();

    linkedlst.delete_by_value("Ahmed");
    cout << "After deleting Ahmed: ";
    linkedlst.display_list();

    Node* current = linkedlst.get_head();
    while (current) {
        Node* temp = current;
        current = current->next_ptr;
        delete temp;
    }

    return 0;
}