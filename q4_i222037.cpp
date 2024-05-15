#include <iostream>
using namespace std;

class rect {
private:
    int len;
    int wid;
public:
	int a;
    int p;
    rect(int l, int w) {
        len = l;
        wid = w;
    }
    void findarea() {
        a = len * wid;
    }
    void findperi() {
        p = 2 * (len + wid);
    }

    void displayinfo() {
        cout << "Area is: " << a << endl;
        cout << "Perimeter is: " << p << endl;
    }
};

int main() {
    int l, w;
    cout << "Input length and width of the rectangle respectively: "<<endl;
    cin >> l >> w;

    rect r1(l, w);
    r1.findarea();
    r1.findperi();
    r1.displayinfo();

    return 0;
}

