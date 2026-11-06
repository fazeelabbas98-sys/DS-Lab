
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class ParkingLot {
private:
    stack<string> myCarStack;
    int capacity = 8;

public:
    void parkCar() {
        if (myCarStack.size() >= capacity) {
            cout << "Parking lot is full!\n";
            return;
        }

        string carNumber;
        cout << "Enter car number: ";
        cin >> carNumber;

        stack<string> temp = myCarStack;

        while (!temp.empty()) {
            if (temp.top() == carNumber) {
                cout << "This car is already parked!\n";
                return;
            }
            temp.pop();
        }

        myCarStack.push(carNumber);
        cout << "Car parked successfully.\n";
    }

    void removeCar() {
        if (myCarStack.empty()) {
            cout << "Parking lot is empty!\n";
            return;
        }

        string carNumber;
        cout << "Enter car number to remove: ";
        cin >> carNumber;

        stack<string> tempStack;
        bool found = false;

        while (!myCarStack.empty()) {
            if (myCarStack.top() == carNumber) {
                myCarStack.pop();
                found = true;
                break;
            }

            tempStack.push(myCarStack.top());
            myCarStack.pop();
        }

        while (!tempStack.empty()) {
            myCarStack.push(tempStack.top());
            tempStack.pop();
        }

        if (found) {
            cout << "Car removed successfully.\n";
        }
        else {
            cout << "Car not found in parking lot.\n";
        }
    }

    void displayCars() {
        if (myCarStack.empty()) {
            cout << "Parking lot is empty!\n";
            return;
        }

        stack<string> temp = myCarStack;

        cout << "\nCurrently parked cars (top to bottom):\n";

        while (!temp.empty()) {
            cout << temp.top() << endl;
            temp.pop();
        }
    }

    void totalCars() {
        cout << "Total cars parked: "
            << myCarStack.size() << "/"
            << capacity << endl;
    }

    void searchCar() {
        string carNumber;
        cout << "Enter car number to search: ";
        cin >> carNumber;

        stack<string> temp = myCarStack;

        while (!temp.empty()) {
            if (temp.top() == carNumber) {
                cout << "Car is present in the parking lot.\n";
                return;
            }
            temp.pop();
        }

        cout << "Car is not present in the parking lot.\n";
    }
};

int main() {
    ParkingLot parking;
    int choice;

    do {
        cout << "\n===== PARKING LOT MANAGEMENT =====\n";
        cout << "1. Park a new car\n";
        cout << "2. Remove a car\n";
        cout << "3. View parked cars\n";
        cout << "4. Total cars parked\n";
        cout << "5. Search for a car\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            parking.parkCar();
            break;

        case 2:
            parking.removeCar();
            break;

        case 3:
            parking.displayCars();
            break;

        case 4:
            parking.totalCars();
            break;

        case 5:
            parking.searchCar();
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
