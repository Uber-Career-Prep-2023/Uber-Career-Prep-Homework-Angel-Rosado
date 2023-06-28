/*
Coding time: 29 minutes
Testing time: I spent 31 minutes looking for a mistake in my code until I 
realized this little point in the given data: "("New York", "Philadelphia.", 2),"
but usually I should have spent like 10 minutes in this part.

Algorithm: breadth-first search
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct edge{
	string origin, destination;
	double travelTime;
};

struct path{
	string destination;
	double travelTime;
};

struct pendingDestination{
	string destination;
	double hoursSpent;
};

//Utility function to construct the adyacency list with the given data.
map<string, vector<path>> makeGraph(vector<edge> destinations){
	map<string, vector<path>> graph;

	for(auto &city : destinations){
		graph[city.origin].push_back({city.destination, city.travelTime});
		graph[city.destination].push_back({city.origin, city.travelTime});
	}

	return graph;
}

/*
Main function which returns the number of places within k hours of a given city using a 
classic bfs algorithm.
Time complexity: O(E) where E = edges
Auxiliary space: O(E)
*/
int vacationDestinations(string originCity, double maximumTravelTime, vector<edge> destinations){
	map<string, vector<path>> graph = makeGraph(destinations);
	map<string, bool> visited;
	int destinationsWithinKHours = 0;

	queue<pendingDestination> pendingDestinations;
	//At the beginning, the hours spent are zero.
	pendingDestinations.push({originCity, 0});
	visited[originCity] = true;

	//bfs
	while(!pendingDestinations.empty()){
		//Receiving the current city from the pending list.
		string currentCity = pendingDestinations.front().destination;
		double hoursSpent = pendingDestinations.front().hoursSpent; 
		pendingDestinations.pop();

		
		//Traversing the list of reachable cities from the current city.
		for(auto &nextCity : graph[currentCity]){
			double hypotheticalArrivalTime = hoursSpent + nextCity.travelTime;
			
			//Leaving the origin city does not add an hour to the spent time.
			if(currentCity != originCity)
				hypotheticalArrivalTime++;

			//Just visiting next city if it is possible
			if(!visited[nextCity.destination] && hypotheticalArrivalTime <= maximumTravelTime){
				
				/*
				This line can print the places within k hours.
				cout << nextCity.destination << "\n";
				*/

				pendingDestinations.push({nextCity.destination, hypotheticalArrivalTime});
				visited[nextCity.destination] = true;
				destinationsWithinKHours++;
			}
		}

	}

	return destinationsWithinKHours;
}

void tests(){

	vector<edge> edges = {{"Boston", "New York", 4}, {"New York", "Philadelphia", 2}, {"Boston", "Newport", 1.5},
	 {"Washington, D.C.", "Harper's Ferry", 1}, {"Boston", "Portland", 2.5}, {"Philadelphia", "Washington, D.C.", 2.5}};
	string origin = "New York";
	double k = 5;

	cout << "\nInput: [(Boston, New York, 4), (New York, Philadelphia., 2), (Boston, Newport, 1.5), Washington, D.C., Harper's Ferry, 1), (Boston, Portland, 2.5), (Philadelphia, Washington, D.C., 2.5)]\n";
	cout << "Origin: New York\n\n";

	cout << "\nk = " << k << "\n";
	cout << "Output: " <<  vacationDestinations(origin, k, edges) << "\n";

	k = 7;
	cout << "\nk = " << k << "\n";
	cout << "Output: " <<  vacationDestinations(origin, k, edges) << "\n";

	k = 8;
	cout << "\nk = " << k << "\n";
	cout << "Output: " <<  vacationDestinations(origin, k, edges) << "\n";

	return;
}

int main(){

	tests();

	return 0;
}