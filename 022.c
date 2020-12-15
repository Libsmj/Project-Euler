#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Using 022.txt, a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. 
	Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

	For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

	What is the total of all the name scores in the file?
*/

static int Compare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b); 
} 

void sort(char** arr, int n) { 
    qsort(arr, n, sizeof(const char*), Compare); 
} 

int main() {
	printf("Problem 22 - Names scores\n");
	FILE* file = fopen("022.txt", "r");
    
	// Read the whole file
	char* buffer = malloc(50000 * sizeof(char));
	int buff_size = 50000;
	fgets(buffer, buff_size, file);

	// Split into array of names
	char** names = calloc(6000, sizeof(char*));
	char *token;
	token = strtok(buffer, ",");
	int i = 0;
	while( token != NULL ) {
		names[i] = calloc(strlen(token)-1, sizeof(char));
		memcpy( names[i++], &token[1], strlen(token)-2 );
		token = strtok(NULL, ",");
	}
	int n = i;

	// Sort the array
	sort(names, n);

	// Add name scoes
	long long sum = 0;
	for (i = 0; i < n; i++) {
		int tempsum = 0;
		for (int j = 0; j < strlen(names[i]); j++) {
			tempsum += names[i][j] - 'A' + 1;
		}
		sum += tempsum * (i + 1);
		free(names[i]);
	}
	printf("%llu\n", sum);

	
	free(names);
	free(buffer);
	fclose(file);
	return 0;
}