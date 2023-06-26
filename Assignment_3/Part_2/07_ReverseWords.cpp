/*
	Coding time: 12 minutes
	Testing time: 6 minutes
	Algorithm: Two pointers
*/
#include <iostream>
#include <algorithm>
using namespace std;

/*
Main function which returns a string with the last words of the input in the beginning.
Time complexity: O(N) N = size of the string input
Auxiliary space: O(1)
*/
string reverseWords(string input){
	
	const int inputLength = input.length();
	int begin, end;
	begin = end = 0;

	//Traversing the string reversing each word
	while(end < inputLength){
		
		//If we reached a blank space, then we reached the end of a word
		if(input[end] == ' '){
			//Reversing a word of the string
			reverse(input.begin() + begin, input.begin() + end);
			//Updating the beginning of the next word
			begin = end + 1;
		}

		end++;
	}
	//special case when we do not reverse the last word because there is no blank space
	reverse(input.begin() + begin, input.begin() + end);

	//Reversing the entire string, consequently having the words backwards
	reverse(input.begin(), input.end());

	return input;
}


/*
Utility function which prints test cases
*/
void printTestCase(string input, string output){

	cout << "Input: " << input << "\n";
	cout << "Output: " << output << "\n\n";

	return;
}


void tests(){
	string testCase = "Uber Career Prep";
	printTestCase(testCase, reverseWords(testCase));

	testCase = "Emma lives in Brooklyn, New York.";
	printTestCase(testCase, reverseWords(testCase));

	//I am assuming that it does not matter if I also reverse the blank spaces.
	testCase = "ohayo sekai good morning world  ";
	printTestCase(testCase, reverseWords(testCase));

	return;
}

int main(){

	tests();

	return 0;
}