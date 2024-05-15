//Abdul Wasay
//22i-2037
//Ds-B
#include<iostream>
#include<string>
using namespace std;
static int t=1;
//initializing structure for node
struct node{
	int ID;
    int time;
    string content;
	node* next;
	//constructor
	node(int id, string cont) : ID(id), time(t), content(cont) ,next(NULL) {}
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
	void send(int id, string cont){
		node* temp = new node(id,cont);
		//to cater empty front
		if (front==NULL){
			front=temp;
			rear=temp;
			rear->next=NULL;
		}
		//normal conditions
		else{
			rear->next=temp;
			rear=temp;
			rear->next=NULL;
		}
		t++;
	}
	//to remove from queue
	void deletee(){
		if (front==NULL){
			cout<<"Inbox is empty."<<endl;
			return;
		}
		else{
			node* temp=front;
            front=front->next;
            rear->next=NULL;
            delete temp;
		}
	}
	//to display
	void display(){
	if(front==NULL){
		cout<<"The Inbox is empty."<<endl;
		return;
	}	
	node* curr=front;
	int i=1;
	while(curr!=NULL){
		cout<<"Details for Message "<<i<<" in Inbox is: "<<endl;
		cout<<"Sender ID: "<<curr->ID<<endl;
		cout<<"Time Stamp: "<<curr->time<<endl;
		cout<<"Message Content: "<<curr->content<<endl;
		cout<<endl;
		curr=curr->next;
		i++;
	}
		cout<<"End of List!"<<endl;
	}
	//for searching
    void search(int id) {
     if (front == NULL) {
        cout << "Empty Inbox! No Messages found!" << endl;
        return;
     }
     node* curr = front;
     while (curr != NULL) {
        if (curr->ID == id || curr->time==id) {
            cout << "Message found! Details are: " << endl;
            cout<<"Sender ID: "<<curr->ID<<endl;
		    cout<<"Time Stamp: "<<curr->time<<endl;
		    cout<<"Message Content: "<<curr->content<<endl;
            return;
        }
        curr = curr->next;
      } 
    cout << "Message not found in the queue." << endl;
}
//for receiving
void receive(){
	if (front==NULL){
			cout<<"Inbox is empty."<<endl;
			return;
		}
		else{
			node* temp=front;
		    cout<<"Sender ID: "<<temp->ID<<endl;
		    cout<<"Time Stamp: "<<temp->time<<endl;
		    cout<<"Message Content: "<<temp->content<<endl;
            front=front->next;
            rear->next=NULL;
            delete temp;
		}
}
//for viewing message on top
void view(){
	if (front==NULL){
			cout<<"Inbox is empty."<<endl;
			return;
		}
		else{
			node* temp=front;
		    cout<<"Sender ID: "<<temp->ID<<endl;
		    cout<<"Time Stamp: "<<temp->time<<endl;
		    cout<<"Message Content: "<<temp->content<<endl;
		}
}
};

int main(){
	string p;
	int iden,t;
	queue q;
	int x=8;
	while (x!=0){
    cout<<"Enter 1 to send a message; 2 to Delete Message ; 3 to display the entire Inbox; 4 to search via ID or Time Stamp; 5 to receive a message; 6 to view message on top; 0 to  exit."<<endl; 
	cin>>x;
	if(x==1)
	{
		cout<<"Enter ID :";
		cin>>iden;
//		cout<<"Enter Time Stamp :";
//		cin>>t;
		cout<<"Content :";
		cin.ignore();
		getline(cin,p);
        q.send(iden,p);
	}
	else if (x==2){
		cout<<"Removing message from Inbox!"<<endl;
		q.deletee();
	}
	else if(x==3){
		cout<<"The entire Inbox is : "<<endl;
		q.display();
	}
	else if(x==4){
		cout<<"Enter ID or Time Stamp to search: ";
		cin>>iden;
		q.search(iden);
	}
	else if (x==5){
		q.receive();
	}
	else if(x==6){
		q.view();
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
