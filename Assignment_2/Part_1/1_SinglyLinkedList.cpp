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

//function that inserts a node as a tail in a linked list
//time complexity: O(N) where N=size of the linked list
//space complexity: O(1)
//Note: this function does not work with empty linked lists
void insertAtBack(Node* head, int val){    //time complexity: O(N)
	if(head == NULL)
		return;

	Node* nodeAtBack = new Node;	
	Node* oldTail = head;
	
	//traversing the array until the tail
	while(oldTail -> next != NULL){
		oldTail = oldTail -> next; 
	}
	
	//inserting the new Tail
	oldTail -> next = nodeAtBack;
	nodeAtBack -> next = NULL;
	nodeAtBack -> value = val;
	
	return;
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

//function that deletes the head of a given linked list
//time complexity: O(1)
//space complexity: O(1)
Node* deleteFront(Node* head){
	if(head == NULL)
		return head;

	Node* oldHead = head;
	
	//if the linked list just have one node, then the new head does not exist
	//bacuase the linked list now is empty, on the other hand, we just update the
	//new head with the next node of the head
	if(oldHead -> next == NULL)
		head = NULL;
	else
		head = oldHead -> next;
	
	delete oldHead; 

	return head;
} 

//function that deletes the tail of a linked list
//time complexity: O(N) where N=size of the linked list 
//space complexity: O(1)
void deleteBack(Node* head){
	if(head == NULL)
		return;
	
	//special case** when the size of the linked list is one
	if(head -> next == NULL){
		delete head;
		return;
	}
		
	//saving the new tail to change its "attribute" next to null
	//and the old tail to delete it. We initialize the old tail one step after
	//the new tail to reach first the end
	Node *oldTail = head -> next, *newTail = head;

	//traversing all the linked list to find the tail 
	while(oldTail -> next != NULL){
		newTail = oldTail;
		oldTail = oldTail -> next;
	}

	//updating the tail
	newTail -> next = NULL;
	delete oldTail;

	return;
}

//function that deletes a node in a linked list
//time complexity: O(N) where N=size of the linked list
//space complexity O(1)
Node* deleteNode(Node* head, Node* loc){
	if(head == NULL)
		return head;
	
	//case when we need to delete the head 
	if(head == loc){
		//updating the head
		head = head -> next;
		//deleting the old head
		delete loc;
	
	}else{
		Node* nodeBeforeLoc = head;
		
		//looking for the node that is before the node that will be deleted
		while(nodeBeforeLoc -> next != loc){
			nodeBeforeLoc = nodeBeforeLoc -> next;
		}

		//updating the node 
		nodeBeforeLoc -> next = loc -> next;
		delete loc;
	}

	return head;
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


//function that reverses a linked list iteratively and returns the new head 
//time complexity: O(N) where N=size of the linked list
//space complexity: O(1)
Node* reverseIterative(Node* head){
	if(head == NULL)
		return head;
	//declaring three pointers that point to three consecutive nodes
	Node *nextNode = head -> next, *currentNode = head, *previousNode = NULL;
	//changing the link of the old head
	head -> next = NULL;

	while(nextNode != NULL){
		//changing the link of the node pointed by the variable "currentNode"
		currentNode -> next = previousNode;
		//updating pointed nodes
		previousNode = currentNode;
		currentNode = nextNode;
		nextNode = nextNode -> next;
	}
	
	//changing the link of the old tail
	currentNode -> next = previousNode;

	//returning the new head
	return currentNode;
}


//the next function it's a helper function for the function "reverseRecursive"

//this function reverses a linked list reversing the link of a Node and the next node to it recursevely
//(starting from the head of the old linked list), it returns the head of the new linked list
//
//time complexity: O(N) where N=the size of the linked list
//space complexity: O(?) Im not sure how the memory works with the recursion stack 
Node* reverseTheLink(Node* priorNode, Node* currentNode){
	//if the currentNode it's the old tail, then we just reverse its link and send
	//the information of the head through the recursion 
	if(currentNode -> next == NULL){
		currentNode -> next = priorNode;
		//the old tail becomes the head
		return currentNode;
	}
	
	//reversing firstly the link of the next node not to lose the information of
	//who comes after the currentNode
	//
	//sending the information
	Node* newHead = reverseTheLink(currentNode, currentNode -> next);
	//reversing the link of the currentNode 
	currentNode -> next = priorNode;
	
	return newHead;
}

//function that reverses a linked list recursevely and returns the head of the
//new linked list
//time complexity: O(N) where N=size of the linked list
//space complexity O(?) 
Node* reverseRecursive(Node* head){
	if(head==NULL)
		return head;
	return reverseTheLink(NULL, head);
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

void test(){
	//we start we an empty linked list so we need to use the fuction "insert at
	//front" due to this function can define/make a new head, after that, I can
	//test the left functions
	
	Node* head = NULL; 	
	
	//Current linked list:
	printingLinkedList(head);
	head = insertAtFront(head, 1);
	//Current linked list: 1->NULL
	printingLinkedList(head);
	insertAfter(head, 10, head);	
	//Current linked list: 1->10->NULL
	printingLinkedList(head);
	insertAfter(head, 9, head);	
	//Current linked list: 1->9->10->NULL
	printingLinkedList(head);
	insertAfter(head, 8, head);	
	//Current linked list: 1->8->9->10->NULL
	printingLinkedList(head);
	insertAfter(head, 7, head);	
	//Current linked list: 1->7->8->9->10->NULL
	printingLinkedList(head);
	insertAfter(head, 6, head);	
	//Current linked list: 1->6->7->8->9->10->NULL
	printingLinkedList(head);
	insertAfter(head, 5, head);		
	//Current linked list: 1->5->6->7->8->9->10->NULL
	printingLinkedList(head);
	insertAfter(head, 4, head);		
	//Current linked list: 1->4->5->6->7->8->9->10->NULL
	printingLinkedList(head);
	insertAfter(head, 3, head);		
	//Current linked list: 1->3->4->5->6->7->8->9->10->NULL
	printingLinkedList(head);
	insertAfter(head, 2, head);	
	//Current linked list: 1->2->3->4->5->6->7->8->9->10->NULL
	printingLinkedList(head);
	
	head = reverseRecursive(head);
	printingLinkedList(head);
	//Current linked list: 10->9->8->7->6->5->4->3->2->1->NULL
	head = reverseIterative(head);
	printingLinkedList(head);
	//Current linked list: 1->2->3->4->5->6->7->8->9->10->NULL

	deleteBack(head);
	printingLinkedList(head);
	//Current linked list: 1->2->3->4->5->6->7->8->9->NULL
	head = deleteFront(head);
	printingLinkedList(head);
	//Current linked list: 2->3->4->5->6->7->8->9->NULL
	
	insertAtBack(head, 11);
	printingLinkedList(head);
	//Current linked list: 2->3->4->5->6->7->8->9->11->NULL
	insertAfter(head, 0, head);
	printingLinkedList(head);
	//Current linked list: 2->0->3->4->5->6->7->8->9->11->NULL
	deleteNode(head, head -> next);
	printingLinkedList(head);
	//Current linked list: 2->3->4->5->6->7->8->9->11->NULL

	cout << length(head) << "\n";

	return;
}

int main(){
	
	test();

	return 0;
}
