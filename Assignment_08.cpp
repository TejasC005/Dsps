/*
A library needs to manage a collection of books (data fields such
as book title, author, ISBN, availability status, and other relevant
information), maintain information about each book, support
operations like adding, removing, and searching for books, and
provide efficient access to library resources. Use the Concept of
Linked List for implementation of Library Management system.
*/
#include <iostream>
using namespace std;

class list 
{
private:
    string tt, pub, auth;
    int cost, sp;
    list *next;

public:
    void insertAtStart();
    void insertAtPosition();
    void insertAtEnd();
    void display();
    void deleteFirst();
    void deleteLast();
    void deleteByTitle();
} *head = NULL, t;

// Function to insert node at the start
void list::insertAtStart() {
    list *newnode = new list;
    newnode->next = NULL;

    cout << "Enter the title of the book: ";
    cin >> newnode->tt;
    cout << "Enter the publisher of the book: ";
    cin >> newnode->pub;
    cout << "Enter the author of the book: ";
    cin >> newnode->auth;
    cout << "Enter the cost of the book: ";
    cin >> newnode->cost;
    cout << "Enter the stock position: ";
    cin >> newnode->sp;

    // Inserting at the start
    newnode->next = head;
    head = newnode;
}

// Function to insert node at a specific position
void list::insertAtPosition() {
    list *newnode = new list;
    newnode->next = NULL;

    cout << "Enter the title of the book: ";
    cin >> newnode->tt;
    cout << "Enter the publisher of the book: ";
    cin >> newnode->pub;
    cout << "Enter the author of the book: ";
    cin >> newnode->auth;
    cout << "Enter the cost of the book: ";
    cin >> newnode->cost;
    cout << "Enter the stock position: ";
    cin >> newnode->sp;

    int pos;
    cout << "Enter the position at which you want to insert the data: ";
    cin >> pos;

    if (pos == 1) {
        // Insert at start if position is 1
        newnode->next = head;
        head = newnode;
    } else {
        list *temp = head;
        int count = 1;

        // Move temp to the (pos - 1)th node
        while (temp != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            cout << "Position out of range" << endl;
            delete newnode;
        } else {
            // Inserting at the given position
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

// Function to insert node at the end
void list::insertAtEnd() {
    list *newnode = new list;
    newnode->next = NULL;

    cout << "Enter the title of the book: ";
    cin >> newnode->tt;
    cout << "Enter the publisher of the book: ";
    cin >> newnode->pub;
    cout << "Enter the author of the book: ";
    cin >> newnode->auth;
    cout << "Enter the cost of the book: ";
    cin >> newnode->cost;
    cout << "Enter the stock position: ";
    cin >> newnode->sp;

    if (head == NULL) {
        head = newnode;
    } else {
        list *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to delete the first node
void list::deleteFirst() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    list *temp = head;
    head = head->next;
    delete temp;
}

// Function to delete the last node
void list::deleteLast() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        list *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
}

// Function to delete a node by title
void list::deleteByTitle() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    string tittle;
    cout << "Enter the title of the book you want to delete: ";
    cin >> tittle;

    list *temp = head, *prev = NULL;
    while (temp != NULL && temp->tt != tittle) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Record not found" << endl;
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Record deleted: " << tittle << endl;
}

// Function to display all nodes
void list::display() {
    if (head == NULL) {
        cout << "No records remaining" << endl;
        return;
    }

    list *temp = head;
    while (temp != NULL) {
        cout << temp->tt << "\t" << temp->pub << "\t" << temp->auth << "\t" << temp->sp << "\t" << temp->cost << "\n";
        temp = temp->next;
    }
}

int main() {
    int ch;
    do {
        cout << "1. Insert at start\n2. Insert at position\n3. Insert at end\n4. Display\n5. Delete first node\n6. Delete last node\n7. Delete by title\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                t.insertAtStart();
                break;
            case 2:
                t.insertAtPosition();
                break;
            case 3:
                t.insertAtEnd();
                break;
            case 4:
                t.display();
                break;
            case 5:
                t.deleteFirst();
                break;
            case 6:
                t.deleteLast();
                break;
            case 7:
                t.deleteByTitle();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (ch != 0);

    return 0;
}
