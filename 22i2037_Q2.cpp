//Abdul Wasay
//22i-2037
//Ds-B
#include<iostream>
using namespace std;
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
//method for  swapping data between two nodes 
void swap(node* a, node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

//using bubble sort to arrange the linked list in the ascending order
void sort(node* head) {
	//exception condition to handle empty linked list
    if (head == NULL){
        return; 
  }
   //bubble sort algorithm
    node* curr;
    node* tail = NULL;
    //boolean condition to run the loop
    bool swapped;
    do {
        swapped = false;
        curr = head;

        while (curr->next != tail) {
            if (curr->data > curr->next->data) {
                swap(curr, curr->next);
                swapped = true;
            }
            curr = curr->next;
        }
        tail = curr;
    } while (swapped==true);
}
void add(int v,node* head){
    // declaration to add value
    node *temp = new node(v);
    
    //condition to handle; if the list is empty or the value is less than the value stored in head
    if (head == NULL || v < head->data) {
        temp->next = head;
        head = temp;
        return;
    }
    
    //iterating to desired position
    node* p = head;
    node* q = NULL;
    while (p != NULL && p->data < v) {
        q = p;
        p = p->next;
    }
    //inserting 
    temp->next = p;
    q->next = temp;
}

int main(){
	//initializing list l1 
    node* list = new node(27);
    list->next = new node(3);
    list->next->next = new node(18);
    list->next->next->next = new node(17);
	//printing the original list 
    cout << "Original List: ";
    display(list);
    //sorting list
    sort(list);
    //printing the sorted list 
    cout << "Sorted List: ";
    display(list);
    //adding value
    add(20,list);
    //printing the final list 
    cout << "Final List: ";
    display(list);
	return 0;
}
