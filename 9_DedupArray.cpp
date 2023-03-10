/*
 
 	where N=equal to the quantity of elements to delete
	Time complexity=O(N*N); the quantity of elements to delete*the number of elements after the erased number
	Space complexity=O(N);
	
	Technique->two pointers?
	
	Time used:
	Reading And Coding Solution->4 min and 47 sec
	Coding the testing function,cases and debugging-> 8 min and 2 sec
	Total time->12 min and 49 sec
	
	Assumptions:
	-I am not allowed to use another array.
 
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> DedupArray(vector<int>& ar){

	for(int i=0;i<ar.size()-1;i++){
		if(ar[i]==ar[i+1]){
			ar.erase(ar.begin()+i+1);
			i--;
		}
	}
	
	return ar;
}

void printer(vector<int>& ar){
	cout<<"Input Array: [";
	for(int i=0;i<ar.size()-1;i++){
			cout<<ar[i]<<", ";
	}
	cout<<ar[ar.size()-1]<<"]\n";
	
	DedupArray(ar);

	cout<<"Modified Array: [";
	for(int i=0;i<ar.size()-1;i++){
		cout<<ar[i]<<", ";
	}	
	cout<<ar[ar.size()-1]<<"]\n\n";
	
	return;
}

void test(){
	vector<int>ar={1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
	printer(ar);
	ar={0, 0, 1, 4, 5, 5, 5, 8, 9, 9, 10, 11, 15, 15};
	printer(ar);
	ar={1, 3, 4, 8, 10, 12};
	printer(ar);

	return;
}

int main(){
	test();

	return 0;
}
