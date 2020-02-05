// 015 - Lattice paths
// @author Jacob Libsman

#include <stdio.h>

int main() {
	int gridSize = 20;
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
	printf("The number of routes that there are through a %d x %d grid is %lld\n", gridSize, gridSize, grid[gridSize][gridSize]);
	return 0;
}