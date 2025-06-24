/*
id: 22011763
name: Aqil Muqriz Bin Mohd Khairul Hasni
lab group: G1
lab: L3 (Doubly)
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;
    Node* prev_ptr;

    Node(string name) {
        this->name = name;
        this->next_ptr = nullptr;
        this->prev_ptr = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_element(Node* newNode) {
        if (!newNode) return;

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next_ptr = newNode;
            newNode->prev_ptr = tail;
            tail = newNode;
        }
    }

    void display_list() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << " <-> ";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }

    void delete_by_value(string val) {
        Node* current = head;

        while (current != nullptr) {
            if (current->name == val) {
                if (current == head) {
                    head = current->next_ptr;
                    if (head) head->prev_ptr = nullptr;
                } else {
                    current->prev_ptr->next_ptr = current->next_ptr;
                }

                if (current == tail) {
                    tail = current->prev_ptr;
                    if (tail) tail->next_ptr = nullptr;
                } else if (current->next_ptr) {
                    current->next_ptr->prev_ptr = current->prev_ptr;
                }

                Node* toDelete = current;
                current = current->next_ptr;
                delete toDelete;
            } else {
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
    DoublyLinkedList dll;

    dll.add_element(new Node("Ali"));
    dll.add_element(new Node("Ahmed"));
    dll.add_element(new Node("Abu"));

    cout << "Original list: ";
    dll.display_list();

    dll.delete_by_value("Ahmed");
    cout << "After deleting Ahmed: ";
    dll.display_list();

    Node* current = dll.get_head();
    while (current) {
        Node* temp = current;
        current = current->next_ptr;
        delete temp;
    }

    return 0;
}