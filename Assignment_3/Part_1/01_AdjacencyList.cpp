#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

/*	
	Creating and adjacency list which represents a graph.
	Time complexity: O(E) where E it's the amount of edges.
	Space complexity: O(E) where E it's the amount of edges.
*/
map<int, vector<int>> adjacencyList(vector<pair<int, int>>& edges){
	map<int, vector<int>> adjacencyList;
	
	//Traversing the list of edges to create the adjacency list 
	for(auto &currentEdge : edges)
		adjacencyList[currentEdge.first].push_back(currentEdge.second);

	return adjacencyList;
}

/*
	Generic algorithm to traverse iteratively a graph in order to find a target.
	Time complexity: O(V + E) where E it's the amount of edges and V the amount of nodes.
	Space complexity: O(V + E) where E it's the amount of edges and V the amount of nodes.
*/
bool bfs(int source, int target, map<int, vector<int>> graph){

	queue<int> nodesToVisit;
	map<int, bool> visited;

	//Starting the bfs in the source
	nodesToVisit.push(source);
	visited[source] = true;

	//Traversing the graph until every node is visited 
	while(!nodesToVisit.empty()){
		int currentNode = nodesToVisit.front();
		nodesToVisit.pop();

		//If the target is already found, then is not necessary to continue the bfs
		if(currentNode == target)
			return true;

		//Traversing the edges' list of the current node
		for(auto &nextNode : graph[currentNode]){

			//If I have not visited the next node, then I visit it
			if(!visited[nextNode]){

				nodesToVisit.push(nextNode);
				visited[nextNode] = true;

			}

		}

	}

	return false;
}


/*
	Generic algorithm to traverse recursevely a graph in order to find a target.
	Time complexity: O(V + E) where E it's the amount of edges and V the amount of nodes.
	Space complexity: O(V + E) where E it's the amount of edges and V the amount of nodes.
*/
bool dfs(int currentNode, int target, map<int, vector<int>> graph, map<int, bool>& visited){
	//Base case
	if(currentNode == target)
		return true;

	//Traversing the list of edges of the current node
	for(auto &nextNode : graph[currentNode]){
		
		//If I have not visited the next node, then I visit it
		if(!visited[nextNode]){
			visited[nextNode] = true;

			//If the target is already found, then is not necessary to continue the dfs
			if(dfs(nextNode, target, graph, visited))
				return true;
		}

	}

	return false;
}

/*
	Generic dfs that marks nodes as visited and helps making a topo sort.
	Time complexity: O(V + E) where E it's the amount of edges and V the amount of nodes.
	Space complexity: O(E) 
*/
void auxiliaryDFS(int currentNode, map<int, vector<int>>& graph, map<int, bool>& visited, vector<int>& topologicalOrdering){

	//Traversing the list of nodes that can be reached from current node.
	for(auto &nextNode : graph[currentNode])
		if(!visited[nextNode]){
			visited[nextNode] = true;
			auxiliaryDFS(nextNode, graph, visited, topologicalOrdering);
			//The topological sort is being formed backwards with the help of the recursion.
			topologicalOrdering.push_back(nextNode);
		}


	return;
}
/*	
	Generic algorithm which creates a topological ordering of a Directed Acyclic Graph.
	Time complexity: O(V + E) where E it's the amount of edges and V the amount of nodes.
	Space complexity: O(V + E) 
*/
vector<int> topologicalSort(map<int, vector<int>> graph){
	vector<int> topologicalOrdering;
	map<int, bool> visited;
	
	//Traversing all the adyacency list to do dfs in every unvisited node
	for(auto &currentNode : graph)
		if(!visited[currentNode.first]){
			visited[currentNode.first] = true;
			auxiliaryDFS(currentNode.first, graph, visited, topologicalOrdering);
			//The topological sort is being formed backwards with the help of the recursion.
			topologicalOrdering.push_back(currentNode.first);
		}

	
	//Reversing the toposort because has been obtained backwards.
	reverse(topologicalOrdering.begin(), topologicalOrdering.end());
	return topologicalOrdering;
}

void tests(){
	vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {1, 3}, {3, 2}, {2, 0}};
	vector<pair<int, int>> edgesDAG = {{1, 2}, {1, 3}, {2, 4}, {3, 4}};

	cout << "Testing depth-first-search\n\n";
	for(int target = 1; target <= 5; target++){
		map<int, bool> visited;
		if(dfs(1, target, adjacencyList(edges), visited))
			cout << "Node #" << target << " is in the graph\n";
		else
			cout << "Node #" << target << " is not in the graph\n";
	}

	cout << "\nTesting breadth-first-search\n\n";
	for(int target = 1; target <= 5; target++){
		if(bfs(1, target, adjacencyList(edges)))
			cout << "Node #" << target << " is in the graph\n";
		else
			cout << "Node #" << target << " is not in the graph\n";
	}

	cout << "\nTesting topological sort\n\n[";
	vector<int> topologicalOrdering = topologicalSort(adjacencyList(edgesDAG));

	for(unsigned int i = 0; i < topologicalOrdering.size(); i++){
		if(i != topologicalOrdering.size()-1)
			cout << topologicalOrdering[i] << ", ";
		else
			cout << topologicalOrdering[i] << "]\n";
	}


	return;
}

int main(){

	tests();

	return 0;
}