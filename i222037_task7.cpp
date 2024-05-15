#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phoneNumber;
    string email;
};

const int MAX_CONTACTS = 100; 
void addContact(Contact contacts[], int &numContacts) {
    if (numContacts >= MAX_CONTACTS) {
        cout << "Contact list is full. Cannot add more contacts." << endl;
        return;
    }

    Contact newContact;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phoneNumber);
    cout << "Enter email: ";
    getline(cin, newContact.email);

    contacts[numContacts++] = newContact;
    cout << "Contact added." << endl;
}

void searchContact(const Contact contacts[], int numContacts, const string &name) {
    bool found = false;
    cout << "Search results for '" << name << "':" << endl;

    for (int i = 0; i < numContacts; i++) {
        if (contacts[i].name == name) {
            cout << "Name: " << contacts[i].name << endl;
            cout << "Phone number: " << contacts[i].phoneNumber << endl;
            cout << "Email: " << contacts[i].email << endl;
            cout << "-----------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No matching contacts found." << endl;
    }
}
void deleteContact(Contact contacts[], int &numContacts, const string &name) {
    int indexToDelete = -1;

    for (int i = 0; i < numContacts; i++) {
        if (contacts[i].name == name) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete != -1) {
        for (int i = indexToDelete; i < numContacts - 1; i++) {
            contacts[i] = contacts[i + 1];
        }

        numContacts--;
        cout << "Contact deleted." << endl;
    } else {
        cout << "Contact not found. Deletion failed." << endl;
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int numContacts = 0;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add a contact" << endl;
        cout << "2. Search for a contact" << endl;
        cout << "3. Delete a contact" << endl;
        cout << "4. Quit" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts, numContacts);
                break;
            case 2:
                {
                    string name;
                    cout << "Enter name to search: ";
                    cin.ignore();
                    getline(cin, name);
                    searchContact(contacts, numContacts, name);
                }
                break;
            case 3:
                {
                    string name;
                    cout << "Enter name to delete: ";
                    cin.ignore();
                    getline(cin, name);
                    deleteContact(contacts, numContacts, name);
                }
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

