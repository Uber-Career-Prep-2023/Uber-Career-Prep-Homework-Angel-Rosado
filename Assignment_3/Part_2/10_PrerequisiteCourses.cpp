/*
	Coding time: 10 minutes
	Testing time: 11 minutes
	Algorithm: Topological Sort
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;


/*
Generic dfs which helps to make the topological ordering backwards through visiting
unvisited nodes.

Time complexity: O(P) P =  # of prerequisite courses
This is the time complexity because the dfs is not visiting every node (course) 
of the graph, but is visiting every node (prerequisites) that is connected to the given node (course), 
so in the worst case, the algorithm is visiting each edge to reach each node 
(every other course is a prerequisite to take the given course).

Space complexity: O(P) 
*/
void dfs(string course, map<string, vector<string>>& prerequisites,
		 map<string, bool>& visited, vector<string>& topologicalSort){

	//Traversing the list of prerequisites needed to take the given course.
	for(auto &prerequisite : prerequisites[course]){
		/*
		If a certain course is not in the toposort, then another dfs is made
		to find the prerequisites to take that course, and after that the course
		is pushed into the toposort.
		*/
		if(!visited[prerequisite]){
			visited[prerequisite] = true;
			dfs(prerequisite, prerequisites, visited, topologicalSort);
			topologicalSort.push_back(prerequisite);
		}
	}

	return;
}


/*
Main algorithm which generates a valid order to take the courses using the topological sort algorithm.
Time complexity: O(C + P) = where: C = # of courses && P = # of prerequisite courses
Space complexity: O(C + P) 
*/
vector<string> prerequisiteCourses(vector<string> courses, map<string, vector<string>> prerequisites){
	vector<string> topologicalSort;
	map<string, bool> visited;

	for(auto &course : courses){
		/*
		If a certain course is not in the list of the valid order to take course,
		then another dfs is made to find the prerequisites to take that course, 
		and after that the course is pushed into the list of the valid order to take the courses.
		*/
		if(!visited[course]){
			visited[course] = true;
			dfs(course, prerequisites, visited, topologicalSort);
			topologicalSort.push_back(course);
		}
	}

	return topologicalSort;
}

//Utility function which print the input.
void printInput(vector<string>& courses, map<string, vector<string>>& prerequisites){
	cout << "Input: [";

	for(unsigned int i = 0; i < courses.size(); i++){
		if(i != courses.size() - 1)
			cout << courses[i] << ", ";
		else
			cout << courses[i] << "],\n{";
	}


	for(auto &course : prerequisites){
		cout << course.first << " : [";
		
		for(unsigned int i = 0; i < course.second.size(); i++){
			if(i != course.second.size() - 1)
				cout << course.second[i] << ", ";
			else
				cout << course.second[i] << "], ";
		}

	}

	cout << "}\n";

	return;
}

//Utility function which prints the output.
void printOutput(vector<string> topologicalSort){
	cout << "Output: [";

	for(unsigned int i = 0; i < topologicalSort.size(); i++){
		if(i != topologicalSort.size() - 1)
			cout << topologicalSort[i] << ", ";
		else
			cout << topologicalSort[i] << "]\n\n";
	}

	return;
}

void tests(){
	//1st testcase
	vector<string> courses = {"Intro to Programming", "Data Structures", "Advanced Algorithms",
	"Operating Systems", "Databases"};

	map<string, vector<string>> prerequisites = {{"Data Structures", {"Intro to Programming"}},
	{"Advanced Algorithms", {"Data Structures"}}, {"Operating Systems", {"Advanced Algorithms"}},
	{"Databases", {"Advanced Algorithms"}}};

	printInput(courses, prerequisites);
	printOutput(prerequisiteCourses(courses, prerequisites));


	//2nd testcase
	courses = {"Intro to Writing", "Contemporary Literature", "Ancient Literature", "Comparative Literature", "Plays & Screenplays"};
	
	prerequisites = {{"Contemporary Literature", {"Intro to Writing"}}, {"Ancient Literature", {"Intro to Writing"}},
	{"Comparative Literature", {"Ancient Literature", "Contemporary Literature"}}, {"Plays & Screenplays", {"Intro to Writing"}}};
	
	printInput(courses, prerequisites);
	printOutput(prerequisiteCourses(courses, prerequisites));

	return;
}

int main(){

	tests();

	return 0;
}