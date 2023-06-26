#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class PriorityQueue{
	private:
		vector<pair<string, int>> array;

	public:
		string top();
		void insert(string x, int weight);
		void remove();
		bool empty();
};

/*
Priority Queue method which returns the string with the maximum weight in the heap.
Time complexity: O(1)
Auxiliary space: O(1)
*/
string PriorityQueue::top(){
	/*
	We return the first value of the array while the array is not empty,
	otherwise return NULL.
	*/
	if(!array.empty())
		return array[0].first;
	return NULL;
}


/*
Priority Queue method which receives an integer and inserts it 
in the priority queue mantaining its properties.
Time complexity: O(logN) N = priority queue size.
Auxiliary space: O(1)
*/
void PriorityQueue::insert(string x, int weight){
	array.push_back({x, weight});
	
	//Position of the inserted value.
	int valuePosition = array.size() - 1;

	/*
	While the value that we are trying to insert mantaining the properties 
	of the max heap is not in the position zero, we continue checking
	if its parent is smaller than it.
	*/
	while(valuePosition){
		int valueParentPosition = (valuePosition - 1) / 2;
		
		/*
		If the value inserted already fulfills the place it should,
		we end the function, otherwise... 
		*/
		if(array[valuePosition].second <= array[valueParentPosition].second)
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
Priority Queue method which removes the top of the max heap, ergo the string 
with maximum weight.
Time complexity: O(logN) N = priority queue size.
Auxiliary space: O(1)
*/
void PriorityQueue::remove(){
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
	Lets call "inserted value" to the value that we swapped for the former maximum value,
	the reason for this is to imagine that we are inserting this value in the max heap.

	We check what is the maximum value between the children of the inserted value, 
	after that we swap this maximum value with the inserted value ONLY IF the maximum 
	value is smaller than the inserted value, otherwise we end the function.
	*/
	while(leftChild < arraySize){
		/*
		Special case when we are comparing a node with just one child. Because 
		a heap is a nearly-completed binary tree, then it means that the child 
		does not have more children and therefore can end the function here.
		*/
		if(rightChild >= arraySize){
			if(array[leftChild].second > array[(leftChild - 1) / 2].second)
				swap(array[leftChild], array[(leftChild - 1) / 2]); 
			return;
		}

		
		//Obtaining the maximum value
		if(array[leftChild].second > array[rightChild].second){

			//Verifying that the inserted value is "breaking" the heap.
			if(array[leftChild].second <= array[(leftChild - 1) / 2].second)
				return;

			//Swapping the maximum value with the inserted value.
			swap(array[leftChild], array[(leftChild - 1) / 2]);
			//Actualizing children
			rightChild = (leftChild * 2) + 1;
			leftChild = (leftChild * 2) + 2;

		}else{

			//Verifying that the inserted value is "breaking" the heap.
			if(array[rightChild].second <= array[(rightChild - 1) / 2].second)
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

/*
Utility function that returns true if the heap is empty.
Time complexity: O(1)
Auxiliary space: O(1)
*/
bool PriorityQueue::empty(){
	return array.empty();
}


void tests(){
	PriorityQueue maxHeap;
	pair<string, int> data[10] = {{"Angel", 7}, {"Ernesto", 8}, {"David", 4}, {"Raul", 8}, 
	{"Maria", 10}, {"Monse", 1}, {"Camila", 6}, {"Sergio", 11}, {"Vivi", 6}, {"Valeria", 23}}; 

	cout << "People in the hospital and the priority level of their urgencies:\n";
	for(auto &personData : data){
		maxHeap.insert(personData.first, personData.second);
		cout << "{" << personData.first << ", " << personData.second << "}\n";
	}
	cout <<"\n";


	int counter = 1;
	while(!maxHeap.empty()){
		
		cout << maxHeap.top() << " is the #" << counter << " person that should be attended\n";
		cout << "Attending...\n"; maxHeap.remove();

		counter++;
	}

	return;
}

int main(){

	tests();

	return 0;
}