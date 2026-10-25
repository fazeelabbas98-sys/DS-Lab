#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
private:
    string text;
    stack<pair<char, char>> undoStack;
    stack<pair<char, char>> redoStack;

public:
    void typeCharacter() {
        char ch;
        cout << "Enter a character to type: ";
        cin >> ch;

        text += ch;
        undoStack.push(make_pair('T', ch));

        while (!redoStack.empty()) {
            redoStack.pop();
        }

        cout << "Character added successfully.\n";
    }

    void deleteCharacter() {
        if (text.empty()) {
            cout << "Text is empty. Nothing to delete.\n";
            return;
        }

        char ch = text.back();
        text.pop_back();

        undoStack.push(make_pair('D', ch));

        while (!redoStack.empty()) {
            redoStack.pop();
        }

        cout << "Last character deleted successfully.\n";
    }

    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo.\n";
            return;
        }

        pair<char, char> action = undoStack.top();
        undoStack.pop();

        if (action.first == 'T') {
            text.pop_back();
        }
        else if (action.first == 'D') {
            text += action.second;
        }

        redoStack.push(action);

        cout << "Undo successful.\n";
    }

    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo.\n";
            return;
        }

        pair<char, char> action = redoStack.top();
        redoStack.pop();

        if (action.first == 'T') {
            text += action.second;
        }
        else if (action.first == 'D') {
            text.pop_back();
        }

        undoStack.push(action);

        cout << "Redo successful.\n";
    }

    void displayText() {
        cout << "\nCurrent Text: " << text << endl;
    }
};

int main() {
    TextEditor editor;
    int choice;

    do {
        cout << "\n===== TEXT EDITOR =====\n";
        cout << "1. Type a character\n";
        cout << "2. Delete last character\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Display text\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            editor.typeCharacter();
            break;

        case 2:
            editor.deleteCharacter();
            break;

        case 3:
            editor.undo();
            break;

        case 4:
            editor.redo();
            break;

        case 5:
            editor.displayText();
            break;

        case 0:
            cout << "Exiting text editor...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}