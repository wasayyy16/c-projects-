#include <iostream>
using namespace std;

class employee {
private:
    string name;
    int employeeID;
	int salary;
    

public:
    employee(string n, int id, int s) {
        name= n;
        employeeID = id;
        salary = s;
	}
void giveRaise(){
	int x;
	cout<<"Enter the amount of salary raise to give to the employee :";
	cin>>x;
	salary+=x;
	
}
    void displayinfo() {
    	cout<<endl<<endl<<"Details are : "<<endl;
        cout << "Name : " << name << endl;
        cout << "Employee ID : " << employeeID << endl;
        cout << "Salary : " << salary << endl;
    }
};

int main() {
	string n;
	int id,s;
	cout<<"Input name , Employee ID and Salary of the Employee respectively : "<<endl;
	cin>>n>>id>>s;
    employee e1(n,id,s);
    e1.giveRaise();
    e1.displayinfo();
    return 0;
}
