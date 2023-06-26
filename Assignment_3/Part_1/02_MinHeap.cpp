#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Heap{
	private:
		vector<int> array;
	
	public:
		int top();
		void insert(int value);
		void remove();	
};

/*
Heap method which returns the minimum integer in the heap.
Time complexity: O(1)
Auxiliary space: O(1)
*/
int Heap::top(){
	/*
	We return the first value of the array while the array is not empty,
	otherwise return the maximum integer.
	*/
	if(!array.empty())
		return array[0];
	return INT_MAX;
}

/*
Heap method which receives an integer and inserts it in the heap mantaining
its properties.
Time complexity: O(logN) N = heap size.
Auxiliary space: O(1)
*/
void Heap::insert(int value){
	array.push_back(value);
	
	//Position of the inserted value.
	int valuePosition = array.size() - 1;

	/*
	While the value that we are trying to insert mantaining the properties 
	of the min heap is not in the position zero, we continue checking
	if its parent is greater than it.
	*/
	while(valuePosition){
		int valueParentPosition = (valuePosition - 1) / 2;
		
		/*
		If the value inserted already fulfills the place it should,
		we end the function, otherwise... 
		*/
		if(array[valuePosition] >= array[valueParentPosition])
			return;

		/*
		... we swap the values of the value inserted and its current parent.
		Finally, we actualize the position of the inserted value.
		*/
		swap(array[valuePosition], array[valueParentPosition]);
		valuePosition = valueParentPosition;
	}

	return;
}

/*
Heap method which removes the top of the heap, ergo the minimum value.
Time complexity: O(logN) N = heap size.
Auxiliary space: O(1)
*/
void Heap::remove(){
	/*
	Removing elements from the end of the array is O(1), so we swap the element 
	that we want to erase with the last element of the array and erase the last
	element.
	*/
	swap(array[0], array[array.size() - 1]);
	array.pop_back();

	//Heapifying

	int leftChild = 1, rightChild = 2;
	int arraySize = array.size();

	/*
	Lets call "inserted value" to the value that we swapped for the former minimum value,
	the reason for this is to imagine that we are inserting this value in the heap.

	We check what is the minimum value between the children of the inserted value, 
	after that we swap this minimum value with the inserted value ONLY IF the minimum value
	is smaller than the inserted value, otherwise we end the function.
	*/
	while(leftChild < arraySize){
		/*
		Special case when we are comparing a node with just one child. Because 
		a heap is a nearly-completed binary tree, then it means that the child 
		does not have more children and therefore can end the function here.
		*/
		if(rightChild >= arraySize){
			if(array[leftChild] < array[(leftChild - 1) / 2])
				swap(array[leftChild], array[(leftChild - 1) / 2]); 
			return;
		}

		
		//Obtaining the minimum value
		if(array[leftChild] < array[rightChild]){

			//Verifying that the inserted value is "breaking" the heap.
			if(array[leftChild] >= array[(leftChild - 1) / 2])
				return;

			//Swapping the minimum value with the inserted value.
			swap(array[leftChild], array[(leftChild - 1) / 2]);
			//Actualizing children
			rightChild = (leftChild * 2) + 1;
			leftChild = (leftChild * 2) + 2;

		}else{

			//Verifying that the inserted value is "breaking" the heap.
			if(array[rightChild] >= array[(rightChild - 1) / 2])
				return;

			//Swapping the minimum value with the inserted value.
			swap(array[rightChild], array[(rightChild - 1) / 2]);
			//Actualizing children 
			leftChild = (rightChild * 2) + 1;
			rightChild = (rightChild * 2) + 2;

		}

	}

	return;
}


void tests(){
	Heap minHeap;
	int numbers[10] = {7, 8, 4, 8, 10, 1, 6, 11, 6, 23};

	cout << "Values in the heap: ";
	for(auto &number : numbers){
		minHeap.insert(number);
		cout << number << ", ";
	}
	cout <<"\n";

	cout << "This is the current minimum value: " << minHeap.top() << "\n";
	cout << "Removing top\n"; minHeap.remove();

	cout << "This is the current minimum value: " << minHeap.top() << "\n";
	cout << "Removing top\n"; minHeap.remove();

	cout << "This is the current minimum value: " << minHeap.top() << "\n";
	cout << "Removing top\n"; minHeap.remove();

	cout << "This is the current minimum value: " << minHeap.top() << "\n";
	cout << "Removing top\n"; minHeap.remove();
	
	cout << "This is the current minimum value: " << minHeap.top() << "\n";
	cout << "Removing top\n"; minHeap.remove();
	
	cout << "This is the current minimum value: " << minHeap.top() << "\n";
	cout << "Removing top\n"; minHeap.remove();

	cout << "This is the current minimum value: " << minHeap.top() << "\n";
	cout << "Removing top\n"; minHeap.remove();

	cout << "This is the current minimum value: " << minHeap.top() << "\n";
	cout << "Removing top\n"; minHeap.remove();

	cout << "This is the current minimum value: " << minHeap.top() << "\n";
	cout << "Removing top\n"; minHeap.remove();

	cout << "This is the current minimum value: " << minHeap.top() << "\n";
	cout << "Removing top\n"; minHeap.remove();

	return;
}

int main(){

	tests();

	return 0;
}