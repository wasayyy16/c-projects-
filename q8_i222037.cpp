#include <iostream>
using namespace std;

class car {
private:
    string make;
    string model;
	int year;
    

public:
    car(string m, string mod, int y) {
        make = m;
        model = mod;
        year = y;
	}

    void displayinfo() {
    	cout<<endl<<endl<<"Details are : "<<endl;
        cout << "Make : " << make << endl;
        cout << "Model : " << model << endl;
        cout << "Year : " << year << endl;
    }
};

int main() {
	string m,mod;
	int y;
	cout<<"Input make , model and year of the car respectively : "<<endl;
	cin>>m>>mod>>y;
    car c1(m,mod,y);
    c1.displayinfo();
    return 0;
}

