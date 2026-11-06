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

// Print Job Structure
struct PrintJob {
    int jobID;
    string userName;
    int pages;
};

// Derived Circular Queue
class MyQueue : public Queue<PrintJob> {
private:
    int front;
    int rear;

public:
    MyQueue(int size) : Queue<PrintJob>(size) {
        front = 0;
        rear = -1;
    }

    bool isEmpty() override {
        return currentSize == 0;
    }

    bool isFull() override {
        return currentSize == maxSize;
    }

    // Add Print Job
    void enqueue(PrintJob p) override {
        if (isFull()) {
            cout << "Queue Overflow! Printer queue is full.\n";
            return;
        }

        rear = (rear + 1) % maxSize;
        arr[rear] = p;
        currentSize++;

        cout << "Print Job Submitted Successfully!\n";
    }

    // Process Print Job
    PrintJob dequeue() override {
        if (isEmpty()) {
            cout << "Queue Underflow! No print jobs available.\n";
            return {};
        }

        PrintJob p = arr[front];

        front = (front + 1) % maxSize;
        currentSize--;

        return p;
    }

    // Display Next Print Job
    PrintJob peek() override {
        if (isEmpty()) {
            cout << "No pending print jobs!\n";
            return {};
        }

        return arr[front];
    }

    // Display All Jobs
    void display() {
        if (isEmpty()) {
            cout << "No pending print jobs!\n";
            return;
        }

        cout << "\n===== PENDING PRINT JOBS =====\n";

        for (int i = 0; i < currentSize; i++) {
            int index = (front + i) % maxSize;

            cout << "Job ID: "
                << arr[index].jobID << endl;

            cout << "User Name: "
                << arr[index].userName << endl;

            cout << "Total Pages: "
                << arr[index].pages << endl;

            cout << "----------------------\n";
        }
    }

    // Count Pending Jobs
    void countJobs() {
        cout << "Total Pending Jobs: "
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
        cout << "\n===== PRINTER JOB SYSTEM =====\n";
        cout << "1. Submit New Print Job\n";
        cout << "2. Process Next Print Job\n";
        cout << "3. Display Next Print Job\n";
        cout << "4. Display All Pending Jobs\n";
        cout << "5. Count Pending Jobs\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            PrintJob p;

            cout << "Enter Job ID: ";
            cin >> p.jobID;

            cin.ignore();

            cout << "Enter User Name: ";
            getline(cin, p.userName);

            cout << "Enter Number of Pages: ";
            cin >> p.pages;

            if (p.pages <= 0) {
                cout << "Invalid number of pages!\n";
                break;
            }

            q.enqueue(p);
            break;
        }

        case 2: {
            if (!q.isEmpty()) {
                PrintJob p = q.dequeue();

                cout << "\nPrint Job Completed!\n";

                cout << "Job ID: "
                    << p.jobID << endl;

                cout << "User Name: "
                    << p.userName << endl;

                cout << "Pages Printed: "
                    << p.pages << endl;
            }
            else {
                q.dequeue();
            }
            break;
        }

        case 3: {
            if (!q.isEmpty()) {
                PrintJob p = q.peek();

                cout << "\nNext Print Job:\n";

                cout << "Job ID: "
                    << p.jobID << endl;

                cout << "User Name: "
                    << p.userName << endl;

                cout << "Pages: "
                    << p.pages << endl;
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
            q.countJobs();
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