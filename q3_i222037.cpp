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

    void displayinfo() {
        cout << "Name is: " << name << endl;
        cout << "Age is: " << age << endl;
    }
    ~person(){
    	cout<<"Object destroyed."<<endl;
	}
};

int main() {
    person p1;
    p1.displayinfo();
    return 0;
}
