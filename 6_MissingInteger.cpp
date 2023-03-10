/* 
	where N=Size of the array
	Time complexity=O(logN);
	Space complexity=O(N);
	
	Technique->Binary Search
	
	Time used:
	Reading And Coding Solution->15 min and 5 sec
	Coding the testing function,cases and debugging-> 11 min and 31 sec
	Total time->26 min and 36 sec
	
	Assumptions:
	-Nothing

*/
#include <iostream>
#include <vector>
using namespace std;

int MissingInteger(vector<int>&ar, int n, int Begin, int End){
	if(Begin==End)
		return Begin;
	
	int Half=(Begin+End)/2;

	if(ar[Half]==Half+1)
		return MissingInteger(ar,n,Half+1,End);
	return MissingInteger(ar,n,Begin,Half);
}

void printer(vector<int> &ar,int n, int Begin, int End){
	
	cout<<"Input Array: [ ";

	for(int i=0;i<ar.size();i++){
		cout<<ar[i]<<", ";
	}
	
	cout<<"]\n";

	cout<<"Input n: "<<n<<"\n"<<"Output: "<<MissingInteger(ar, n, Begin, End)+1<<"\n\n";
	
	return;
}

void test(){
	vector<int> ar={1, 2, 3, 4, 6, 7};
	int n=7;
	printer(ar,n,0,ar.size());
	
	ar={1};
	n=2;
	printer(ar,n,0,ar.size());

	ar={1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12};
	n=12;	
	printer(ar,n,0,ar.size());

	return;
}

int main(){
	
	test();

	return 0;
}
