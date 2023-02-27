/*
 	where N=array's size
	Time complexity=O(2N) amortized;
	Space complexity=O(N);
	
	Technique->Hashing technique
	
	Time used:
	Reading And Coding Solution->25 min and 46 sec
	Coding the testing function,cases and debugging-> 10 min and 2 sec
	Total time->35 min and 48 sec
	
	Assumptions:
	-nothing
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int TwoSum (vector<int>& ar,int k){
	unordered_map <int,int> hashtable;
	int pairs=0;
	
	for(int i=0;i<ar.size();i++){
		
		if(hashtable.find(ar[i])!=hashtable.end()){ //checking if I already saved a value with the same key
			hashtable.find(ar[i])->second++;
		}
		
		hashtable.insert({ar[i],1});
		
	}

	for(int i=0;i<ar.size();i++){
		auto current_value=hashtable.find(ar[i]), sought_value=hashtable.find(k-ar[i]) ;
		
		//if I have the current_value and the sought_value in the hashtable
		//then I made pairs with them
		if(current_value->second && sought_value!=hashtable.end() && sought_value->second){ 
			//the number of pairs that we can do with these values is the product of
  		//the total number of occurrences of each one, except if the sought_value
			//and current_value are equal. In this corner case, we are going to 
			//multiply by one the number of occurrences of the value minus 1.
			if(sought_value->first==current_value->first){
				pairs+=(1 * (sought_value->second-1));	
				//Decrementing by one
				current_value->second--;
			}	
			else{
				pairs+=current_value->second * sought_value->second;
				//Erasing the values from the hashtable
				current_value->second=0;
				sought_value->second=0;
			}

		}

	}

	return pairs;
}

void printer(vector<int> &ar, int k){
	cout<<"Input array: [";
	
		for(int i=0;i<ar.size();i++){
			if(i!=ar.size()-1)
				cout<<ar[i]<<", ";
			else
				cout<<ar[i]<<"]\n";
		}

	cout<<"Input k: "<<k<<"\n"<<"Output: "<<TwoSum(ar,k)<<"\n\n";
	
	return;
}

void test(){
	vector<int> ar={1, 10, 8, 3, 2, 5, 7, 2, -2, -1};
	int k=10;

	printer(ar,k);
	
	ar.clear();
	ar={1, 10, 8, 3, 2, 5, 7, 2, -2, -1};
	k=8;
	printer(ar,k);
	

	ar.clear();
	ar={4, 3, 3, 5, 7, 0, 2, 3, 8, 6};
	k=6;
	printer(ar,k);

	ar.clear();
  ar={4, 3, 3, 5, 7, 0, 2, 3, 8, 6};
  k=1;
	printer(ar,k);

	return;
}

int main(){

	test();

	return 0;
}
