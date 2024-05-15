#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    int publicationYear;
    bool isAvailable;
};

const int MAX_BOOKS = 100; 
void addBook(Book catalog[], int &numBooks) {
    if (numBooks >= MAX_BOOKS) {
        cout << "Catalog is full. Cannot add more books." << endl;
        return;
    }

    Book newBook;
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter author: ";
    getline(cin, newBook.author);
    cout << "Enter publication year: ";
    cin >> newBook.publicationYear;
    newBook.isAvailable = true;

    catalog[numBooks++] = newBook;
    cout << "Book added to the catalog." << endl;
}
void checkOutBook(Book catalog[], int numBooks, const string &title) {
    for (int i = 0; i < numBooks; i++) {
        if (catalog[i].title == title) {
            if (catalog[i].isAvailable) {
                catalog[i].isAvailable = false;
                cout << "Checked out: " << catalog[i].title << endl;
            } else {
                cout << "Book is already checked out." << endl;
            }
            return;
        }
    }
    cout << "Book not found in the catalog." << endl;
}
void checkInBook(Book catalog[], int numBooks, const string &title) {
    for (int i = 0; i < numBooks; i++) {
        if (catalog[i].title == title) {
            if (!catalog[i].isAvailable) {
                catalog[i].isAvailable = true;
                cout << "Checked in: " << catalog[i].title << endl;
            } else {
                cout << "Book is already checked in." << endl;
            }
            return;
        }
    }
    cout << "Book not found in the catalog." << endl;
}
void searchBook(const Book catalog[], int numBooks, const string &title) {
    bool found = false;
    cout << "Search results for '" << title << "':" << endl;

    for (int i = 0; i < numBooks; i++) {
        if (catalog[i].title == title) {
            cout << "Title: " << catalog[i].title << endl;
            cout << "Author: " << catalog[i].author << endl;
            cout << "Publication Year: " << catalog[i].publicationYear << endl;
            cout << "Availability: " << (catalog[i].isAvailable ? "Available" : "Checked Out") << endl;
            cout << "-----------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No matching books found." << endl;
    }
}
void listBooks(const Book catalog[], int numBooks) {
    cout << "Library Catalog:" << endl;
    for (int i = 0; i < numBooks; i++) {
        cout << "Title: " << catalog[i].title << endl;
        cout << "Author: " << catalog[i].author << endl;
        cout << "Publication Year: " << catalog[i].publicationYear << endl;
        cout << "Availability: " << (catalog[i].isAvailable ? "Available" : "Checked Out") << endl;
        cout << "-----------------------------" << endl;
    }
}

int main() {
    Book catalog[MAX_BOOKS]; 
    int numBooks = 0; 

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Check out a book" << endl;
        cout << "3. Check in a book" << endl;
        cout << "4. Search for a book" << endl;
        cout << "5. List all books" << endl;
        cout << "6. Quit" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(catalog, numBooks);
                break;
            case 2:
                {
                    string title;
                    cout << "Enter title to check out: ";
                    cin.ignore();
                    getline(cin, title);
                    checkOutBook(catalog, numBooks, title);
                }
                break;
            case 3:
                {
                    string title;
                    cout << "Enter title to check in: ";
                    cin.ignore();
                    getline(cin, title);
                    checkInBook(catalog, numBooks, title);
                }
                break;
            case 4:
                {
                    string title;
                    cout << "Enter title to search: ";
                    cin.ignore();
                    getline(cin, title);
                    searchBook(catalog, numBooks, title);
                }
                break;
            case 5:
                listBooks(catalog, numBooks);
                break;
            case 6:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

