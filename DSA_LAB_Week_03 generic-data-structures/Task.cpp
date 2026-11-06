#include <iostream>
#include "CustomList.h"
using namespace std;

int main() {
    int capacity;

    cout << "Enter maximum list capacity: ";
    cin >> capacity;

    if (capacity <= 0) {
        cout << "Capacity must be greater than zero.\n";
        return 0;
    }

    CustomList<int> list(capacity);
    int choice;

    do {
        cout << "\n--- Generic Data Structures Menu ---\n";
        cout << "1. Add element at beginning\n";
        cout << "2. Add element at end\n";
        cout << "3. Remove element from beginning\n";
        cout << "4. Remove element from end\n";
        cout << "5. Insert at index\n";
        cout << "6. Search for value\n";
        cout << "7. Display list\n";
        cout << "8. Check whether list is empty\n";
        cout << "9. Check whether list is full\n";
        cout << "10. Show list size\n";
        cout << "11. Show last element\n";
        cout << "12. Sum of prime numbers\n";
        cout << "13. Second maximum even number\n";
        cout << "14. Second minimum odd number\n";
        cout << "15. Print duplicates\n";
        cout << "16. Rotate both halves clockwise\n";
        cout << "17. Rotate both halves anticlockwise\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try {
            int value;
            int index;
            int rotations;

            switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.addElementAtFirstIndex(value);
                cout << "Element added.\n";
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.addElementAtLastIndex(value);
                cout << "Element added.\n";
                break;

            case 3:
                list.removeElementFromStart();
                cout << "First element removed.\n";
                break;

            case 4:
                cout << "Removed element: " << list.removeElementFromEnd() << '\n';
                break;

            case 5:
                cout << "Enter index (starting from 0): ";
                cin >> index;
                cout << "Enter value: ";
                cin >> value;
                if (list.insertAt(index, value)) {
                    cout << "Element inserted.\n";
                }
                else {
                    cout << "Invalid index or list is full.\n";
                }
                break;

            case 6:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (list.search(value) ? "Value found.\n" : "Value not found.\n");
                break;

            case 7:
                list.display();
                break;

            case 8:
                cout << (list.empty() ? "List is empty.\n" : "List is not empty.\n");
                break;

            case 9:
                cout << (list.full() ? "List is full.\n" : "List is not full.\n");
                break;

            case 10:
                cout << "Current size: " << list.size() << '\n';
                break;

            case 11:
                cout << "Last element: " << list.last() << '\n';
                break;

            case 12:
                cout << "Sum of prime numbers: " << list.sum_ofPrime() << '\n';
                break;

            case 13:
                cout << "Second maximum even number: " << list.secondMaxEven() << '\n';
                break;

            case 14:
                cout << "Second minimum odd number: " << list.secondMinOdd() << '\n';
                break;

            case 15:
                cout << "Duplicates: ";
                list.printDuplicates();
                break;

            case 16:
                cout << "Enter number of rotations: ";
                cin >> rotations;
                list.rotateClockwaise(rotations);
                cout << "Both halves rotated clockwise.\n";
                list.display();
                break;

            case 17:
                cout << "Enter number of rotations: ";
                cin >> rotations;
                list.rotateanitclockwaise(rotations);
                cout << "Both halves rotated anticlockwise.\n";
                list.display();
                break;

            case 0:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice.\n";
            }
        }
        catch (const exception& error) {
            cout << "Error: " << error.what() << '\n';
        }

    } while (choice != 0);

    return 0;
}
