/*	
	where N=string size and Q=number of vowels;
	Time complexity=O(2N);
	Space complexity=O(2N+Q);
	
	Technique->It can be solved with 2 pointers but it's faster to think and implement with a stack; 
	
	Time used:
	Reading And Coding Solution->15 min and 20 sec
	Coding the testing function,cases and debugging->9 min and 2 sec
	Total time->24 min and 22 sec
	
	Assumptions: 
	-Is the string conformed only by alphabet letters?
	-What should I return if a string is empty?
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool IsVowel(char c){
	if(c=='a'|| c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
		return true;
	return false;
}

string ReverseVowels(string originalS){
	string answer;
	stack<char> currentvowel;
	
	for(unsigned int i=0;i<originalS.length();i++){
		if(IsVowel(originalS[i])){
			currentvowel.push(originalS[i]); //Storing all the vowels in a stack
		}
	}
	
	for(unsigned int i=0;i<originalS.length();i++){
		if(IsVowel(originalS[i])){
			answer.push_back(currentvowel.top()); //Because it's a stack, the top element of the stack will be the last vowel
			currentvowel.pop();
		}else{
			answer.push_back(originalS[i]); //it's easier and faster to store the data in a new string because the insertions a deletions in a string are commonly linear in time and space
		}
		
	}
	return answer;
}
void testing(string s){
	cout<<"Input String: "<<s<<"\n";
	cout<<"Modified String: "<<ReverseVowels(s)<<"\n\n";		
	
	return;	
}

void cases(){
	string test="Uber Career Prep";
	testing(test);
	
	test="xyz";
	testing(test);
	
	test="flamingo";
	testing(test);
	
	return;
}


int main() {
	
	cases();
	
	return 0;
}

//Written by Liux2040
