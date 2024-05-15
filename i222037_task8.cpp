#include <iostream>
#include <string>
using namespace std;

// Define a structure for car information
struct Car {
    string make;
    string model;
    int year;
    double price;
};

const int MAX_CARS = 100; // Maximum number of cars in the inventory

// Function to add a car to the inventory
void addCar(Car inventory[], int &numCars) {
    if (numCars >= MAX_CARS) {
        cout << "Inventory is full. Cannot add more cars." << endl;
        return;
    }

    Car newCar;
    cout << "Enter make: ";
    cin.ignore();
    getline(cin, newCar.make);
    cout << "Enter model: ";
    getline(cin, newCar.model);
    cout << "Enter year: ";
    cin >> newCar.year;
    cout << "Enter price: ";
    cin >> newCar.price;

    inventory[numCars++] = newCar;
    cout << "Car added to inventory." << endl;
}

// Function to search for a car by make and model
void searchCar(const Car inventory[], int numCars, const string &make, const string &model) {
    bool found = false;
    cout << "Search results for '" << make << " " << model << "':" << endl;

    for (int i = 0; i < numCars; i++) {
        if (inventory[i].make == make && inventory[i].model == model) {
            cout << "Make: " << inventory[i].make << endl;
            cout << "Model: " << inventory[i].model << endl;
            cout << "Year: " << inventory[i].year << endl;
            cout << "Price: $" << inventory[i].price << endl;
            cout << "-----------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No matching cars found." << endl;
    }
}

// Function to display all cars in the inventory
void displayInventory(const Car inventory[], int numCars) {
    cout << "Inventory Listing:" << endl;
    for (int i = 0; i < numCars; i++) {
        cout << "Make: " << inventory[i].make << endl;
        cout << "Model: " << inventory[i].model << endl;
        cout << "Year: " << inventory[i].year << endl;
        cout << "Price: $" << inventory[i].price << endl;
        cout << "-----------------------------" << endl;
    }
}

int main() {
    Car inventory[MAX_CARS]; // Array to store cars
    int numCars = 0; // Number of cars currently in the inventory

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add a car" << endl;
        cout << "2. Search for a car" << endl;
        cout << "3. Display inventory" << endl;
        cout << "4. Quit" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addCar(inventory, numCars);
                break;
            case 2:
                {
                    string make, model;
                    cout << "Enter make: ";
                    cin.ignore();
                    getline(cin, make);
                    cout << "Enter model: ";
                    getline(cin, model);
                    searchCar(inventory, numCars, make, model);
                }
                break;
            case 3:
                displayInventory(inventory, numCars);
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

