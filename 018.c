#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*
Starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

   3
  7 4
 2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

#18.txt

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
*/


// Dynammic programming
// The maximum path up to each element is calculated from top to bottom
int main(int argc, char** argv) {
	printf("Problem 18 - Maximum path sum I\n");
	int rows, fd, rc;
	int i; int j;
	int** max_path;
	int** nums;
	char buff[4];

	if (argc > 1) {
		fd = open(argv[1], O_RDONLY);
	}
	else {
		fd = open("018.txt", O_RDONLY);
	}
	if (fd == -1) {
		perror("ERROR");
		return 1;
	}
	rc = read(fd, buff, 3);
	
	nums = calloc(1, sizeof(int*));
	rows = 0; i = 0;
	while (rc != 0) {
		if (i == rows) {
			nums = realloc(nums, ++rows * sizeof(int*));
			nums[rows - 1] = calloc(rows, sizeof(int));
			i = 0;
		}
		nums[rows - 1][i++] = atoi(buff);
		rc = read(fd, buff, 3);
	}
	
	close(fd);


	max_path = calloc(rows, sizeof(int*));
	for (i = 0; i < rows; i++) {
		max_path[i] = calloc(i + 1, sizeof(int));
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
#ifdef debug
		printf("%d\n", max_path[i][j]);
#endif
		if (max < max_path[i][j])
			max = max_path[i][j];
	}
	printf("%d\n", max);

	for (i = 0; i < rows; i++) {
		free(max_path[i]);
		free(nums[i]);
	}
	free(max_path);
	free(nums);
	return 0;
}
