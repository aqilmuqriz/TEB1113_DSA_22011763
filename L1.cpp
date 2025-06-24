/*
id: 22011763
name: aqil
group: g1
lab: L1
*/

#include <iostream>
#include <string>
using namespace std;

struct Student {

    int id;
    string name;
    string email;
    string phone;
    float gpa;

};

int main() {

    const int SIZE = 5;
    Student students[SIZE];         
    Student* ptr = students;        

    cout << "Enter details for " << SIZE << " students:\n";

    // Input using pointer
    for (int i = 0; i < SIZE; i++) {

        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Enter ID: ";
        cin >> (ptr + i)->id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, (ptr + i)->name);

        cout << "Enter Email: ";
        getline(cin, (ptr + i)->email);

        cout << "Enter Phone Number: ";
        getline(cin, (ptr + i)->phone);

        cout << "Enter GPA: ";
        cin >> (ptr + i)->gpa;
        cin.ignore();

    }

    cout << "\nStudent Database:\n";
    cout << "------------------------------------------------------\n";
    for (int i = 0; i < SIZE; i++) {

        cout << "Student " << i + 1;
        cout << "\nID: " << (ptr + i)->id;
        cout << "\nName: " << (ptr + i)->name;
        cout << "\nEmail: " << (ptr + i)->email;
        cout << "\nPhone: " << (ptr + i)->phone;
        cout << "\nGPA: " << (ptr + i)->gpa;
        cout << "\n------------------------------------------------------\n";
        
    }

    return 0;
}
