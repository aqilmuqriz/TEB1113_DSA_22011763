#include <string>
#include <iostream>
using namespace std;

class Node{
public:
    string name;
    Node* next_ptr;

    Node(string name){
        this->name = name;
        this->next_ptr = nullptr;
    }
};

class LinkedList{
private:
    Node* head;
    Node* tail;

public:
    LinkedList(Node* node){
        head = node;
        tail = node;
    }

    void add_element(Node* newNode){
        tail->next_ptr = newNode;
        tail = newNode;
    }

    void display_list(){
        Node* current = head;
        while (current != nullptr){
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "NULL" << endl;
    }

    void delete_by_value(string val){
        Node* current = head; 
        Node* prev = nullptr;

        while (current != nullptr){
            if (current->name == val){
                if (prev == nullptr){
                    head = current->next_ptr;
                    delete current;
                    current = head;
                } else {
                    prev->next_ptr = current->next_ptr;
                    if (current == tail){
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
    }
};

int main(){
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmed");
    Node* node3 = new Node("Abu");

    LinkedList linkedlst(node1);

    linkedlst.add_element(node2);
    linkedlst.add_element(node3);

    

    linkedlst.display_list();
}