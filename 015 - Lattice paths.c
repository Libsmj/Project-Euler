// 015 - Lattice paths
// @author Jacob Libsman

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	const int gridSize = 20;
	long long grid[gridSize + 1][gridSize + 1];

	for (int i = 0; i <= gridSize; i++) {
		grid[i][0] = 1;
		grid[0][i] = 1;
	}
	for (int i = 1; i <= gridSize; i++) {
		for (int j = 1; j <= gridSize; j++) {
			grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
		}
	}
	cout << "The number of routes that there are through a " << gridSize << "x" << gridSize << " grid is " << grid[gridSize][gridSize] << "\n";
}