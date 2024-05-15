#include <iostream>
#include <string>
using namespace std;

struct Bank {
    int acc;
    string name;
    double bal;
};

void details(const Bank &b1) {
    cout << b1.acc << endl;
    cout << b1.name << endl;
    cout << b1.bal << endl;
}

void deposit(Bank &b1) {
    cout << "Enter the amount to be deposited: ";
    int p;
    cin >> p;
    b1.bal += p;
}

void withdraw(Bank &b1) {
    cout << "Enter the amount to be withdrawn: ";
    int p;
    cin >> p;
    b1.bal -= p;
}

int main() {
    Bank b1;
    cin >> b1.acc;
    cin.ignore(); // Clear the input buffer
    getline(cin, b1.name);
    cin >> b1.bal;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. See details" << endl;
        cout << "4. Quit" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                deposit(b1);
                break;
            case 2:
                withdraw(b1);
                break;
            case 3:
                cout << "Details are: " << endl;
                details(b1);
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 1;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}


//#include <iostream>
//#include <string>
//using namespace std;
//
//struct Bank {
//    int acc;
//    string name;
//    double bal;
//};
//void details(Bank b1){
//    cout<<b1.acc<<endl;
//    cout<<b1.name<<endl;
//    cout<<b1.bal<<endl;	
//}
//void deposit(Bank b1){
//    cout<<"Enter the amount to be deposited : "<<endl;	
//    int p;
//    cin>>p;
//    b1.bal+=p;
//}
//void withdraw(Bank b1){
//    cout<<"Enter the amount to be withdrawn : "<<endl;	
//    int p;
//    cin>>p;
//    b1.bal-=p;
//}
//
//
//int main() {
//    Bank b1;
//    cin>>b1.acc;
//    cin>>b1.name;
//    cin>>b1.bal;
//    while (true) {
//        cout << "Menu:" << endl;
//        cout << "1. Deposit" << endl;
//        cout << "2. Withdraw" << endl;
//        cout << "3. See details" << endl;
//        cout << "4. Quit" << endl;
//        int choice;
//        cin >> choice;
//
//        switch (choice) {
//            case 1:
//                withdraw(b1);
//                break;
//            case 2:
//			    deposit(b1);
//                break;
//            case 3:
//            	cout<<"Details are : "<<endl;
//                details(b1);
//                break;
//            case 4:
//                cout << "Exiting the program." << endl;
//                return 1;
//            default:
//                cout << "Invalid choice. Please try again." << endl;
//        }
//    }
//
//    return 0;
//}


