//Abdul Wasay
//22i-2037
//Ds-B
#include<iostream>
using namespace std;
//initializing counter
static int count=1;
struct node{ 
	int data;
	node* next;
	//constructor
	node(int d) : data(d) , next(NULL) {}
};
//function for displaying lists
void display(node* head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"--->";
		temp=temp->next;
	}
	cout<<"NULL";
	cout<<endl;
}
//function for inputting values to the linked list
void input(node*& head) {
    int val;
    cout << "Input the value: ";
    cin >> val;
    //condition for empty list
    if (head == NULL) {
        head = new node(val);
        return;
    }
    //iterating to the end of the list
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    //storing the input value in a new node
    temp->next = new node(val);
}
//function for median value
void median(node* head){
	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
		count++;
	}
	node* p=head;
	cout<<"Total values are: "<<count<<endl;
	int mid=count/2;
	//for odd number of values
	if(count%2==1){
		for(int i=0;i<mid;i++){
			p=p->next;
		}
		cout<<"Median Value is: "<<p->data<<endl;
		}
	//for even number of values
	if (count%2==0){
		float a;
		float b;
		mid-=1;
		for(int i=0;i<mid;i++){
			p=p->next;
		}
		a=p->data;
		b=p->next->data;
//		static_cast<float>(a);
//		static_cast<float>(b);
		float result=((a+b)/2);
		cout<<"Median Value is: "<<result<<endl;
		
	}	
}
int main(){
	//initializing list 
    node* list=NULL;
    //inputting list
    int x=8;
    while(x!=0){
    	cout<<"Input 1 to add value and 0 to exit adding values: ";
    	cin>>x;
		if(x==0){
			cout<<"Exitting!"<<endl;
			break;
		}
    	else if (x==1){
    		input(list);
    	}
    	else{
    		cout<<"Invalid Input!"<<endl;
		}
	}
	//printing the original list 
    cout << "Original List: ";
    display(list);
    median(list);
	return 0;
}
