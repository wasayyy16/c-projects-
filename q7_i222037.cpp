#include <iostream>
#include <string>
using namespace std;

class library {
private:
    string title;
    string author;
    string inventory[5]; // Array to store book titles

public:
    library() {
        // Initialize the inventory array with book titles
        inventory[0] = "OOP";
        inventory[1] = "PF";
        inventory[2] = "Calculus";
        inventory[3] = "Differential";
        inventory[4] = "Linear";
    }

    void check() {
        string x;
        cout << "Enter the title of the book you want to check : ";
        cin >> x;

        bool found = false;
        for (int i = 0; i < 5; i++) {
            if (x == inventory[i]) {
                cout << "Book is available." << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Book is not available." << endl;
        }
    }

    ~library() {
        cout << endl << "Object Deleted!";
    }
};

int main() {
    int w;
    cout << "Input 1 to add a book, 2 to check the availability of the book: ";
    cin >> w;

    if (w == 1) {
        string t, a;
        cout << "Input title and author of the book respectively : " << endl;
        cin >> t >> a;
        library b1;
        // You can add the book to the library's inventory here if needed
    }
    else if (w == 2) {
        library b2;
        b2.check();
    }
    else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}

