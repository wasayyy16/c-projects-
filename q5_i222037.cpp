#include<iostream>
using namespace std;
class bank{
	private :
		int accNo;
		int bal;
		public :
	bank(int n,int b) {
	accNo=n;
	bal=b;
	}	
	void deposit(){
		int amm;
		cout<<"Enter the amount you want to deposit : ";
		cin>>amm;
		bal+=amm;
		cout<<"Remaining balance is : $"<<bal<<endl;
	}
	void withdraw(){
		int amm;
		cout<<"Enter the amount you want to withdraw : ";
		cin>>amm;
		bal-=amm;
		cout<<"Remaining balance is : $"<<bal<<endl;
	}
	~bank(){
		cout<<endl<<"Object Deleted!";
	}
};
int main(){
	int n,b;
	cout<<"Enter your account number : ";
	cin>>n;
	cout<<"Enter your balance : ";
	cin>>b;
	bank b1(n,b);
	int x;
	cout<<"Enter 1 if you want to Deposit money, 2 to Withdraw money : ";
	cin>>x;
	switch (x){
		case  1 : 
		b1.deposit();
		break;
		case 2 :
			b1.withdraw();
			break;
			
		default	:
			cout<<"Invalid Input"<<endl;
			break;
		
	}
	return 0;
}
