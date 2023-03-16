/*	
	where N=array size
	Time complexity=O(N);
	Space complexity=O(N);
	
	Technique->Prefix sums
	Time used:
	Reading And Coding Solution->29 min and 19 sec
	Coding the testing function,cases and debugging-> 8 min and 7 sec
	Total time->37 min and 26 sec
	
	Assumptions:
	-The array have only integer numbers (although it should work in the most of the cases with real numbers).
	
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 		 my thoughts
 		Input Array: [4, 5, 2, -1, -3, -3, 4, 6, -7]
		
		I will build and prefix_array like this and I will save these values in a hashtable 
								 [4, 9, 11, 10, 7, 4, 8, 14, 7]	
		this array is like and array of accumulated values where I save the sum from all the numbers
		since the beginning until the ith position
								
		since my sought value is zero I will check this
							
								 if set.count( prefix_array[current_index] ) == true then
								 	con++;
	
		Output: 2
		(Subarrays: [5, 2, -1, -3, -3], [-3, 4, 6, -7])
	
		[8, -5, 0, -2, 3, -4]
		[8, 3, 3, 1, 4, 0]
		

		//NOTE:I consider that this idea is hard to understand and explain because
		//it's very visual but the main idea is to play with the sum of the ranges
		//in an array to get the value that we need.
*/


int ZeroSumSubArrays(vector<int> &ar){
	vector<int> prefix_array(ar.size(),0);
	unordered_map<int,int> hashtable;
	int answer=0;
	
	prefix_array[0]=ar[0];
	

	//building the prefix array and saving its values in the hashtable
	for(int i=1;i<ar.size();i++){
		prefix_array[i] = ar[i] + prefix_array[i-1];
		hashtable[prefix_array[i]]++;	
	}
	
	for(int i=0;i<prefix_array.size()-1;i++){
		//erasing the current element in the prefix_array from the hashtable
		//because I just want to check the number that are after my current
		//position
		if(i!=0)
			hashtable[prefix_array[i]]--;
		
		//if I have the same value than the current value in the prefix_array after the current_index, this means that I have found a
		//subarray that sum to zero
		if(hashtable[prefix_array[i]]>0){
			answer+=hashtable[prefix_array[i]];
		}
		
		//it the first case when the subarray starts in the beginning
		if(prefix_array[i]==0)
			answer++;
	}
	
	//I did not verify this in the prior for loop
	if(prefix_array[prefix_array.size()-1]==0)
		answer++;

	return answer;
}


void printer(vector<int> &ar){
	cout<<"Input array: [";

	for(int i=0;i<ar.size();i++)
		if(i!=ar.size()-1)
			cout<<ar[i]<<", ";
		else
			cout<<ar[i]<<"]";
	
	cout<<"\nOutput: "<<ZeroSumSubArrays(ar)<<"\n\n";

	return;
}


void test(){
	vector<int> ar={4, 5, 2, -1, -3, -3, 4, 6, -7};
	printer(ar);

	ar={1, 8, 7, 3, 11, 9};
	printer(ar);

	ar={8, -5, 0, -2, 3, -4};	
	printer(ar);
	//an interesting case
	ar={0, 0, 0, 0, 0, 0, 0, 0, 0};
	printer(ar);

	return;
}

int main(){
	
	test();

	return 0;
}
