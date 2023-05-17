#include <iostream>
using namespace std;

struct Node{
	int value;
	Node* next;
	Node* previous;
};

//function that inserts a node as a head in a linked list
//time complexity: O(1)
//space complexity: O(1)
Node* insertAtFront(Node* head, int val){
	Node* nodeAtFront = new Node;
	
	//initializing the "attributes" of the new head
	nodeAtFront -> next = head;
	nodeAtFront -> previous = NULL;
	nodeAtFront -> value = val;
	
	if(head != NULL)
		head -> previous = nodeAtFront;
	
	return nodeAtFront;
}
	
//function that inserts a new node after a given node in a linked list 
//time complexity: O(1)
//space complexity: O(1)
void insertAfter(Node* head, int val, Node* loc){
	if(head == NULL)
		return;
	
	//creating a new node
	Node* newNode = new Node;
	
	//inserting the new node 
	newNode -> value = val;
	newNode -> next = loc -> next;
	newNode -> previous = loc;
	if(loc -> next != NULL)
		loc -> next -> previous = newNode;
	loc -> next = newNode;
	
	return;
}
	
//helper function to test
	
//this function traverses a linked list  
void printingLinkedList(Node* head){
	cout << "Current linked list: ";
	
	//traversing the linked list until the tail
	while(head != NULL){
		cout << head -> value << " ";
		head = head -> next;
	}
	
	cout << "\n";
		return;
}
	
bool IsPalindrome(Node* head){
	if(head == NULL)
		return true;
	
	Node* tail = head;
	Node* backNode;
	Node* frontNode;
	int size = 1;
	bool itIs = true;
	
	//looking for the tale
	while(tail -> next != NULL){
		//traversing the linked list
		tail = tail -> next;
		size++;
	}
	
	backNode = tail;
	frontNode = head;	
	
	for(int i = 0; i < size/2; i++){
		if(frontNode -> value != backNode -> value){
			itIs = false;
			break;
		}
		frontNode = frontNode -> next;
		backNode = backNode -> previous;
	}
	
	return itIs;
}

void test(){
	//we start we an empty linked list so we need to use the fuction "insert at
	//front" due to this function can define/make a new head, after that, I can
	//test the left functions
	Node* head = NULL;
	
	head = insertAtFront(head, 9);
	insertAfter(head, 9, head);	
	insertAfter(head, 2, head);	
	insertAfter(head, 4, head);	
	insertAfter(head, 2, head);	
	//Current linked list: NULL<-9<->2<->4<->2<->9->NULL

	printingLinkedList(head);
	if(IsPalindrome(head)){
		cout<<"True\n\n";
	}else{
		cout<<"False\n\n";
	}
	
	//just another test case
	insertAfter(head, 12, head);	

	printingLinkedList(head);
	if(IsPalindrome(head)){
		cout<<"True\n";
	}else{
		cout<<"False\n";
	}
	
	
	return;
}

int main() {
	
	test();
	
	return 0;
}

