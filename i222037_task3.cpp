#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title; 
    string author;
    string ISBN;
    double price;
};

const int MAX_BOOKS = 100; 
void addBook(Book inventory[], int &numBooks) {
    if (numBooks >= MAX_BOOKS) {
        cout << "Inventory is full. Cannot add more books." << endl;
        return;
    }

    Book newBook;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter author: ";
    getline(cin, newBook.author);
    cout << "Enter ISBN: ";
    getline(cin, newBook.ISBN);
    cout << "Enter price: ";
    cin >> newBook.price;

    inventory[numBooks++] = newBook;
    cout << "Book added to inventory." << endl;
}

void listBooks(const Book inventory[], int numBooks) {
    cout << "Inventory Listing:" << endl;
    for (int i = 0; i < numBooks; i++) {
        cout << "Title: " << inventory[i].title << endl;
        cout << "Author: " << inventory[i].author << endl;
        cout << "ISBN: " << inventory[i].ISBN << endl;
        cout << "Price: $" << inventory[i].price << endl;
        cout << "-----------------------------" << endl;
    }
}

int main() {
    Book inventory[MAX_BOOKS]; 
    int numBooks = 0; 

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. List all books" << endl;
        cout << "3. Quit" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(inventory, numBooks);
                break;
            case 2:
                listBooks(inventory, numBooks);
                break;
            case 3:
                cout << "Exiting the program." << endl;
                return 1;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

