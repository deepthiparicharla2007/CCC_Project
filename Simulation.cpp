#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

/*---------------------- INSERT AT END -----------------------*/
void insertNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        cout << "Node inserted as head.\n";
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        cout << "Node inserted at end.\n";
    }
}

/*---------------------- DELETE NODE -------------------------*/
void deleteNode(int value) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        delete temp;
        cout << "Head node deleted.\n";
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value not found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Node deleted.\n";
}

/*---------------------- SEARCH NODE -------------------------*/
void searchNode(int value) {
    Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Value " << value << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }

    cout << "Value not found in list.\n";
}

/*---------------------- DISPLAY LIST -------------------------*/
void displayList() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "\nLinked List Simulation:\n";

    while (temp != NULL) {
        cout << "[" << temp->data << "] -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

/*--------------------------- MAIN MENU ------------------------*/
int main() {
    int choice, value;

    while (true) {
        cout << "\n---- LINKED LIST SIMULATION ----\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Search Node\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertNode(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(value);
                break;

            case 4:
                displayList();
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}