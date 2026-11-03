//
//#include <iostream>
//#include <stack>
//using namespace std;
//
//class myQueue {
//private:
//    stack<int> stack1;
//    stack<int> stack2;
//    void transfer() {
//        if (stack2.empty()) {
//            while (!stack1.empty()) {
//                stack2.push(stack1.top());
//                stack1.pop();
//            }
//        }
//    }
//
//public:
//    void enQueue(int value) {
//        stack1.push(value);
//        cout << value << " inserted successfully!" << endl;
//    }
//
//    int deQueue() {
//        transfer();
//
//        if (stack2.empty()) {
//            cout << "Queue is Empty!" << endl;
//            return -1;
//        }
//
//        int value = stack2.top();
//        stack2.pop();
//
//        return value;
//    }
//
//    int front() {
//        transfer();
//
//        if (stack2.empty()) {
//            cout << "Queue is Empty!" << endl;
//            return -1;
//        }
//
//        return stack2.top();
//    }
//
//    void display() {
//        if (stack1.empty() && stack2.empty()) {
//            cout << "Queue is Empty!" << endl;
//            return;
//        }
//
//        cout << "Queue Elements (Front to Rear): ";
//
//        stack<int> temp2 = stack2;
//
//        while (!temp2.empty()) {
//            cout << temp2.top() << " ";
//            temp2.pop();
//        }
//
//        stack<int> temp1 = stack1;
//        stack<int> temp3;
//
//        while (!temp1.empty()) {
//            temp3.push(temp1.top());
//            temp1.pop();
//        }
//
//        while (!temp3.empty()) {
//            cout << temp3.top() << " ";
//            temp3.pop();
//        }
//
//        cout << endl;
//    }
//
//    bool isEmpty() {
//        return stack1.empty() && stack2.empty();
//    }
//};
//
//int main() {
//    myQueue q;
//    int choice, value;
//
//    do {
//        cout << "\n===== QUEUE USING TWO STACKS =====" << endl;
//        cout << "1. Enqueue (Insert)" << endl;
//        cout << "2. Dequeue (Remove)" << endl;
//        cout << "3. Front Element" << endl;
//        cout << "4. Display Elements" << endl;
//        cout << "5. Check Empty" << endl;
//        cout << "6. Exit" << endl;
//
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//
//        case 1:
//            cout << "Enter value: ";
//            cin >> value;
//            q.enQueue(value);
//            break;
//
//        case 2:
//            if (!q.isEmpty())
//                cout << "Removed Element: "
//                << q.deQueue() << endl;
//            else
//                cout << "Queue is Empty!" << endl;
//            break;
//
//        case 3:
//            if (!q.isEmpty())
//                cout << "Front Element: "
//                << q.front() << endl;
//            else
//                cout << "Queue is Empty!" << endl;
//            break;
//
//        case 4:
//            q.display();
//            break;
//
//        case 5:
//            if (q.isEmpty())
//                cout << "Queue is Empty." << endl;
//            else
//                cout << "Queue is Not Empty." << endl;
//            break;
//
//        case 6:
//            cout << "Program Exited Successfully!" << endl;
//            break;
//
//        default:
//            cout << "Invalid Choice! Try Again." << endl;
//        }
//
//    } while (choice != 6);
//
//    return 0;
//}
