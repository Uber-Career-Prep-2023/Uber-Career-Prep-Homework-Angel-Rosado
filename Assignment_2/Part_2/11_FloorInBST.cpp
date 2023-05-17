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
		cout<<currentNode->value<<" ";
		inOrder(currentNode -> _right);
	
		return;
	}

};

//Basically, the function is just this three cases:
//
//-If my currentNode is less than the target, move to the right child
//-If my currentNode is greater than the target, move to the left child
//-Otherwise, return the current value 
int traverseTheTree(Node* currentNode, int targetValue){
	if(currentNode -> value < targetValue && currentNode -> _right != NULL)
		return traverseTheTree(currentNode -> _right, targetValue);
	if(currentNode -> value > targetValue && currentNode -> _left != NULL)
		return traverseTheTree(currentNode -> _left, targetValue);
	return currentNode -> value;
}

//Function that returns the floor (greatest element less than or equal 
//to the target) in a BST.
//Time complexity: O(N) N = Number of nodes in the tree	
//Space complexity: O(N?) N = Number of nodes in the tree. 
int floorInBST(BinarySearchTree* myTree, int targetValue){
	//Because of the ease of the recursive function, I am going to use this
	//function just as a wrapper function.
	return traverseTheTree(myTree -> root, targetValue);
}

void test(){
	BinarySearchTree* myTree = new BinarySearchTree;
	
	//creating myTree
	myTree -> getRoot(10);
	myTree -> insertNode(16);
	myTree -> insertNode(17);
	myTree -> insertNode(20);
	myTree -> insertNode(13);
	myTree -> insertNode(8);
	myTree -> insertNode(9);
	
	//First testcase
	cout<<"Input:\n"<<"My tree: [ ";
	myTree -> inOrder(myTree -> root);
	cout<<"]\n"<<"Target = 13\n"<<"Output: "<<floorInBST(myTree, 13)<<"\n\n";
	
	//Second testcase
	cout<<"Input:\n"<<"My tree: [ ";
	myTree -> inOrder(myTree -> root);
	cout<<"]\n"<<"Target = 15\n"<<"Output: "<<floorInBST(myTree, 15)<<"\n";
	
	return;
}

int main() {
	
	test();
	
	return 0;
}

