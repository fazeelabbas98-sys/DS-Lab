#include <iostream>
#include <string>
using namespace std;

class StudentNode {
public:
    string name;
    int priority;
    StudentNode* next;

    StudentNode(string n, int p) {
        name = n;
        priority = p;
        next = nullptr;
    }
};

class Book {
private:
    string bookName;
    StudentNode* head;

public:
    Book(string name) {
        bookName = name;
        head = nullptr;
    }

    // Add Student according to Priority
    void addStudent(string name, int priority) {
        if (priority < 1 || priority > 3) {
            cout << "Invalid priority!" << endl;
            return;
        }

        StudentNode* newNode =
            new StudentNode(name, priority);

        // Insert at Beginning
        if (head == nullptr ||
            priority < head->priority) {

            newNode->next = head;
            head = newNode;

            cout << name << " added successfully!" << endl;
            return;
        }

        StudentNode* temp = head;

        // Maintain priority order
        while (temp->next != nullptr &&
            temp->next->priority <= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << name << " added successfully!" << endl;
    }

    // Remove Student by Name
    void removeStudent(string name) {
        if (head == nullptr) {
            cout << "Reservation list is empty!" << endl;
            return;
        }

        if (head->name == name) {
            StudentNode* temp = head;
            head = head->next;

            delete temp;

            cout << "Reservation cancelled!" << endl;
            return;
        }

        StudentNode* temp = head;

        while (temp->next != nullptr &&
            temp->next->name != name) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Student not found!" << endl;
            return;
        }

        StudentNode* del = temp->next;
        temp->next = del->next;

        delete del;

        cout << "Reservation cancelled!" << endl;
    }

    // Update Student Priority
    void updatePriority(string name, int newPriority) {
        if (newPriority < 1 || newPriority > 3) {
            cout << "Invalid priority!" << endl;
            return;
        }

        StudentNode* temp = head;

        while (temp != nullptr && temp->name != name) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Student not found!" << endl;
            return;
        }

        // Remove old node
        int oldPriority = temp->priority;

        removeStudent(name);

        // Add again with new priority
        addStudent(name, newPriority);

        cout << "Priority updated from "
            << oldPriority << " to "
            << newPriority << endl;
    }

    // Display Reservation List
    void display() {
        StudentNode* temp = head;

        cout << "\nBook: " << bookName << endl;

        if (temp == nullptr) {
            cout << "No reservations!" << endl;
            return;
        }

        cout << "Reservation List:\n";

        while (temp != nullptr) {
            cout << temp->name
                << " (Priority: "
                << temp->priority << ") -> ";

            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    // Count Students
    void countStudents() {
        StudentNode* temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total Students: " << count << endl;
    }

    // Issue Book to First Student
    void issueBook() {
        if (head == nullptr) {
            cout << "No student waiting for this book!" << endl;
            return;
        }

        StudentNode* temp = head;

        cout << "Book issued to: "
            << temp->name << endl;

        head = head->next;

        delete temp;
    }

    ~Book() {
        while (head != nullptr) {
            StudentNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {

    // Two Different Books
    Book book1("Programming");
    Book book2("Data Structures");

    // Book 1 Reservations
    cout << "\n===== BOOK 1 =====\n";

    book1.addStudent("Ali", 3);
    book1.addStudent("Ahmed", 1);
    book1.addStudent("Sara", 2);

    book1.display();
    book1.countStudents();

    // Update Priority
    cout << "\nUpdating Priority:\n";

    book1.updatePriority("Ali", 1);

    book1.display();

    // Cancel Reservation
    cout << "\nCancelling Reservation:\n";

    book1.removeStudent("Sara");

    book1.display();
    book1.countStudents();

    // Return Book
    cout << "\nBook Returned:\n";

    book1.issueBook();

    book1.display();

    // Book 2 Reservations
    cout << "\n===== BOOK 2 =====\n";

    book2.addStudent("Usman", 2);
    book2.addStudent("Ayesha", 1);
    book2.addStudent("Hassan", 3);

    book2.display();
    book2.countStudents();

    // Issue Book 2
    cout << "\nBook Returned:\n";

    book2.issueBook();

    book2.display();

    return 0;
}