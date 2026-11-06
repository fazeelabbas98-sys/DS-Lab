#include <iostream>
#include <string>
using namespace std;

// Abstract Queue Class
template <class T>
class Queue {
protected:
    T* arr;
    int maxSize;
    int currentSize;

public:
    Queue(int size) {
        maxSize = size;
        currentSize = 0;
        arr = new T[maxSize];
    }

    virtual void enqueue(T data) = 0;
    virtual T dequeue() = 0;
    virtual T peek() = 0;
    virtual bool isFull() = 0;
    virtual bool isEmpty() = 0;

    virtual ~Queue() {
        delete[] arr;
    }
};

// Booking Structure
struct Booking {
    int customerID;
    string customerName;
    int numberOfTickets;
};

// Derived Circular Queue
class MyQueue : public Queue<Booking> {
private:
    int front;
    int rear;

public:
    MyQueue(int size) : Queue<Booking>(size) {
        front = 0;
        rear = -1;
    }

    bool isEmpty() override {
        return currentSize == 0;
    }

    bool isFull() override {
        return currentSize == maxSize;
    }

    // Enqueue Booking
    void enqueue(Booking b) override {
        if (isFull()) {
            cout << "Queue Overflow! No seats available.\n";
            return;
        }

        rear = (rear + 1) % maxSize;
        arr[rear] = b;
        currentSize++;

        cout << "Booking successful!\n";
    }

    // Dequeue Booking
    Booking dequeue() override {
        if (isEmpty()) {
            cout << "Queue Underflow! No bookings available.\n";
            return {};
        }

        Booking b = arr[front];

        front = (front + 1) % maxSize;
        currentSize--;

        return b;
    }

    // Peek Booking
    Booking peek() override {
        if (isEmpty()) {
            cout << "No booking available!\n";
            return {};
        }

        return arr[front];
    }

    // Display All Bookings
    void display() {
        if (isEmpty()) {
            cout << "No bookings available!\n";
            return;
        }

        cout << "\n===== ALL BOOKINGS =====\n";

        for (int i = 0; i < currentSize; i++) {
            int index = (front + i) % maxSize;

            cout << "Customer ID: "
                << arr[index].customerID << endl;

            cout << "Customer Name: "
                << arr[index].customerName << endl;

            cout << "Tickets: "
                << arr[index].numberOfTickets << endl;

            cout << "----------------------\n";
        }
    }

    void countBookings() {
        cout << "Total Bookings: "
            << currentSize << endl;
    }
};

int main() {
    int size, choice;

    cout << "Enter Maximum Queue Size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid queue size!\n";
        return 0;
    }

    MyQueue q(size);

    do {
        cout << "\n===== CINEMA BOOKING SYSTEM =====\n";
        cout << "1. Book Tickets\n";
        cout << "2. Cancel First Booking\n";
        cout << "3. Display Next Booking\n";
        cout << "4. Display All Bookings\n";
        cout << "5. Count Bookings\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            Booking b;

            cout << "Enter Customer ID: ";
            cin >> b.customerID;

            cin.ignore();

            cout << "Enter Customer Name: ";
            getline(cin, b.customerName);

            cout << "Enter Number of Tickets: ";
            cin >> b.numberOfTickets;

            if (b.numberOfTickets <= 0) {
                cout << "Invalid ticket quantity!\n";
                break;
            }

            q.enqueue(b);
            break;
        }

        case 2: {
            if (!q.isEmpty()) {
                Booking b = q.dequeue();

                cout << "Booking Cancelled!\n";
                cout << "Customer: "
                    << b.customerName << endl;
            }
            else {
                q.dequeue();
            }
            break;
        }

        case 3: {
            if (!q.isEmpty()) {
                Booking b = q.peek();

                cout << "\nNext Booking:\n";
                cout << "Customer ID: "
                    << b.customerID << endl;

                cout << "Name: "
                    << b.customerName << endl;

                cout << "Tickets: "
                    << b.numberOfTickets << endl;
            }
            else {
                q.peek();
            }
            break;
        }

        case 4:
            q.display();
            break;

        case 5:
            q.countBookings();
            break;

        case 6:
            cout << "Program Exited!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}