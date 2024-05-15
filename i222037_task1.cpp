#include<iostream>
#include<cstring>
using namespace std;
struct student{
	string name;
	int rollno;
	double marks;
};
int main(){
	int n;
	cout<<"Enter the number of students : ";
	cin>>n;
	student s1[n];
	for (int i=0;i<n;i++){
		cout<<"Enter details for student "<<i+1<<endl;
		cin>>s1[i].name;
		cin>>s1[i].rollno;
		cin>>s1[i].marks;
	}
	for (int i=0;i<n;i++){
		cout<<"Details for student "<<i+1<<endl;
		cout<<s1[i].name<<endl;
		cout<<s1[i].rollno<<endl;
		cout<<s1[i].marks<<endl;
	}
	
	return 0;
}
