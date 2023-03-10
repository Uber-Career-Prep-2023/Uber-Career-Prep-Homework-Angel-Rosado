/*
 
 	where N=equal to number of pairs
	Time complexity=O(N logN); the time complexity it's mostly because of the sort function which uses NlogN of time
	Space complexity=O(N); just the arrays
	
	Technique->Two pointers
	
	Time used:
	Reading And Coding Solution->21 min and 13 sec
	Coding the testing function,cases and debugging-> 8 min and 25 sec
	Total time->29 min and 38 sec
	
	Assumptions:
	-I can print the intervals in any order.
 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int,int>> MergeIntervals(vector<pair<int,int>> List){
	vector<pair<int,int>> NewList;
	int CurrPos;
	

	sort(List.begin(),List.end());
	NewList.push_back(List[0]);
	
	
	for(int i=1;i<List.size();i++){
		CurrPos=NewList.size()-1;
		
		//Checking if the end of the interval (which end is the biggest from the
		//NewList) is greater or equal than the beginning of the current interval
		//to check. If this happens, we must fuse the intervals 
		if( NewList[CurrPos].second >= List[i].first ){
			NewList[CurrPos].second = max( NewList[CurrPos].second, List[i].second );
		}else{
			NewList.push_back(List[i]);
		}

	}

	return  NewList;
}

void printer(vector<pair<int,int>> &TestingList){
		cout<<"Input: [";
	
		for(int i=0;i<TestingList.size();i++){
			cout<<"("<<TestingList[i].first<<", "<<TestingList[i].second<<")"<<", ";
		}
		cout<<"]\n";
		
		TestingList = MergeIntervals(TestingList);
		
		cout<<"Output: [";

		for(int i=0;i<TestingList.size();i++){
			cout<<"("<<TestingList[i].first<<", "<<TestingList[i].second<<")"<<", ";
		}
		cout<<"]\n\n";
		
	return;
}

void test(){
	vector<pair<int,int>> TestingList={{2,3},{4,8},{1,2},{5,7},{9,12}};
	printer(TestingList);
	
	TestingList={{5,8},{6,10},{2,4},{3,6}};
	printer(TestingList);
	
	TestingList={{10,12},{5,6},{7,9},{1,3}};
	printer(TestingList);

	return;
}

int main(){
	
	test();

	return 0;
}
