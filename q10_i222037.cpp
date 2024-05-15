#include <iostream>
using namespace std;

class circle {
private:
    int radius;
    const float pi = 3.14;

public:
    float a;
    float c;

    circle(int r) {
        radius = r;
    }

    void findarea() {
        a = pi * radius * radius;
    }

    void findcirc() {
        c = 2 * pi * radius;
    }

    void displayinfo() {
        cout << "Area is: " << a << endl;
        cout << "Circumference is: " << c << endl;
    }
};

int main() {
    int r;
    cout << "Input radius of circle : ";
    cin >> r;

    circle c1(r);
    c1.findarea();
    c1.findcirc();
    c1.displayinfo();

    return 0;
}

