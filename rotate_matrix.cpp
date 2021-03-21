
// Program to rotate matrix clockwise by 90 degrees

#include <iostream>

using namespace std;


// Function to display 2d array
void display_matrix(int arr[5][5], const int n)
{
	cout << "\nMatrix is:" << endl;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}


// Function to display 2d array using pointers
void display_matrix2(int **arr, const int n)
{
	cout << "\nMatrix is:" << endl;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}


// Function to rotate matrix with extra space
void rotate_matrix_brute(int arr[5][5], const int n)
{
	int **arr2;
	int m = n;

	arr2 = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr2[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			arr2[i][j] = arr[n-j-1][i];
		}
	}
	display_matrix2(arr2, n);
}


// Function to rotate square matrix in-place
void rotate_matrix(int arr[5][5], const int n)
{
	int i = 0, j = 0;
	while (i < n / 2)
	{
		int temp;

		// Rotate the four vertices
		int k = j;
		// I = arr[i][j]
		// II = arr[i][m-j-1]
		// III = arr[n-i-1][m-j-1]
		// IV = arr[n-i-1][j]
		while (k < n - j - 1)
		{
			temp = arr[i + k][n - j - 1];
			arr[i + k][n - j - 1] = arr[i][j + k];
			arr[i][j + k] = temp;

			temp = arr[n - i - 1][n - j - 1 - k];
			arr[n - i - 1][n - j - 1 - k] = arr[i][j + k];
			arr[i][j + k] = temp;

			temp = arr[n - i - 1 - k][j];
			arr[n - i - 1 - k][j] = arr[i][j + k];
			arr[i][j + k] = temp;

			//std::cout << "\nK:" << k << endl;
			//display_matrix(arr, n);
			k++;
		}

		i++;
		j++;
	}
	display_matrix(arr, n);
}


// Main function
int main()
{
	int arr[5][5] = {
		{ 10,21,3,4,5 },
		{ 20,31,4,5,6 },
		{ 30,41,5,6,7 },
		{ 40,51,6,7,8 },
		{ 50,61,7,8,9 }
	};
	const int n = 5;

	display_matrix(arr, n);
	rotate_matrix_brute(arr, n);
	cin.get();
	return 0;
}