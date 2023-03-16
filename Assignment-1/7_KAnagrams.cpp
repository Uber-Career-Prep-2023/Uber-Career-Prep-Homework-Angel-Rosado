/*
	where N=string length
	Time complexity=O(2N) amortized;
	Space complexity=O(2N);
	
	Technique->Hashing technique (Increment and decrement hashmap counts)
	
	Time used:
	Reading And Coding Solution->7 min and 29 sec
	Coding the testing function,cases and debugging-> 9 min and 2 sec
	Total time->16 min and 31 sec
	
	Assumptions:
	-The operation K does not allow to add a character to the string
	-I can change the order of the characters in the string and this does not count as a K operation.

*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string KAnagrams(string string_1, string string_2,int k){
	if(string_1.length()!=string_2.length())
		return "False";
	
	unordered_map<char,int> hashmap;
	int counter=0;

	//Storing the elements of the 2nd  string in the hashmap
	for(int i=0;i<string_2.length();i++){
		if(hashmap.count(string_2[i]))
			hashmap.find(string_2[i])->second++;
		else
			hashmap.insert({string_2[i],1});
	}

	for(int i=0;i<string_1.length();i++){
		auto it=hashmap.find(string_1[i]);
		//If the ith element of the string_1 is in the hashmap then, we reduce one
		//becase we already "matched" this element. Else, we add one
		//to the "counter" which counts how many chars we need to replace. 
		if(it!=hashmap.end() && it->second > 0){
			it->second--;
		}else{
			counter++;
		}
	
	}

	if(counter>k)
		return "False";
	return "True";
}	

void printer(string s1,string s2,int k){
	cout<<"Input Strings: "<<s1<<" , "<<s2<<"\n";
	cout<<"Input k: "<<k<<"\n";
	cout<<"Output: "<<KAnagrams(s1,s2,k)<<"\n\n";
	return;
}


void test(){
	string s1,s2;
	int k;

	s1="apple";
	s2="peach";
	k=1;
	printer(s1,s2,k);

	s1="apple";
	s2="peach";
	k=2;
	printer(s1,s2,k);

	s1="cat";
	s2="dog";
	k=3;
	printer(s1,s2,k);

	s1="debit curd";
	s2="bad credit";
	k=1;
	printer(s1,s2,k);

	s1="baseball";
	s2="basketball";
	k=2;
	printer(s1,s2,k);
	return;
}

int main(){
	test();

	return 0;
}
