/*
A Music Library System is a software application used to manage
the storage and retrieval of music tracks and albums. System need
to maintain information such as track title, artist, album, genre, 
duration, release year, and any other relevant attributes. System
should able to add new music track, remove the track, update the
information of the track, search the specific track also it should
display the information of all the track which are present in the
database. Use the Concept of Circular Linked list to implement the
above system.
*/
#include <iostream>
using namespace std;

class MusicLibrary {
private:
    int musicID;
    string track, musicName, artist;
    float duration;
    MusicLibrary *next, *prev; // Add previous pointer

public:
    void insertAtStart();
    void insertAtPosition();
    void insertAtEnd();
    void displayFor();
    void displayBack();
    void deleteFirst();
    void deleteLast();
    void deleteById();
} *head = NULL, *tail = NULL, lib; // Add a tail pointer for efficient insertion at end

// Function to insert music at the start
void MusicLibrary::insertAtStart() 
{
    MusicLibrary *newNode = new MusicLibrary;
    newNode->next = head;
    newNode->prev = NULL; // Set prev to NULL

    cout << "Enter Music ID: ";
    cin >> newNode->musicID;
    cout << "Enter Track Name: ";
    cin>>newNode->track;
    cout << "Enter Music Name: ";
    cin>>newNode->musicName;
    cout << "Enter Artist: ";
    cin>>newNode->artist;
    cout << "Enter Duration (in minutes): ";
    cin >> newNode->duration;

    if (head == NULL) {
        head = tail = newNode; // If list is empty, head and tail point to new node
    } else {
        head->prev = newNode; // Set current head's prev to new node
        head = newNode; // Update head to new node
    }
}

// Function to insert music at a specific position
void MusicLibrary::insertAtPosition()
 {
    MusicLibrary *newNode = new MusicLibrary;
    newNode->next = NULL;
    newNode->prev = NULL;

    cout << "Enter Music ID: ";
    cin >> newNode->musicID;
    cout << "Enter Track Name: ";
    cin.ignore();
    getline(cin, newNode->track);
    cout << "Enter Music Name: ";
    getline(cin, newNode->musicName);
    cout << "Enter Artist: ";
    getline(cin, newNode->artist);
    cout << "Enter Duration (in minutes): ";
    cin >> newNode->duration;

    int pos;
    cout << "Enter the position at which you want to insert the data: ";
    cin >> pos;

    if (pos == 1) {
        insertAtStart(); // Use insertAtStart if position is 1
    } else {
        MusicLibrary *temp = head;
        int count = 1;

        // Traverse to (pos - 1)th node
        while (temp != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            cout << "Position out of range" << endl;
            delete newNode;
        } else {
            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next != NULL) {
                temp->next->prev = newNode;
            } else {
                tail = newNode; // Update tail if inserting at the end
            }

            temp->next = newNode;
        }
    }
}

// Function to insert music at the end
void MusicLibrary::insertAtEnd() {
    MusicLibrary *newNode = new MusicLibrary;
    newNode->next = NULL;
    newNode->prev = tail;

    cout << "Enter Music ID: ";
    cin >> newNode->musicID;
    cout << "Enter Track Name: ";
    cin>>newNode->track;
    cout << "Enter Music Name: ";
    cin>>newNode->musicName;
    cout << "Enter Artist: ";
    cin>>newNode->artist;
    cout << "Enter Duration (in minutes): ";
    cin >> newNode->duration;

    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to display all music entries in forward order
void MusicLibrary::displayFor() {
    if (head == NULL) {
        cout << "No records remaining" << endl;
        return;
    }

    MusicLibrary *temp = head;
    while (temp != NULL) {
        cout << "Music ID: " << temp->musicID << "\tTrack: " << temp->track
             << "\tMusic Name: " << temp->musicName << "\tArtist: " << temp->artist
             << "\tDuration: " << temp->duration << " mins\n";
        temp = temp->next;
    }
}

// Function to display all music entries in backward order
void MusicLibrary::displayBack() {
    if (tail == NULL) {
        cout << "No records remaining" << endl;
        return;
    }

    MusicLibrary *temp = tail;
    while (temp != NULL) {
        cout << "Music ID: " << temp->musicID << "\tTrack: " << temp->track
             << "\tMusic Name: " << temp->musicName << "\tArtist: " << temp->artist
             << "\tDuration: " << temp->duration << " mins\n";
        temp = temp->prev;
    }
}

// Function to delete the first music entry
void MusicLibrary::deleteFirst() {
    if (head == NULL) {
        cout << "Library is empty" << endl;
        return;
    }

    MusicLibrary *temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    delete temp;
}

// Function to delete the last music entry
void MusicLibrary::deleteLast() {
    if (tail == NULL) {
        cout << "Library is empty" << endl;
        return;
    }

    MusicLibrary *temp = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete temp;
}

// Function to delete a music entry by track name
void MusicLibrary::deleteById() {
    if (head == NULL) {
        cout << "Library is empty" << endl;
        return;
    }

    int IdToDelete;
    cout << "Enter the Track Name you want to delete: ";
    cin>>IdToDelete;

    MusicLibrary *temp = head;
    while (temp != NULL && temp->musicID != IdToDelete) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Record not found" << endl;
        return;
    }

    if (temp == head) {
        deleteFirst();
    } else if (temp == tail) {
        deleteLast();
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    cout << "Record deleted: " << IdToDelete << endl;
}

int main() {
    int ch;
    do {
        cout << "\n1. Insert at start\n2. Insert at position\n3. Insert at end\n4. Display Forward\n5. Display Backward\n6. Delete first entry\n7. Delete last entry\n8. Delete by ID\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                lib.insertAtStart();
                break;
            case 2:
                lib.insertAtPosition();
                break;
            case 3:
                lib.insertAtEnd();
                break;
            case 4:
                lib.displayFor();
                break;
            case 5:
                lib.displayBack();
                break;
            case 6:
                lib.deleteFirst();
                break;
            case 7:
                lib.deleteLast();
                break;
            case 8:
                lib.deleteById();
                break;
            default:
            cout<<"invalid";
            break;
        }
    }
    while(ch!=0);
    return 0;
}
    

