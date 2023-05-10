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
	
//function that returns the number of nodes in a linked list
//time complexity: O(N) where N=size of the linked list
//space complexity: O(1) 
int length(Node* head){ 
	if(head == NULL)
		return 0;
	
	//the default value is one because a linked list at least has one node  
	int linkedListLength = 1;
	Node* currentNode = head;
	
	//we traverse the linked list until the last node
	while(currentNode -> next != NULL){
		linkedListLength++;
		currentNode = currentNode -> next;
	}
	
	return linkedListLength;
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
	
	
//Function that move the nth from the last element to the front of the list.
//Time Complexity: O(N) Where N is the number of nodes
//Space Complexity: O(1)
Node* moveNthLastToFront(Node* head, int k){
	if(head == NULL)
		return head;
	
	//declaring the number of nodes we need to traverse
	int leftNodesToTraverse =  length(head) - k - 1;
	Node* beforeCurrentNode = head;
	Node* currentNode = head -> next;
	
	//traversing the linked list
	while(currentNode != NULL){
		
		if(leftNodesToTraverse == 0){
			//moving to front the currentNode
			beforeCurrentNode -> next = currentNode -> next;
			currentNode -> next = head;
			//updating the new head
			head = currentNode;
			break;
		}
		
		//just updating info to continue the loop
		beforeCurrentNode = currentNode;
		currentNode = currentNode -> next;
		leftNodesToTraverse--;
	}
	
	//returning the new head
	return head;
}
	
void test(){
	//we start with an empty linked list so we need to use the fuction "insert at
	//front" due to this function can define/make a new head, after that, I can
	//test the left functions
	
	Node* head = NULL; 	
	
	head = insertAtFront(head, 15);
	insertAfter(head, 19, head);
	insertAfter(head, 6, head);
	insertAfter(head, 11, head);
	insertAfter(head, 9, head);
	insertAfter(head, 20, head);
	insertAfter(head, 7, head);
	insertAfter(head, 8, head);
	insertAfter(head, 2, head);
	//Current linked list: 15->2->8->7->20->9->11->6->19->NULL
	
	//just printing
	cout << "--This is the first test case-- \nInput: \n";
	printingLinkedList(head);
	cout << "\nOutput: \n";
	printingLinkedList(moveNthLastToFront(head, 2));
	cout << "\n\n\n";
	
	//just another test case
	head = NULL;
	
	head = insertAtFront(head, 15);
	insertAfter(head, 19, head);
	insertAfter(head, 6, head);
	insertAfter(head, 11, head);
	insertAfter(head, 9, head);
	insertAfter(head, 20, head);
	insertAfter(head, 7, head);
	insertAfter(head, 8, head);
	insertAfter(head, 2, head);
	//Current linked list: 15->2->8->7->20->9->11->6->19->NULL
	
	//just printing
	cout << "--This is the second test case-- \nInput: \n";
	printingLinkedList(head);
	cout << "\nOutput: \n";
	printingLinkedList(moveNthLastToFront(head, 7));
		
	return;
}

int main() {
	
	test();
	
	return 0;
}

