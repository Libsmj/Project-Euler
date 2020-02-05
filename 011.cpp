// 011 - Largest product in a grid
// @author Jacob Libsman

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream inFile;
	inFile.open("011.txt");
	
	int nums[20][20];
	int x = 0;
	int y = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			nums[j][i] = i;
		}
	}
	while (y < 20) {
		inFile >> nums[x][y];
		if (x < 19) {
			x++;
		}
		else {
			x = 0;
			y++;
		}
	}
	inFile.close();
	int largestProduct = 1;
	int product = 1;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			product = 1;
			if (i < 16)
				for (int k = 0; k < 4; k++)
					product *= nums[i + k][j];
			if (product > largestProduct)
				largestProduct = product;
			product = 1;
			if (j < 16)
				for (int k = 0; k < 4; k++)
					product *= nums[i][j + k];
			if (product > largestProduct)
				largestProduct = product;
			product = 1;
			if (i < 16 && j < 16)
				for (int k = 0; k < 4; k++)
					product *= nums[i + k][j + k];
			if (product > largestProduct)
				largestProduct = product;
			product = 1;
			if (i > 2 && j > 2)
				for (int k = 0; k < 4; k++)
					product *= nums[i - k][j + k];
			if (product > largestProduct)
				largestProduct = product;
		}
	}

	// Prints grid
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (nums[j][i] < 10)
				cout << 0;
			cout << nums[j][i] << " ";
		}
		cout << "\n";
	}
	cout << "The greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20-20 grid is " << largestProduct << "\n";
	return 0;
}