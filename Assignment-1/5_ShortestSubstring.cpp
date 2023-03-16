/*	
	where N=Input string size
	Time complexity=O(N);
	Space complexity=O(N);
	
	Technique->Sliding window
	Time used:
	Reading And Coding Solution->36 min and 58 sec
	//I spent several time looking for a bug :c
	Coding the testing function,cases and debugging-> 15 min and 11 sec
	Total time->52 min and 9 sec

	Assumptions:
	-The second substring should not be an empty string 
	-All the characters are lowercase letters (although the code should work also with lowercase and uppercase letters)
	-Always exists at least one substring containing all the required characters (otherwise my code prints 0)
*/
#include <iostream>
#include <unordered_map>
using namespace std;

/*
 
	My thoughts:

	-look for the first valid Substring
	-begin=0 and end=Substring.size()
	
	-I need a counter that is equal to zero when I have all the chars
	of the sought string
	-I need a hashtable to save if a char is in the sought string and 	the number of ocurrences that I need 

	-for(){
		increment my begin while it is a valid Substring 
			it is a valid substring if counter continues being zero 
		
		increment end while it isnt a valid substring 

		when I move forward, I need to delete the char that is no longer 		
		in my window, so I increment the value in my hashtable and if this value is now greater than 0 then
		I add 1 to my counter
	}

*/

int ShortestSubstring (string input_string, string required_characters){
	//remaining_chars to make a string valid
	int begin,end,remaining_chars=required_characters.size(),answer=0;
	
	//Valid char ocurrences that I need to get a valid string
	unordered_map <char,int> chars_ocurrences;
	
	for(int i=0;i<required_characters.size();i++)
		chars_ocurrences[required_characters[i]]++;
		
	for(begin=0, end=0; begin<input_string.size() &&  end<input_string.size();){
		
		if(remaining_chars>0){
			
			if(chars_ocurrences.count(input_string[end])){ //If Im looking for this char
			
				//decrementing the num of chars that I need to make a substring valid 
				if(chars_ocurrences[input_string[end]]-- > 0)
					remaining_chars--;
				
			}
			if(remaining_chars==0){
				//updating my answer
				if(answer!=0)
					answer=min(answer,end-begin+1);
				else
					answer=end-begin+1;
			}

			end++;

		}else{ //remaining_chars==0

			if( chars_ocurrences.count(input_string[begin]) ){//If Im seeking this char
			
				//incrementing the number of chars that I need to make substring no valid 
				if(chars_ocurrences[input_string[begin]]++ >= 0)
					remaining_chars++;
			}

			begin++;
			
			if(remaining_chars==0){
				//updating my answer
				if(answer!=0)
					answer=min(answer,end-begin);
				else
					answer=end-begin;
			}
				
		}

	}
	//an special case when I have a valid substring that ends exactly in the last
	//character 
	while(begin < input_string.size() && remaining_chars==0){		

		if( chars_ocurrences.count(input_string[begin]) ){//If Im seeking this char
		//incrementing the number of chars that I need to make the substring valid 
			if(chars_ocurrences[input_string[begin]]++ >= 0)
				remaining_chars++;
		}

		begin++;
			
		if(remaining_chars==0){
			//updating my answer
			if(answer!=0)
				answer=min(answer,end-begin);
			else
				answer=end-begin;
		}
	
	}


	return answer;
}

void printer(string s1, string s2){
	
	cout<<"Input strings: "<<s1<<", "<<s2<<"\n";
	cout<<"Output: "<<ShortestSubstring(s1,s2)<<"\n\n";

	return;
}

void test(){
	string s1="abracadabra",s2="abc";
	printer(s1,s2);

	s1="zxycbaabcdwxyzzxwdcbxyzabccbazyx";
	s2="zzyzx";	
	printer(s1,s2);

	s1="dog";
	s2="god";	
	printer(s1,s2);

	return;
}

int main(){
	
	test();

	return 0;
}
