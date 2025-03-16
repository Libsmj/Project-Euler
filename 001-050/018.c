#include <stdio.h>
#include <stdlib.h>

/*
	Starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

	   3
	  7 4
	 2 4 6
	8 5 9 3

	That is, 3 + 7 + 4 + 9 = 23.

	Find the maximum total from top to bottom of the triangle [18.txt]

	NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. 
	However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
*/

// Dynammic programming
// The maximum path up to each element is calculated from top to bottom
int main(int argc, char** argv) {
	printf("Problem 18 - Maximum path sum I\n");
	int rows = 15;
	int p = 2;
	int i, j;
	int** max_path = calloc( rows, sizeof(int*) );
	int** nums = calloc( rows, sizeof(int*) );
	for (i = 0; i < rows; i++) {
		max_path[i] = calloc( i + 1, sizeof(int) );
		nums[i] = calloc( i + 1, sizeof(int) );
	}
	char* buff = calloc( p + 2,  sizeof(char) );
	FILE* fp = fopen("018.txt", "r");

	for (i = 0; i < rows; i++) {
		for (j = 0; j <= i; j++) {
			fgets(buff, p+2, fp);
			nums[i][j] = atoi(buff);
		}
		if (fgets(buff, p, fp) == NULL) {
			break;
		}
	}

	max_path[0][0] = nums[0][0];
	
	for (i = 1; i < rows; i++) {
		// Left most 
		max_path[i][0] = max_path[i - 1][0] + nums[i][0];
		for (j = 1; j < i; j++) {
			if (max_path[i - 1][j - 1] < max_path[i - 1][j]) {
				max_path[i][j] = max_path[i - 1][j];
			}
			else {
				max_path[i][j] = max_path[i - 1][j - 1];
			}
			max_path[i][j] += nums[i][j];
		}
		// Right most
		max_path[i][i] = max_path[i - 1][i - 1] + nums[i][i];
	}


	i--;
	int max = 0;
	for (j = 0; j < i + 1; j++) {
		if (max < max_path[i][j])
			max = max_path[i][j];
	}
	printf("%d\n", max);

	fclose(fp);
	free(buff);
	for (i = 0; i < rows; i++) {
		free(max_path[i]);
		free(nums[i]);
	}
	free(max_path);
	free(nums);
	return 0;
}
