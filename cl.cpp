/*Implement Circular Linked List using C++. Make sure the following functions are implemented: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
	It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 ” for a linked list holding integers in the order 1,2,3,4. 
*/
//define library
#include<iostream>
using namespace std;
//define Node class
class Node{
	//make public
	public:
	//define vaiables
	int data;
	//address pointer
	Node* next=NULL;
};
//define Circlink class
class Circlink{
	//make public
	public:
	//define address pointer
	Node* head;
	Node* tail;
	//define constructor
	Circlink(){
		head=NULL;
		tail=NULL;
	}
	//insert function that inserts the value in the nodes
	void insert(int value){
		//create new node
		Node* temp=new Node;
		//first data will be in the head
		if(head==NULL){
			head=temp;
		}
		else{
			tail->next=temp;
		}
		//insert the value
		temp->data=value;
		temp->next=head;
		tail=temp;
	}
	//insertAt function that inserts a new node at given position
	void insertAt(int pos,int value){
		//if the position is grater than the number of nodes
		if(pos>countItems()){
			cout<<"This position is not avialable."<<endl;
		}
		else{
			//create a new node
			Node* temp=new Node;
			//insert the value
			temp->data=value;
			int i=1;
			Node* current=head;
			while(i<pos-1){
				current=current->next;
				i++;
			}
			temp->next=current->next;
			current->next=temp;
		}
	}
	//delet function that deletes the last node
	void delet(){
		Node* current=head;
		while(current->next!=tail){
			current=current->next;
		}
		//now assign the head in current->next
		current->next=head;
		//delete tail;
		delete tail;
		//update tail
		tail=current;
	}
	//deletAt function that will delete the node of a particular postion
	void deleteAt(int pos){
		//if the pos is greater than the nodes
		if(pos>countItems()){
			cout<<"This position is not avialable."<<endl;
		}
		else{
			Node* current=head;
			int i=1;
			//use loop to find the position
			while(i<pos-1){
				i++;
				current=current->next;
			}
			//cout<<current->data<<endl;
			Node* temp=current->next;
			//update current->next
			current->next=temp->next;
			delete temp;
		}
	}
	//countItems function that counts the number of functions
	int countItems(){
		int i=1;
		Node* current=head;
		while(current!=tail){
			i++;
			current=current->next;
		}
		return i;
	}
	//display function that displays all the datas
	void display(){
		Node* current=head;
		while(current!=tail){
			cout<<current->data<<"->";
			current=current->next;
		}
		cout<<tail->data<<"->"<<endl;
	}
};
//define main function
int main(){
	Circlink c;
	for(int i=0;i<10;i++){
		c.insert(i);
	}c.delet();c.insertAt(2,55);c.deleteAt(5);
	c.countItems();c.display();
	return 0;
}
