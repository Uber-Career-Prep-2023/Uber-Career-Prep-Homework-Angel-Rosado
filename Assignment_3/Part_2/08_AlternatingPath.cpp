/*
	Coding time: 31 minutes
	Testing time: 7 minutes
	Algorithm: Breadth-first search
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
using namespace std;

struct edges{
	char nodeA, nodeB;
	string color;
};

struct nodeType{
	char node;
	string color;
	int shortestPath;
};

struct type{
	char node;
	string color;
};

/*
Main function which returns the length of the shortest path between an origin node
and a destination while this path has to alternate between the two types of edges. 
Time complexity: O(V + E) where V = vertices, E = Edges
Space complexity: O(E) E = Edges
*/
int alternatingPath(map<char, vector<type>> graph, char origin, char destination){

	queue<nodeType> nodesToVisit;
	map<pair<char, string>, bool> visited;

	//Starting the bfs in the origin
	nodesToVisit.push({origin, "-", 0});
	visited[{origin, "-"}] = true;

	//Traversing the graph until every node is visited 
	while(!nodesToVisit.empty()){
		nodeType currentNode = nodesToVisit.front();
		nodesToVisit.pop();

		//If the destination is already found, then is not necessary to continue the bfs
		if(currentNode.node == destination)
			return currentNode.shortestPath;

		//Traversing the edges' list of the current node
		for(auto &nextNode : graph[currentNode.node]){
			/*	
			If I have not visited the next node, and I can arrive right there with 
			and edge of a different color, then I visit it.
			*/
			if(!visited[{nextNode.node, currentNode.color}] && currentNode.color != nextNode.color){
				
				nodesToVisit.push({nextNode.node, nextNode.color, currentNode.shortestPath + 1});
				visited[{nextNode.node, currentNode.color}] = true;

			}

		}

	}

	/*
	If the loop was exited, then it means that 
	there is no path between the two nodes   
	*/
	return -1;
}

//Utility function which converts a list of edges into an adyacency list
map<char, vector<type>> makeAdyacencyList(vector<edges>& edgesList){
	map<char, vector<type>> adyacencyList;

	for(auto &currentEdge : edgesList)
		adyacencyList[currentEdge.nodeA].push_back({currentEdge.nodeB, currentEdge.color});

	return adyacencyList;
}

//Utility function which prints tescases.
void printTest(int shortestPath, char origin, char destination){

	cout << "Input: " << " origin = " << origin << ", ";
	cout << "destination = " << destination << "\n";
	cout << "Output: " << shortestPath << "\n\n";

	return;
}

void tests(){
	vector<edges> edgesList= 
	{{'A', 'B', "blue"}, {'A', 'C', "red"}, {'B', 'D', "blue"}, {'B', 'E', "blue"}, {'C', 'B', "red"}, 
	{'D', 'C', "blue"}, {'A', 'D', "red"}, {'D', 'E', "red"}, {'E', 'C', "red"}};

	printTest(alternatingPath(makeAdyacencyList(edgesList), 'A', 'E'), 'A', 'E');
	printTest(alternatingPath(makeAdyacencyList(edgesList), 'E', 'D'), 'E', 'D');
	printTest(alternatingPath(makeAdyacencyList(edgesList), 'E', 'E'), 'E', 'E');
	printTest(alternatingPath(makeAdyacencyList(edgesList), 'B', 'C'), 'B', 'C');

	return;
}

int main(){

	tests();

	return 0;
}