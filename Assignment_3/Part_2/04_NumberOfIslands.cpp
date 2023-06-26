/*
	Coding time: 29 minutes
	Testing time: 5 minutes
	Algorithm: Depth-first search 
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;


/*
	Utility function to check if a given position is inside the matrix.
	Time complexity: O(1)
	Space complexity: O(1) 
*/
bool validBoundaries(int row, int column, int rowSize, int columnSize){
	return row >= 0 && row < rowSize && column >= 0 && column < columnSize;
}

/*
	Generic algorithm to traverse recursevely a graph marking the places that it visits.
	Time complexity: O(V + E) where E it's the amount of edges and V the amount of nodes.
	Space complexity: O(V + E) where E it's the amount of edges and V the amount of nodes.
*/
void dfs(int row, int column, vector<vector<int>> &adyacencyMatrix, vector<vector<bool>> &visited){
	int placesToMove[4] = {1, -1, 0, 0};

	for(int i = 0; i < 4; i++){
		
		int nextRow = row + placesToMove[i];
		int nextColumn = column + placesToMove[3-i];
		int rowSize = adyacencyMatrix.size();
		int columnSize = adyacencyMatrix[nextRow].size();

		//If that land is inside the adyacency matrix and I have not visited it yet, then I visit it.
		if(validBoundaries(nextRow, nextColumn, rowSize, columnSize) && !visited[nextRow][nextColumn] && adyacencyMatrix[nextRow][nextColumn]){
			visited[nextRow][nextColumn] = true;
			dfs(nextRow, nextColumn, adyacencyMatrix, visited);
		}

	}

	return;
}

/*
	Main function which returns the number of islands in the grid.
	Time complexity: O(V + E) where E it's the amount of edges and V the amount of nodes.
	Space complexity: O(V + E) where E it's the amount of edges and V the amount of nodes.
*/
int numberOfIslands(vector<vector<int>> &adyacencyMatrix){
	vector<vector<bool>> visited(adyacencyMatrix.size(), vector<bool> (adyacencyMatrix[0].size(), false));
	int amountOfIslands = 0;

	//Traversing the adyacency matrix to visit all the islands.
	for(int row = 0; row < (int)adyacencyMatrix.size(); row++){
		for(int column = 0; column < (int)adyacencyMatrix[row].size(); column++){
			
			//If there is a land (1) unvisited, then I dfs that land and visit all contiguos lands (islands).
			if(adyacencyMatrix[row][column] && !visited[row][column]){
				visited[row][column] = true,
				dfs(row, column, adyacencyMatrix, visited);
				amountOfIslands++;
			}

		}
	}

	return amountOfIslands;;
}


/*
	Utility function which prints a matrix.
	Time complexity: O(RC) Where R is the amount of rows and C the amount of columns.
	Space complexity: O(1)
*/
void printMatrix(vector<vector<int>> &matrix){
	
	//Traversing a matrix.
	for(int row = 0; row < (int)matrix.size(); row++){
		for(int column = 0; column < (int)matrix[row].size(); column++){
			cout << matrix[row][column]<<" ";
		}
		cout<<"\n";
	}	
	cout<<"\n";

	return;
}

void tests(){
	vector<vector<int>> adyacencyMatrix = {{1,0,1,1,1}, {1,1,0,1,1}, {0,1,0,0,0}, {0,0,0,1,0}, {0,0,0,0,0}};
	printMatrix(adyacencyMatrix);
	cout << "Output: " << numberOfIslands(adyacencyMatrix) << "\n";

	cout<<"\n\n";

	adyacencyMatrix = {{1,0,0}, {0,0,0}};
	printMatrix(adyacencyMatrix);
	cout << "Output: " << numberOfIslands(adyacencyMatrix) << "\n";

	return;
}

int main(){

	tests();

	return 0;
}