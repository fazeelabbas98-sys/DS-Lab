#include <iostream>
#include <string>
using namespace std;

struct Customer {
    string name;
    string transaction;
};

class BankQueue {
private:
    Customer* arr;
    int maxSize;
    int front;
    int rear;
    int currentSize;

public:
    BankQueue(int size) {
        maxSize = size;
        arr = new Customer[maxSize];
        front = 0;
        rear = -1;
        currentSize = 0;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == maxSize;
    }

    // Add Customer
    void enqueue(Customer c) {
        if (isFull()) {
            cout << "Queue Overflow! Bank queue is full.\n";
            return;
        }

        rear = (rear + 1) % maxSize;
        arr[rear] = c;
        currentSize++;

        cout << "Customer added successfully!\n";
    }

    // Serve Customer
    Customer dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No customer available.\n";
            return { "", "" };
        }

        Customer c = arr[front];

        front = (front + 1) % maxSize;
        currentSize--;

        return c;
    }

    // Display Customers
    void display() {
        if (isEmpty()) {
            cout << "No customers waiting!\n";
            return;
        }

        cout << "\nBank Waiting Queue:\n";

        for (int i = 0; i < currentSize; i++) {
            int index = (front + i) % maxSize;

            cout << "Name: " << arr[index].name
                << " | Transaction: "
                << arr[index].transaction << endl;
        }
    }

    // Count Customers
    void countCustomers() {
        cout << "Total Waiting Customers: "
            << currentSize << endl;
    }

    ~BankQueue() {
        delete[] arr;
    }
};

int main() {
    int size, choice;

    cout << "Enter Queue Size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid queue size!\n";
        return 0;
    }

    BankQueue q(size);

    do {
        cout << "\n===== BANK QUEUE SYSTEM =====\n";
        cout << "1. Add Customer\n";
        cout << "2. Serve Customer\n";
        cout << "3. Display Customers\n";
        cout << "4. Count Customers\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            Customer c;

            cin.ignore();

            cout << "Enter Customer Name: ";
            getline(cin, c.name);

            cout << "Enter Transaction Type: ";
            getline(cin, c.transaction);

            q.enqueue(c);
            break;
        }

        case 2: {
            if (!q.isEmpty()) {
                Customer c = q.dequeue();

                cout << "Customer Served: "
                    << c.name << endl;

                cout << "Transaction: "
                    << c.transaction << endl;
            }
            else {
                q.dequeue();
            }
            break;
        }

        case 3:
            q.display();
            break;

        case 4:
            q.countCustomers();
            break;

        case 5:
            cout << "Program Exited!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}