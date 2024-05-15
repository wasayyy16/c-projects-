#include <iostream>
using namespace std;

class person {
private:
    string name;
    int age;

public:
    person() {
        name = "wasay";
        age = 19;
    }
    person(string n,int a) {
        name = n;
        age = a;
    }

    void displayinfo() {
        cout << "Name is: " << name << endl;
        cout << "Age is: " << age << endl;
    }
};

int main() {
    person p1,p2("Rafay",22);
    cout<<"Normal constructor."<<endl;
    p1.displayinfo();
    cout<<endl;
    cout<<"Overloaded Constructor."<<endl;
    p2.displayinfo();
    return 0;
}
