/*	
	where N=array size
	Time complexity=O(N);
	Space complexity=O(N);
	
	Technique->Sliding window
	Time used:
	Reading And Coding Solution->9 min and 20 sec
	Coding the testing function,cases and debugging-> 8 min and 8 sec
	Total time->17 min and 28 sec
	Assumptions:
	-Is K always lesser than the array size? !!Otherwise,the Code doesn't work
	-What about an empty array?.
*/

#include <iostream>
#include <vector>
using namespace std;

float MaxMeanSubarray(vector<int>& ar,int k){
	float mean=0,maxmean=0;
	
	for(int i=0;i<k;i++){
		mean+=ar[i];
	}
	maxmean=mean;
	
	for(int i=k;i<ar.size();i++){
		mean+=ar[i]-ar[i-k];
		maxmean=max(maxmean,mean);
	}
	maxmean/=k;
	
	return maxmean; 
}

void testing(){
	vector<int> test = {4, 5, -3, 2, 6, 1};
	cout<<"Input Array: [4, 5, -3, 2, 6, 1] \n"<<"Input k = 2 \n"<<"Output: "<<MaxMeanSubarray(test,2)<<"\n\n";
	
	cout<<"Input Array: [4, 5, -3, 2, 6, 1] \n"<<"Input k = 3 \n"<<"Output: "<<MaxMeanSubarray(test,3)<<"\n\n";
	
	test={1, 1, 1, 1, -1, -1, 2, -1, -1};
	cout<<"Input Array: [1, 1, 1, 1, -1, -1, 2, -1, -1] \n"<<"Input k = 3 \n"<<"Output: "<<MaxMeanSubarray(test,3)<<"\n\n";
	
	test={1, 1, 1, 1, -1, -1, 2, -1, -1, 6};
	cout<<"Input Array: [1, 1, 1, 1, -1, -1, 2, -1, -1, 6] \n"<<"Input k = 5 \n"<<"Output: "<<MaxMeanSubarray(test,5)<<"\n\n";
	
	return;
}


int main() {
	
	testing();
	
	return 0;
}

//Written by Liux2040
