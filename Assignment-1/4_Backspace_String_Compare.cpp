/* 
	where N=string size
	Time complexity=O(N);
	Space complexity=O(N);
	
	Technique->Simulation
	
	Time used:
	Reading And Coding Solution->17 min and 32 sec
	Coding the testing function,cases and debugging-> 11 min and 21 sec
	Total time->28 min and 53 sec
	
	Assumptions:
	-If I have "###test" I'm not gonna delete anything	
*/

#include <iostream>
#include <string>
using namespace std;

string BackspaceStringCompare(string s1,string s2){
	string final_s1,final_s2;
	int con=0;
	
	for(int i=s1.length()-1;i>=0;i--){
		if(s1[i]=='#'){ //I need to store how many chars I need to delete
			con++;
		}	else if((con>0)){ 		// if con it's not zero I'm not gonna store it in the final
			i-=con-1;							// string since my current i that stands for my
			con=0;								// current position in the string
		}else{ //the default case
			final_s1.push_back(s1[i]);
		}
	}
	
	con=0; //cleaning the count
	
	//the same that in the other for loop but with the second string
	for(int i=s2.length()-1;i>=0;i--){
		if(s2[i]=='#'){
			con++;
		}else if(con>0){
			i-=(con-1);
			con=0;
		}else{
			final_s2.push_back(s2[i]);
		}
	}
	
	//note: the strings are backwards but is not necessary to put them in the
	//right order because I'm not gonna print them 
	
	if(final_s1==final_s2)
		return "True";    //return true if they are equal and false if they
	return "False";     //are different
}

void printer(string s1,string s2){
  cout<<"Input Strings: "<<s1<<", "<<s2<<"\n";
	cout<<"Output: "<<BackspaceStringCompare(s1,s2)<<"\n\n";
	return;
}

void test(){
	string s1,s2;

	s1="abcde";
	s2="abcde";
	printer(s1,s2);

	s1="Uber Career Prep";
	s2="u#Uber Careee#r Prep";
	printer(s1,s2);

	s1="abcdef###xyz";
	s2="abcw#xyz";
	printer(s1,s2);
	
	s1="abcdef###xyz";
	s2="abcdefxyz###";
	printer(s1,s2);

	return;
}

int main(){
	test();
	
	return 0;
}
