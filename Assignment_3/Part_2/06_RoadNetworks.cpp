/*
Assumptions: For this problem I am assuming that the roads are undirected in consequence
of the answers in the testcases, and also considering that if the edges were directed,
it would be a hard problem were you need to count the number of strongly connected
components.

Time coding: 15 min
Time testing: 10 min
Algorithm used: dfs
*/
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

struct edges{
	string nodeA, nodeB;
};

//Overloading the == operator for the helper struct edges
bool operator==(const edges& a, const edges& b){
	return a.nodeA == b.nodeA && a.nodeB == b.nodeB;
}

/*
Generic dfs which marks as visited every visited node

Time complexity: O(R) where R = # of roads
(time and space used is because the dfs is not neccesary visiting all the vertices)
Space complexity: O(R)
*/
void dfs(string currentNode, map<string, vector<string>>& graph, unordered_map<string, bool>& visited){

	for(auto &nextNode : graph[currentNode]){
		if(!visited[nextNode]){
			visited[nextNode] = true; 
			dfs(nextNode, graph, visited);
		}		
	}

	return;
}

/*
Main function which returns the number of road networks in a state. To obtain this,
every town which is connected with at least another town should be visited
and marked as that, and also every connected town to this town. Dfs is used to 
achieve the mentioned before. Everytime a dfs is made is the total number of 
road networks. If the dfs function is never called, then there is no road network.

Time complexity: O(T + R) where: T = # of towns && R = # of roads
Space complexity: O(T + R)
*/
int roadNetworks(map<string, vector<string>> graph){
	int numberOfRoadNetworks = 0;
	unordered_map<string, bool> visited;

	for(auto &currentNode : graph){
		if(!visited[currentNode.first]){
			visited[currentNode.first] = true;
			dfs(currentNode.first, graph, visited);
			numberOfRoadNetworks++;
		}

	}

	return numberOfRoadNetworks;
}

//Utility function to construct an adyacency list from an edges list
map<string, vector<string>> makeAdyacencyList(vector<edges>& edgesList){
	map<string, vector<string>> adyacencyList;

	for(auto &currentEdge : edgesList)
		adyacencyList[currentEdge.nodeA].push_back(currentEdge.nodeB),
		adyacencyList[currentEdge.nodeB].push_back(currentEdge.nodeA);

	return adyacencyList;
}

void printInputOutput(vector<string>& townsList, vector<edges>& edgesList, int numberOfRoadNetworks){
	cout << "Input: [";

	for(auto &currentTown : townsList){
		if(currentTown != townsList.back())
			cout << currentTown << ", ";
		else
			cout << currentTown << "]\n";
	}	

	for(auto &currentEdge : edgesList){
		if(currentEdge == edgesList.front())
			cout << "[(" << currentEdge.nodeA << ", " << currentEdge.nodeB << "), "; 
		else if(currentEdge == edgesList.back())
			cout << '(' << currentEdge.nodeA << ", " << currentEdge.nodeB << ")]\n";
		else
			cout << '(' << currentEdge.nodeA << ", " << currentEdge.nodeB << "), ";
			 
	}

	cout << "Output: " << numberOfRoadNetworks << "\n\n";

	return;
}

void tests(){
	vector<edges> edgesList = {{"Anchorage", "Homer"}, {"Glacier Bay", "Gustavus"}, 
	{"Copper Center", "McCarthy"}, {"Anchorage", "Copper Center"}, {"Copper Center", "Fairbanks"}, 
	{"Healy", "Fairbanks"}, {"Healy", "Anchorage"}};
	
	vector<string> townsList = {"Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth",
	"Glacier Bay", "Fairbanks", "McCarthy", "Copper Center", "Healy""Skagway", "Juneau", "Gustavus",
	"Homer", "Port Alsworth", "Glacier Bay", "Fairbanks", "McCarthy", "Copper Center", "Healy"};

	printInputOutput(townsList, edgesList, roadNetworks(makeAdyacencyList(edgesList)));

	vector<edges> edgesList2 = {{"Kona", "Volcano"}, {"Volcano", "Hilo"}, {"Lahaina", "Hana"}, 
	{"Kahului", "Haiku"}, {"Hana", "Haiku"}, {"Kahului", "Lahaina"}, {"Princeville", "Lihue"}, {"Lihue", "Waimea"}}; 

	vector<string> townsList2 = {"Kona", "Hilo", "Volcano", "Lahaina", "Hana", "Haiku", 
	"Kahului", "Princeville", "Lihue", "Waimea"};
	
	printInputOutput(townsList2, edgesList2, roadNetworks(makeAdyacencyList(edgesList2)));

	return;
}

int main(){

	tests();

	return 0;
}