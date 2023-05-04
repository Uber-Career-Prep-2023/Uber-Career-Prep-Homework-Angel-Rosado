#include <iostream>
using namespace std;

struct Node{
	int value;
	Node *_left, *_right;
};

class BinarySearchTree{

	public:
	
	Node* root = new Node;

	//function that searches for the node with the minimum value
	int minimumValue(){
		Node* currentNode = root;

		while(currentNode -> _left != NULL){
			currentNode = currentNode -> _left;
		}
		
		return currentNode -> value;
	}


	//function that searches for the node with the maximum value
	int maximumValue(){
		Node* currentNode = root;

		while(currentNode -> _right != NULL){
			currentNode = currentNode -> _right;
		}

		return currentNode -> value;
	}

	bool containsThisValue(int val){
		Node* currentNode = new Node;
		currentNode = root;

		while(true){
			
			//checking if the currentNode value it's equal to the sought value
			if(currentNode -> value == val)
				return true;

			//If I should go left
			if(val < currentNode -> value){ 
				
				//the sought value does not exist in the BST
				if(currentNode -> _left == NULL)
					return false;

				//updating the current Node
				currentNode = currentNode -> _left;
			
			}else{ //If I should go right

				if(currentNode -> _right == NULL)
					return false;

				//updating the current Node
				currentNode = currentNode -> _right;

			}

		}

	}


	//helper functions for insertNode function
	
	void createNodeAtLeft(Node* loc, int val){
		Node* newNode = new Node;
		
		//initializing the newNode attributes
		newNode -> value = val;
		newNode -> _left = NULL;
		newNode -> _right = NULL;
		
		//linking the newNode with the BST
		loc -> _left = newNode;
	
		return;
	}

	void createNodeAtRight(Node* loc, int val){
		Node* newNode = new Node;
		
		//initializing the newNode attributes 
		newNode -> value = val;
		newNode -> _left = NULL;
		newNode -> _right = NULL;
		
		//linking the newNode with the BST
		loc -> _right = newNode;

		return;
	}

	//function that insert a new Node in the BST
	void insertNode(int val){
		Node* currentNode = root;
		
		//A BST has the property that, in a certain node, the value of the left child of this
		//node should be lesser, and the value of the right child should be
		//greater. We must use this information to insert a node so, basically, we
		//just check if the value that we need to insert in a new node is greater
		//or lesser than the value of the current node and go to the left or right
		//child with this information until the place where we must go does not
		//exist, then we create the new node.

		while(true){
			//if I should go left
			if(val < currentNode -> value){
				
				//Does the left child exist?
				if(currentNode -> _left != NULL){
					currentNode = currentNode -> _left;
				}else{
					createNodeAtLeft(currentNode, val);
					break;
				}

			}else{ // if I should go right
				
				//Does the right child exist?
				if(currentNode -> _right != NULL){
					currentNode = currentNode -> _right;
				}else{
					createNodeAtRight(currentNode, val);
					break;
				}				
			}
			
		}

		return;
	}
	
	/*function that deletes a given Node in the BST 
	int deleteNode(int val){
		

		

	}*/
	
	//helper functions for testing
	
	//initializes the attributes of the root 
	void getRoot(int value){
		
		root -> value = value;
		root -> _left = NULL;
		root -> _right = NULL;

		return;
	}

	void inOrder(Node* currentNode){
		if(currentNode == NULL)
			return;

		inOrder(currentNode -> _left);
		cout<<currentNode -> value<<" ";
		inOrder(currentNode -> _right);

		return;
	}

};

void test(){
	BinarySearchTree* myTree = new BinarySearchTree;
	
	myTree -> getRoot(13);
	myTree -> insertNode(10);
	myTree -> insertNode(1);
	myTree -> insertNode(14);
	myTree -> insertNode(12);
	myTree -> insertNode(16);
	myTree -> insertNode(17);
	myTree -> insertNode(18);
	myTree -> insertNode(5);
	
	cout<<"This is the tree: ";
	myTree -> inOrder(myTree -> root);
	cout<<"\n\n";
	
	for(int i = 1; i < 7; i++){
		if(myTree -> containsThisValue(i))
			cout<<"The tree contains number "<<i<<"\n";
		else
			cout<<"The tree does not contain number "<<i<<"\n";
	}
	cout<<"\n";
	
	cout<<"The minimum value of the tree is: "<<myTree -> minimumValue()<<"\n";
	cout<<"The maximum value of the tree is: "<<myTree -> maximumValue()<<"\n";

	return;
}

int main(){

	test();

	return 0;
}
