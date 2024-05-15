//Abdul Wasay
//22i-2037
//Ds-B
#include<iostream>
#include<string>
using namespace std;
//initializing structure for node
struct node{
	int ID;
    string name;
    string tickettype;
    string ridepref;
	node* next;
	//constructor
	node(int id, string n, string ticket, string pref) : ID(id), name(n), tickettype(ticket), ridepref(pref), next(NULL) {}
};
//initializing class for queue
class queue {
	private : 
	node* front;
	node* rear;
	public:
	//constructor
	queue() : front(NULL),rear(NULL) {}	
	// enqueuing function
	void enqueue(int id, string name, string tickettype, string ridepref){
		node* temp = new node(id,name,tickettype,ridepref);
		//to cater empty front
		if (front==NULL){
			front=temp;
			rear=temp;
			rear->next=front;//for circular linked list
		}
		//normal conditions
		else{
			rear->next=temp;
			rear=temp;
			rear->next=front;//for circular linked list
		}
	}
	//to remove from queue
	void dequeue(){
		if (front==NULL){
			cout<<"Queue is empty."<<endl;
			return;
		}
		else{
			node* temp=front;
            front=front->next;
            rear->next=front;//for circular linked list
            delete temp;
		}
	}
	//to display
	void display(){
	if(front==NULL){
		cout<<"The queue is empty."<<endl;
		return;
	}	
	node* curr=front;
	int i=1;
	do{
		cout<<"Details for person "<<i<<" in queue is: "<<endl;
		cout<<curr->ID<<" "<<curr->name<<" "<<curr->tickettype<<" "<<curr->ridepref;
		cout<<endl;
		curr=curr->next;
		i++;
	}while(curr!=front);
		cout<<"End of List!"<<endl;
	}
	//for searching
    void search(int id) {
     if (front == NULL) {
        cout << "Empty queue! No entries found!" << endl;
        return;
     }
     node* curr = front;
     do {
        if (curr->ID == id) {
            cout << "Person found! Details are: " << endl;
            cout << curr->ID << " " << curr->name << " " << curr->tickettype << " " << curr->ridepref << endl;
            return;
        }
        curr = curr->next;
      } while (curr != front);
    cout << "Person with ID " << id << " not found in the queue." << endl;
}
};


int main(){
	string n,t,p;
	int iden;
	queue q;
	int x=8;
	while (x!=0){
		cout<<"Enter 1 to add member to queue; 2 to remove from queue; 3 to display the entire queue; 4 to search via ID; 0 to exit."<<endl; 
	cin>>x;
	if(x==1)
	{
		cout<<"Enter name :";
		cin>>n;
		cout<<"Enter ID :";
		cin>>iden;
		cout<<"Enter Ticket Type :";
		cin>>t;
		cout<<"Enter Ride Preference :";
		cin>>p;
        q.enqueue(iden,n,t,p);
	}
	else if (x==2){
		cout<<"Removing element from queue!"<<endl;
		q.dequeue();
	}
	else if(x==3){
		cout<<"The entire queue is : "<<endl;
		q.display();
	}
	else if(x==4){
		cout<<"Enter ID to search: ";
		cin>>iden;
		q.search(iden);
	}
	else if(x==0){
		cout<<"Exitting!"<<endl;
		break;
	}
	else{
		cout<<"Invalid Input!"<<endl;
	}
	}
	return 0;
}
