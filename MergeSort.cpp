// Merge Sort O(nlogn)
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Merge(vector <int>& A, vector <int> Left, vector <int> Right) {
	int nL = Left.size(); // Get Left side's size
	int nR = Right.size(); // Get Right side's size
	
	int i = 0, j = 0, k = 0; // Indexes
	
	while (i < nL && j < nR) {
		if (Left[i] <= Right[j]) {
			A[k] = Left[i]; i++;
		} else {
			A[k] = Right[j]; j++;
		}
		k++;
	}
	
	while (i < nL) { // If there are remaining elements in the left side
		A[k] = Left[i];
		i++; k++;
	}
	
	while (j < nR) { // If there are remaining elements in the right side
		A[k] = Right[j];
		j++; k++;
	}
}

void MergeSort(vector <int>& A) { // Use pass by ref. to modify the vector
	int n = A.size();
	if (n < 2) return;
	int mid = round(n / 2);
	
	vector <int> Left(mid), Right(n - mid);
	
	for (int i = 0; i < mid; i++)
		Left[i] = A[i];
		
	for (int i = mid; i < n; i++)
		Right[i - mid] = A[i];
		
	MergeSort(Left); MergeSort(Right); // Divide both halves until having 1 element
	Merge(A, Left, Right);
}

int main() {
	int n;
	cin >> n; // Amount of elements
	
	vector <int> Arr(n); // Vector with "n" elements
	
	for (int i = 0; i < n; i++)
		cin >> Arr[i]; // Assign every vector's element a value
		
	MergeSort(Arr);
	
	for (int i : Arr) cout << i << ' ';
	
	return 0;
}