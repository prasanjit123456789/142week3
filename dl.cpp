/*Implement Doubly Linked List using C++. Make sure the following functions are implemented: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
	It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. 

*/
#include <iostream>
using namespace std;
//define class
class Node{
    //make public
    public:
    int data;
    //define pointers
    Node *next=NULL;
    Node *prev=NULL;
};
//ANOTHER class called Doublelink
class Doublelink{
    //make public
    public:
    Node* head;
    Node* tail;
    //constructor
    Doublelink(){
        head=NULL;
        tail=NULL;
    }
    //insert function that inserts the values
    void insert(int value){
        //create new Node
        Node *temp=new Node;
        //condition for forward link
        if(head==NULL){
            head=temp;
        }
        else{
            tail->next=temp;
        }
        //condition for backward link
        if(head==temp){
            head->prev=NULL;
        }
        else{
            temp->prev=tail;
        }
        tail=temp;
        //insert the values
        temp->data=value;
    }
	//use insertAt function that inserts a new node at certain position
	void insertAt(int pos,int value){
		//if position is not avialable
		if(pos>countItems()){
			cout<<"This position is not possible"<<endl;			
		}
		else{
			//create new node
			Node* temp=new Node;
			temp->data=value;
			int i=1;
			Node* current=head;
			while(i<pos-1){
				i++;
				current=current->next; 
			}
			temp->next=current->next;
			current->next->prev=temp;
			//now update the address stored in the node
			current->next=temp;
			temp->prev=current;
			//cout<<endl<<current->data<<endl;
		}
	}
	//use deleteAt function that will delete a selectt node
	void deleteAt(int pos){
		//call by contItems function
		if(pos>countItems()){
			cout<<"This position is not avialable.";	
		}
		else{
			int i=1;
			Node* current=head;
			while(i<pos){
				current=current->next;
				i++;
			}
			Node* temp=current;
			current->prev->next=current->next;
			current->next->prev=current->prev;
			delete temp;
		}
	} 
	//use delet function that deletes the last list
	void delet(){
		Node* temp=tail->prev;
		temp->next=NULL;
		delete tail;
		tail=temp;
	}
	int countItems(){
		int i=1;
		Node* current=head;
		while(current!=tail){
			current=current->next;
			i++;
		}
		return i;
	}
	//display all the datas in the linked list
	void display(){
		Node* current=head;
		while(current!=NULL){
			cout<<current->data<<"->";
			current=current->next;
		}
		cout<<endl;
	}
};
int main(){
	Doublelink d;
	for(int i=0;i<10;i++){
		d.insert(i);
	}
	d.insertAt(2,55);
	d.deleteAt(3);
	d.delet();
	cout<<"The number of linkedlists are="<<d.countItems()<<endl;
	d.display();
    return 0;
}

