#include <iostream>
using namespace std;

class student {
private:
    string name;
    int rollNo;
    char grade;
public:
	int a;
    int p;
    student(string n, int r, char g) {
    	name=n;
    	rollNo=r;
    	grade=g;
    	}
   
    void displayinfo() {
        cout << "Name : " << name << endl;
        cout << "Roll Number : " << rollNo << endl;
        cout << "Grade : " << grade << endl;
    }
    ~student(){
		cout<<endl<<"Object Deleted!";
	}
};

int main() {
    string n;
    int r;
    char g;
    cout << "Input name, roll number and grade of the student respectively: "<<endl;
    cin >> n >> r>>g;
    cout<<endl<<endl<<"Object details are as follows : "<<endl;w
    student s1(n,r,g);
    s1.displayinfo();

    return 0;
}
