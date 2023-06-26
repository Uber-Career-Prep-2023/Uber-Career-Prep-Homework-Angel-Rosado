/*
	Coding time: 3 minutes
	Testing time: 8 minutes
	Algorithm: Sort
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
Main function which returns a sorted array.
Time complexity: O(NlogN) N = array size
Space complexity: O(1) 
*/
vector<int> mergeKSortedArrays(int k, vector<vector<int>> sortedArrays){
	vector<int> resultedArray;

	//Pushing each element of the k sorted arrays into a single array.
	for(int currentSortedArray = 0 ; currentSortedArray < k ; currentSortedArray++)
		for(auto &currentElement : sortedArrays[currentSortedArray])
			resultedArray.push_back(currentElement);

	//Sorting the single array with all the elements.
	sort(resultedArray.begin(), resultedArray.end());

	return resultedArray;
}

//Utility function to print the input.
void printInput(int k, vector<vector<int>>& sortedArrays){
	cout << "Input: " << k <<", ";

	for(int i = 0; i < (int)sortedArrays.size(); i++){
		cout << "[";
		
		for(int j = 0; j < (int)sortedArrays[i].size(); j++){
		
			if(j != (int)sortedArrays[i].size() - 1)
				cout << sortedArrays[i][j] << ", ";
			else
				cout << sortedArrays[i][j] << "]";
		
		}

		if(i != (int)sortedArrays.size() - 1)
			cout<<", ";
		else
			cout<<"]\n";
	}

	return;
}

//Utility function to print the output.
void printOutput(vector<int> resultedArray){
	cout << "Output: [";

	for(int i = 0; i < (int)resultedArray.size(); i++){
		if(i != (int)resultedArray.size() - 1)
			cout << resultedArray[i] << ", ";
		else
			cout << resultedArray[i] << "]\n\n";
	}

	return;
}

void tests(){
	int k = 2;
	vector<vector<int>> sortedArrays = {{1, 2, 3, 4, 5}, {1, 3, 5, 7, 9}};

	printInput(k, sortedArrays);
	printOutput(mergeKSortedArrays(k, sortedArrays));



	k = 3;
	sortedArrays = {{1, 4, 7, 9}, {2, 6, 7, 10, 11, 13, 15}, {3, 8, 12, 13, 16}};

	printInput(k, sortedArrays);
	printOutput(mergeKSortedArrays(k, sortedArrays));

	return;
}

int main(){

	tests();

	return 0;
}