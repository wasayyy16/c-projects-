#include<iostream>
using namespace std;
struct employee{
	string name;
	int id;
	double salary;
	void add(employee *ptr,int n){
		for (int i=0;i<n;i++){
		cout<<"Enter details for employee "<<i+1<<endl;
		cin>>ptr->name;
        cin>>ptr->id;
        cin>>ptr->salary;
		}
	}
	void del(employee *ptr,int n){
		
		for (int i=0;i<n;i++){
		cout<<"Details for employee "<<i+1<<endl;
		cout<<ptr->name<<endl;
        cout<<ptr->id<<endl;
        cout<<ptr->salary<<endl;
	}
	cout<<"Enter the Index yout want to delete : ";
	int a;
	cin>>a;
    ptr[a].name = "  ";
    ptr[a].id = 0;
    ptr[a].salary = 0.0;

	}
	void display(employee *ptr,int n){
		
		for (int i=0;i<n;i++){
		cout<<"Details for employee "<<i+1<<endl;
		cout<<ptr->name<<endl;
        cout<<ptr->id<<endl;
        cout<<ptr->salary<<endl;
	}
}
};
int main(){
	int n;
	cout<<"Enter number of employees : ";
	cin>>n;
	employee e1;
	employee *ptr=&e1;
	ptr= new employee[n];
	cout<<"Enter 1 to add record, 2 to delete record.";
	int w;
	cin>>w;
	if (w==1){
	e1.add(ptr,n);
	cout<<"Enter 1 to view details.";
	int x;
	cin>>x;	
	if (x==1){
		e1.display(ptr,n);
	}
	}
	if (w==2){
	e1.del(ptr,n);	
		cout<<"Enter 1 to view details.";
	int x;
	cin>>x;	
	if (x==1){
		e1.display(ptr,n);
	}
	}
	
	delete[] ptr;
	return 0;
} 
