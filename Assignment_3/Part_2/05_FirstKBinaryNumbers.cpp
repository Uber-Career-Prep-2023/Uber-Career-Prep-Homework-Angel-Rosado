/*
	Coding time: 20 minutes
	Testing time: 3 minutes
	Algorithm: Hashmap
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


/*
	Utility function which erases the leading zeros.
	Time complexity: O(k) Where k is the size of the array.
	Space complexity: O(1)
*/
void deleteLeadingZeros(vector<string>& binaryNumbers){
	int k = (int)binaryNumbers.size();

	for(int i = 1;i < k; i++)
		for(int j = binaryNumbers[i].size() - 1; binaryNumbers[i][j] == '0'; j--)
			binaryNumbers[i].pop_back();
		
	return;
}

/*
	Utility function which reverses every string from an array of strings.
	Time complexity: O(k) Where k is the size of the array.
	Space complexity: O(1)
*/
void reverseEveryString(vector<string>& binaryNumbers){
	int k = (int)binaryNumbers.size();

	for(int i = 1; i < k; i++)
		reverse(binaryNumbers[i].begin(), binaryNumbers[i].end());

	return;
}

/*
	Main function which returns an array of strings which is composed of the binary
	representation of the first k numbers (indexed in 0).
	Time complexity: O(k) Where k stands for the first k numbers.
	Space complexity: O(k) Where k stands for the first k numbers.
*/
vector<string>  firstKBinaryNumbers(int k){
	vector<string> binaryNumbers(k); 
	binaryNumbers[0] = "0";

	/*
		There is a pattern for the first k numbers in their binary representation.
		The pattern consists in:
		-Alternate between 0 and 1 for the rightmost digit. 
		[0, 1, 0, 1, 0 ...]
		
		-Alternate between 0 and 1 every two numbers for the 2nd rightmost digit. 
		[00, 01, 10, 11, 00 ...]

		-Alternate between 0 and 1 every four numbers for the 3rd rightmost digit. 
		[000, 001, 010, 011, 100 ...]
		
		...

		-Alternate between 0 and 1 every 2^(i-1) numbers for the ith rightmost digit. 
		
	*/
	for(int currentPowerOfTwo = 2; (currentPowerOfTwo / 2) < k; currentPowerOfTwo *= 2){
		/*
			Note 1: Because it is easier and faster in Big O, this code generates the binary numbers backwards.
			Note 2: Do not add anything to the first number because it is going to be 0 and 
			it would become more difficult to delete all the leading zeros. 
		*/
		for(int i = 1; i < k; i++){
			if((i % currentPowerOfTwo) >= (currentPowerOfTwo / 2))
				binaryNumbers[i].push_back('1');
			else
				binaryNumbers[i].push_back('0');
		}

	}

	deleteLeadingZeros(binaryNumbers);
	reverseEveryString(binaryNumbers);

	return binaryNumbers;
}

/*
	Utility function which prints an array of strings.
	Time complexity: O(k) Where k is the size of the array.
	Space complexity: O(1)
*/
void printArray(vector<string> binaryNumbers){
	int k = (int)binaryNumbers.size();

	cout << "Input: " << k << "\n";
	
	cout << "Output: [";
	for(int i = 0; i < k; i++){
		if(i != k-1)
			cout << binaryNumbers[i] << ", ";
		else
			cout << binaryNumbers[i] << "]\n\n";
	}

	return;
}

void tests(){

	printArray(firstKBinaryNumbers(5));
	printArray(firstKBinaryNumbers(10));
	printArray(firstKBinaryNumbers(100));

	return;
}

int main(){

	tests();

	return 0;
}