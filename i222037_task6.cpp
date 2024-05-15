#include <iostream>
using namespace std;

struct rect {
    double l;
    double w;
};

void area(const rect &r) {
    cout << "Area is : " << (r.l * r.w) << endl;
}

void perimeter(const rect &r) {
    cout << "Perimeter is : " << 2 * (r.l + r.w) << endl;
}

bool intersecting(const rect &r1, const rect &r2) {
    bool horizontalOverlap = (r1.l <= r2.l + r2.w) && (r1.l + r1.w >= r2.l);
    bool verticalOverlap = (r1.w <= r2.w + r2.l) && (r1.w + r1.l >= r2.w);
    return (horizontalOverlap && verticalOverlap);
}

int main() {
    rect r1, r2;

    while (true) {
    	cout << "Enter length and width of rectangle 1." << endl;
        cin >> r1.l;
        cin >> r1.w;
        cout << "Menu:" << endl;
        cout << "1. Area" << endl;
        cout << "2. Perimeter" << endl;
        cout << "3. Check intersecting rectangles." << endl;
        cout << "4. Quit" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            area(r1);
            break;
        case 2:
            perimeter(r1);
            break;
        case 3:
            cout << "Enter length and width of rectangle 2." << endl;
            cin >> r2.l;
            cin >> r2.w;
            if (intersecting(r1, r2)) {
                cout << "Rectangles intersect." << endl;
            } else {
                cout << "Rectangles do not intersect." << endl;
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

