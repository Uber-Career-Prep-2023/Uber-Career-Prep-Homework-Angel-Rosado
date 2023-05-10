#include <iostream>
using namespace std;

struct Node{
	int value;
	Node* next;
};

//function that inserts a node as a head in a linked list
//time complexity: O(1)
//space complexity: O(1)
Node* insertAtFront(Node* head, int val){
	Node* nodeAtFront = new Node;
	
	//initializing the "attributes" of the new head
	nodeAtFront->next = head;
	nodeAtFront->value = val;
	
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
	loc -> next = newNode;
	
	return;
}
	
//function that deletes repeated nodes in a sorted linked list
//time complexity: O(N) where N = number of nodes
//space complexity: O(N) 
Node* dedupSortedList(Node* head){
	if(head == NULL)
		return head;
	
	Node* currentNode = head;
	Node* newNextNode = NULL;
	
	//traversing the linked list while deleting repeated nodes
	while(currentNode -> next != NULL){
		//if the value of my currentNode is diferent of the value of my next 
		//node, delete next node
		if(currentNode -> value == currentNode -> next -> value){
			//saving the next node of the next node of the current Node
			newNextNode = currentNode -> next -> next;
			//deleting the next node
			delete currentNode -> next;
			//updating the nex node
			currentNode -> next = newNextNode;
		}else{
			currentNode = currentNode -> next;
		}
		
	}
	
	return head;
}
//helper function to test
	
//this function traverses a linked list  
void printingLinkedList(Node* head){
	Node* currentNode = head;
	
	cout << "Current linked list: ";
	
	//traversing the linked list until the tail
	while(currentNode != NULL){
		cout << currentNode -> value << " ";
		currentNode = currentNode -> next;
	}
	
	cout << "\n";
	
	return;
}

	
void test(){
	//we start with an empty linked list so we need to use the fuction "insert at
	//front" due to this function can define/make a new head, after that, I can
	//test the left functio
	
	Node* head = NULL; 	
	
	head = insertAtFront(head, 1);
	insertAfter(head, 10, head);
	insertAfter(head, 10, head);
	insertAfter(head, 5, head);
	insertAfter(head, 5, head);
	insertAfter(head, 5, head);
	insertAfter(head, 4, head);
	insertAfter(head, 2, head);
	insertAfter(head, 2, head);
	//Current linked list: 1->2->2->4->5->5->5->10->10->NULL
	
	cout << "--This is the first test case-- \nInput: \n";
	printingLinkedList(head);
	cout << "\nOutput: \n";
	printingLinkedList(dedupSortedList(head));
	cout << "\n\n\n";
	
	//another test case
	head = NULL;
	
	head = insertAtFront(head, 8);
	insertAfter(head, 8, head);
	insertAfter(head, 8, head);
	insertAfter(head, 8, head);
	//Current linked list: 8->8->8->8->NULL
	
	cout << "--This is the second test case-- \nInput: \n";
	printingLinkedList(head);
	cout << "\nOutput: \n";
	printingLinkedList(dedupSortedList(head));
	
	
	return;
}


int main() {
	
	test();
	
	return 0;
}

