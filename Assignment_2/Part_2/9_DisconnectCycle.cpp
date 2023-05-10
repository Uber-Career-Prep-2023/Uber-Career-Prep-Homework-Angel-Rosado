#include <iostream>
#include <unordered_set>
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
	nodeAtFront -> next = head;
	nodeAtFront -> value = val;
	
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

//Function that diconnects a cycle (if it exists) in a singly linked list
//Time Complexity: O(N) where N is the number of nodes
//Space Complexity: O(N)  
void disconnectingCycle(Node* head){
	if(head == NULL)
		return;
	
	//hashmap which saves the adresses of the visited nodes
	unordered_set <Node*> visitedNodes;
	Node* currentNode = head;
	
	visitedNodes.insert(head);
	
	//I continue traversing the linked list while I haven't visited the next
	//node, and also while there is a next node.
	while(currentNode -> next != NULL && visitedNodes.count(currentNode -> next) == false){
		//marking as visited the next node
		visitedNodes.insert(currentNode -> next);
		//updating currentNode
		currentNode = currentNode -> next; 
	}
	
	//if a cycle exists, then we disconnect it changing the next pointer to NULL
	currentNode -> next = NULL;
	
	return;
}

void test(){
	//we start we an empty linked list so we need to use the fuction "insert at
	//front" due to this function can define/make a new head, after that, I can
	//test the left functions
	
	Node* head = NULL;
 	Node* tail = NULL;
	Node* cycle = NULL;
	
	head = insertAtFront(head, 10);
	insertAfter(head, 4, head);
	insertAfter(head, 11, head);
	insertAfter(head, 9, head);
	insertAfter(head, 12, head);
	insertAfter(head, 18, head);
	
	//we traverse the linked list until the last node
	tail = head;
	while(tail -> next != NULL){
		if(tail -> value == 12)
			cycle = tail;
		
		tail = tail -> next;
	}
	//making the cycle
	tail -> next = cycle;
	
	//I just built a testcase
	//Current linked list: 10->18->12->9->11->4->12
	disconnectingCycle(head);
	printingLinkedList(head);	
	
	return;
}
	
	
int main() {
	
	test();
	
	return 0;
}
