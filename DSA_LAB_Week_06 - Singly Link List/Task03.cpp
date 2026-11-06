#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at Specific Position
    void insertPosition(int value, int pos) {
        if (pos < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(value);

        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1; i++) {
            if (temp == nullptr) {
                cout << "Invalid position!" << endl;
                delete newNode;
                return;
            }

            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Node inserted!" << endl;
    }

    // Delete at Specific Position
    void deletePosition(int pos) {
        if (head == nullptr || pos < 1) {
            cout << "Invalid operation!" << endl;
            return;
        }

        Node* temp = head;

        if (pos == 1) {
            head = head->next;
            delete temp;

            cout << "Node deleted!" << endl;
            return;
        }

        for (int i = 1; i < pos - 1; i++) {
            if (temp == nullptr) {
                cout << "Invalid position!" << endl;
                return;
            }

            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;

        delete del;

        cout << "Node deleted!" << endl;
    }

    // Search Element
    void search(int value) {
        Node* temp = head;
        int pos = 1;

        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Element found at position "
                    << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "Element not found!" << endl;
    }

    // Count Nodes
    void countNodes() {
        Node* temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total Nodes: " << count << endl;
    }

    // Display
    void display() {
        Node* temp = head;

        if (temp == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int choice, value, pos;

    do {
        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Insert at Position\n";
        cout << "2. Delete at Position\n";
        cout << "3. Search Element\n";
        cout << "4. Count Nodes\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Value: ";
            cin >> value;

            cout << "Enter Position: ";
            cin >> pos;

            list.insertPosition(value, pos);
            break;

        case 2:
            cout << "Enter Position: ";
            cin >> pos;

            list.deletePosition(pos);
            break;

        case 3:
            cout << "Enter Value to Search: ";
            cin >> value;

            list.search(value);
            break;

        case 4:
            list.countNodes();
            break;

        case 5:
            list.display();
            break;

        case 6:
            cout << "Program Exited!" << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}