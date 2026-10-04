// Counting Sort O(n + m) m : counter vector size
#include <iostream>
#include <vector>
using namespace std;

int get_max(vector <int> A) { // Get the vector's largest element
	int m = -1; // Supposing all the elements are positives
	for (int i = 0; i < A.size(); i++) {
		if (m < A[i]) m = A[i];
	}
	return m;
}

void CountingSort(vector <int>& A) {
	int n = A.size();
	int m = get_max(A);
	
	vector <int> Count(m + 1, 0); // There are "m + 1" spaces with initial value 0
	
	for (int i = 0; i < n; i++)
		Count[A[i]]++; // Count how many times an element appears
	
	for (int i = 1; i <= m; i++)
		Count[i] += Count[i - 1]; // Turn the counting vector into a cumulative vector
		
	vector <int> Output(n); // Auxiliar vector with the sorted elements
	
	for (int i = n - 1; i >= 0; i--) {
		Output[Count[A[i]] - 1] = A[i]; // Get the final vector's index to set the sorted element
		Count[A[i]]--; // Decrease by one to avoid overwriting duplicated elements
	}
	
	for (int i = 0; i < n; i++)
		A[i] = Output[i]; // Send output's elements to the main vector
}

int main() {
	int n;
	cin >> n; // Amount of elements
	
	vector <int> Arr(n); // Vector with "n" elements
	
	for (int i = 0; i < n; i++)
		cin >> Arr[i]; // Assign every vector's element a value
		
	CountingSort(Arr);
	
	for (int i : Arr) cout << i << ' ';
	
	return 0;
}