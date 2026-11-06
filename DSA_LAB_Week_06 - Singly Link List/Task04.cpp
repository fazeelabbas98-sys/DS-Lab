#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = nullptr;
    }
};

class Hospital {
private:
    Node* head;

public:
    Hospital() {
        head = nullptr;
    }

    // Add Patient
    void addPatient(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            cout << "Patient added!" << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;

        cout << "Patient added!" << endl;
    }

    // Remove Patient by Name
    void removePatient(string name) {
        if (head == nullptr) {
            cout << "No patients available!" << endl;
            return;
        }

        if (head->name == name) {
            Node* temp = head;
            head = head->next;

            delete temp;

            cout << "Patient cancelled!" << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr &&
            temp->next->name != name) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Patient not found!" << endl;
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;

        delete del;

        cout << "Patient cancelled!" << endl;
    }

    // Display Patients
    void displayPatients() {
        Node* temp = head;

        if (temp == nullptr) {
            cout << "No patients in waiting list!" << endl;
            return;
        }

        cout << "\nHospital Waiting List:\n";

        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    // Count Patients
    void countPatients() {
        Node* temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total Patients: " << count << endl;
    }

    ~Hospital() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Hospital h;

    // Adding Sample Patients
    h.addPatient("Ali");
    h.addPatient("Ahmed");
    h.addPatient("Sara");
    h.addPatient("Usman");

    // Display
    h.displayPatients();

    // Cancel Patient
    h.removePatient("Ahmed");

    // Display Updated List
    h.displayPatients();

    // Count Patients
    h.countPatients();

    return 0;
}