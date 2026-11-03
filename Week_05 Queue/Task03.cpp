
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class myQueue {
private:
    queue<int> q;

public:

    void enqueue(int value) {
        q.push(value);
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        int value = q.front();
        q.pop();
        return value;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }

        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }

    void display() {
        queue<int> temp = q;

        cout << "Queue: ";

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }

    void reverseFirstK(int k) {
        int n = q.size();

        if (k <= 1 || n == 0) {
            return;
        }

        if (k > n) {
            k = n;
        }

        stack<int> s;

        for (int i = 0; i < k; i++) {
            s.push(q.front());
            q.pop();
        }

        while (!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        int remaining = n - k;

        for (int i = 0; i < remaining; i++) {
            q.push(q.front());
            q.pop();
        }
    }
};

int main() {
    myQueue q;

    int n, value, k;

    cout << "Enter number of queue elements: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid queue size!" << endl;
        return 0;
    }

    cout << "Enter queue elements:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    cout << "\nOriginal ";
    q.display();

    cout << "\nEnter value of K: ";
    cin >> k;

    if (k < 0) {
        cout << "K cannot be negative!" << endl;
        return 0;
    }

    q.reverseFirstK(k);

    cout << "\nQueue after reversing first "
        << k << " elements:" << endl;

    q.display();

    return 0;
}
